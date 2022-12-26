#include <iostream>
#include <cstring>
#include <boost/program_options.hpp>

#include "XNetSDK/include/XNetSDK.h"
#include "PtzCameraControl.h"

int CALLBACK Main_MessageCallBack(XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char* szString, void* pObject, int64 lParam, int nSeq, void* pUserData, void* pMsg)
{
  PtzCameraControl* p_this = (PtzCameraControl*)pUserData;
  if(p_this)
    return p_this->callback(hDevice, nMsgId, nParam1, nParam2, nParam3, szString, pObject, lParam, nSeq, pMsg);

  /*
  CClientDemoDlg* pThis = (CClientDemoDlg*)pUserData;

  switch(nMsgId)
  {
    case ESXSDK_ON_DAS_DEVICE_REGIST:
    {
      pThis->OnDASDeviceReg(hDevice, (SXSDKDASDeviceInfo*)pObject);
    }
      break;
    case ESXSDK_ON_DEV_STATE:
    {
      ::PostMessage(pThis->m_hWnd, WM_DEVICE_STATE, nParam1, hDevice);
    }
      break;
    default:
      break;
  }
*/
  std::cout << "Callback called!" << std::endl;
  return 1;
}

int main(int argc, char* argv[]) {
  boost::program_options::options_description desc("Allowed options");
  desc.add_options()(
    "address,a",
    boost::program_options::value< std::string >()->default_value(""),
    "Camera address"
  )(
    "port,p",
    boost::program_options::value< int >()->default_value(80),
    "Camera port"
  )(
    "username,U",
    boost::program_options::value< std::string >()->default_value("root"),
    "User name"
  )(
    "password,P",
    boost::program_options::value< std::string >()->default_value("root"),
    "User password"
  );

  boost::program_options::variables_map settings;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), settings);
  boost::program_options::notify(settings);

  if(settings["address"].as<std::string>().empty()) {
    std::cerr << desc << std::endl;
    return 1;
  }
  SXSDK_Version pVersionInfo;

  XSDK_GetXNetSDKVersion(&pVersionInfo);
  std::cout << "XNetSDK Version " << pVersionInfo.sVersion << " [" << pVersionInfo.sCompileTime << "]" << std::endl;

  SXSDKInitParam initParam = { 0 };
  initParam.mainMsgCallBack.pMsgCallback = Main_MessageCallBack;
  initParam.mainMsgCallBack.pUserData = nullptr;
  //CString strAppPath = GET_MODULE_FILE_INFO.strPath;
  //StrSafeCopy(initParam.szConfigPath, strAppPath.GetBuffer(0), 256);
  int init_result = XSDK_Init(&initParam);
  std::cout << "SDK init status: " << init_result << std::endl;

//  PtzCameraControl cam("http://10.10.10.10", 80, "root", "root");
  PtzCameraControl cam(settings["address"].as<std::string>(), settings["port"].as<int>(), settings["username"].as<std::string>(), settings["password"].as<std::string>());

  cam.connect();
  XSDK_HANDLE device_handle = cam.get_device_handle();
  std::cout << "Device Handle: " << int(device_handle) << std::endl;

  return 0;
}
