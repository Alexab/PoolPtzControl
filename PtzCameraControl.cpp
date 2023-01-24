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

bool PtzCameraControl::connect(std::chrono::milliseconds timeout)
{
  XSDK_HANDLE device_handle;
  SXSDKLoginParam pParam;
  pParam.nCnnType = EDEV_CNN_TYPE_AUTO; // EDEV_CNN_TYPE_IP_DNS; // EDEV_CNN_TYPE_SDK;
  strcpy(pParam.sDevId, _address.c_str());
  pParam.nDevPort = _port;
  strcpy(pParam.sUserName, _username.c_str());
  strcpy(pParam.sPassword, _password.c_str());

  _device_handle = XSDK_DevLoginSyn(&pParam, timeout.count());
  if(_device_handle<=0) {
    std::cout << "XSDK_DevLoginSyn failed. Device handle=" <<  _device_handle <<std::endl;
    return false;
  }
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
    else {
      std::cout << "XSDK_DevGetSysConfigSyn failed: nResult=" <<  nResult << std::endl;
      return false;
    }
  }
  else
    return false;

  _num_channels = nChannelNum;

  return true;
}

void PtzCameraControl::disconnect()
{
  if (_device_handle>0)
    XSDK_DevLogout(_device_handle);
  _device_handle = 0;
  _num_channels = 0;
}

bool PtzCameraControl::light_inc()
{
  //int res = XSDK_DevPtzControl(_device_handle, 0, S_XPTZ_DirectionUp, 1, true);
  int res = XSDK_DevPtzPreset(_device_handle, 0, S_XPTZ_GotoPreset, 242);
  return res >= 0;
}

bool PtzCameraControl::light_dec()
{
//  int res = XSDK_DevPtzControl(_device_handle, 0, S_XPTZ_DirectionDown, 1, true);
  int res = XSDK_DevPtzPreset(_device_handle, 0, S_XPTZ_GotoPreset, 243);
  return res >= 0;
}

bool PtzCameraControl::ir_switch_mode()
{
  int res = XSDK_DevPtzPreset(_device_handle, 0, S_XPTZ_GotoPreset, 244);
  return res >= 0;
}

bool PtzCameraControl::white_switch_mode()
{
  int res = XSDK_DevPtzPreset(_device_handle, 0, S_XPTZ_GotoPreset, 245);
  return res >= 0;
}

bool PtzCameraControl::save_light_settings()
{
  int res = XSDK_DevPtzPreset(_device_handle, 0, S_XPTZ_GotoPreset, 250);
  return res >= 0;
}

bool PtzCameraControl::restore_light_settings()
{
  int res = XSDK_DevPtzPreset(_device_handle, 0, S_XPTZ_GotoPreset, 251);
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