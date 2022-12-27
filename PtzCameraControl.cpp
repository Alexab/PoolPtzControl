//
// Created by user on 26.12.22.
//

#include <cstring>
#include "PtzCameraControl.h"
#include "XNetSDK/include/Json_Header/SystemInfo.h"

PtzCameraControl::PtzCameraControl(const std::string &address, int port, const std::string &username, const std::string &password)
 : _address(address)
 , _port(port)
 , _username(username)
 , _password(password)
 , _device_handle(0)
 , _num_channels(0)
{
}

PtzCameraControl::~PtzCameraControl()
{
  disconnect();
}

bool PtzCameraControl::connect()
{
  XSDK_HANDLE device_handle;
  SXSDKLoginParam pParam;
  pParam.nCnnType = EDEV_CNN_TYPE_AUTO; // EDEV_CNN_TYPE_IP_DNS; // EDEV_CNN_TYPE_SDK;
  strcpy(pParam.sDevId, _address.c_str());
  pParam.nDevPort = _port;
  strcpy(pParam.sUserName, _username.c_str());
  strcpy(pParam.sPassword, _password.c_str());

  _device_handle = XSDK_DevLoginSyn(&pParam, 5000);
  if(_device_handle<=0)
    return false;

  int nChannelNum = 0;

  if (_device_handle > 0)
  {
    char szOutBuffer[40960] = { 0 };
    int  nInOutSize = sizeof(szOutBuffer);
    int nResult = XSDK_DevGetSysConfigSyn(_device_handle, JK_SystemInfo, szOutBuffer, &nInOutSize, 4000, JK_SystemInfo_MsgId);

    if (nResult >= 0)
    {
      XSDK_CFG::SystemInfo cfg;
      cfg.Parse(szOutBuffer);

      nChannelNum = cfg.DigChannel.Value() + cfg.VideoInChannel.Value();
    }
  }

  _num_channels = nChannelNum;

  return false;
}

void PtzCameraControl::disconnect()
{
  if (_device_handle>0)
    XSDK_DevLogout(_device_handle);
  _device_handle = 0;
  _num_channels = 0;
}

bool PtzCameraControl::light_on()
{
  int res = XSDK_DevPtzControl(_device_handle, 0, S_XPTZ_DirectionUp, 1, true);
  return res >= 0;
}

bool PtzCameraControl::light_off()
{
  int res = XSDK_DevPtzControl(_device_handle, 0, S_XPTZ_DirectionDown, 1, true);
  return res >= 0;
}

int PtzCameraControl::callback(XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char* szString, void* pObject, int64 lParam, int nSeq, void* pMsg)
{
 return 1;
}

XSDK_HANDLE PtzCameraControl::get_device_handle() const
{
  return _device_handle;
}

int PtzCameraControl::get_num_channels() const
{
  return _num_channels;
}