//
// Created by user on 26.12.22.
//

#ifndef PTZCONTROL_PTZCAMERACONTROL_H
#define PTZCONTROL_PTZCAMERACONTROL_H

#include <string>
#include <chrono>

#include "XNetSDK/include/XNetSDK.h"
#include "XNetSDK/include/XNetSDKSyn.h"

#define JK_SystemInfo "SystemInfo"
#define JK_SystemInfo_MsgId 1020

/////////////云台基本控制///////////
#define S_XPTZ_DirectionLeftUp	"DirectionLeftUp"
#define S_XPTZ_DirectionUp		"DirectionUp"
#define S_XPTZ_DirectionRightUp "DirectionRightUp"
#define S_XPTZ_DirectionLeft	"DirectionLeft"
#define S_XPTZ_DirectionRight	"DirectionRight"
#define S_XPTZ_DirectionLeftDown "DirectionLeftDown"
#define S_XPTZ_DirectionDown	"DirectionDown"
#define S_XPTZ_DirectionRightDown "DirectionRightDown"
#define S_XPTZ_IrisSmall	"IrisSmall"
#define S_XPTZ_IrisLarge	"IrisLarge"
#define S_XPTZ_FocusNear	"FocusNear"
#define S_XPTZ_FocusFar		"FocusFar"
#define S_XPTZ_ZoomWide		"ZoomWide"
#define S_XPTZ_ZoomTile		"ZoomTile"
////////////预置点操作///////////
#define S_XPTZ_GotoPreset	"GotoPreset"
#define S_XPTZ_SetPreset	"SetPreset"
#define S_XPTZ_ClearPreset	"ClearPreset"
///////////串口类型/////////////
#define S_XTRANS_COMM_RS232	"RS232"
#define S_XTRANS_COMM_RS485	"RS485"


class PtzCameraControl {

 public:
  PtzCameraControl(const std::string &address, int port, const std::string &username, const std::string &password);
  ~PtzCameraControl();
  bool connect(std::chrono::milliseconds timeout);
  void disconnect();

  bool light_on();
  bool light_off();

  int callback(XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char* szString, void* pObject, int64 lParam, int nSeq, void* pMsg);

  XSDK_HANDLE get_device_handle() const;
  int get_num_channels() const;

 private: // Parameters
  std::string _address;
  int _port;
  std::string _username;
  std::string _password;

 private: // States
  XSDK_HANDLE _device_handle;
  int _num_channels;
};


#endif //PTZCONTROL_PTZCAMERACONTROL_H
