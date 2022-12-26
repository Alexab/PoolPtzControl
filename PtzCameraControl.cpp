//
// Created by user on 26.12.22.
//

#include <cstring>
#include "PtzCameraControl.h"

PtzCameraControl::PtzCameraControl(const std::string &address, int port, const std::string &username, const std::string &password)
 : _address(address)
 , _port(port)
 , _username(username)
 , _password(password)
 , _device_handle(0)
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

  _device_handle = XSDK_DevLogin(&pParam, 1000, 0);
  if(_device_handle>0)
    return true;

  return false;
}

void PtzCameraControl::disconnect()
{
  if (_device_handle>0)
    XSDK_DevLogout(_device_handle);
  _device_handle = 0;
}

bool PtzCameraControl::light_on()
{

}

bool PtzCameraControl::light_off()
{

}

int PtzCameraControl::callback(XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char* szString, void* pObject, int64 lParam, int nSeq, void* pMsg)
{
 return 1;
}

XSDK_HANDLE PtzCameraControl::get_device_handle() const
{
  return _device_handle;
}