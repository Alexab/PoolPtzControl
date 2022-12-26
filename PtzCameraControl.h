//
// Created by user on 26.12.22.
//

#ifndef PTZCONTROL_PTZCAMERACONTROL_H
#define PTZCONTROL_PTZCAMERACONTROL_H

#include <string>

#include "XNetSDK/include/XNetSDK.h"


class PtzCameraControl {

 public:
  PtzCameraControl(const std::string &address, int port, const std::string &username, const std::string &password);
  ~PtzCameraControl();
  bool connect();
  void disconnect();

  bool light_on();
  bool light_off();

  int callback(XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char* szString, void* pObject, int64 lParam, int nSeq, void* pMsg);

  XSDK_HANDLE get_device_handle() const;

 private: // Parameters
  std::string _address;
  int _port;
  std::string _username;
  std::string _password;

 private: // States
  XSDK_HANDLE _device_handle;
};


#endif //PTZCONTROL_PTZCAMERACONTROL_H
