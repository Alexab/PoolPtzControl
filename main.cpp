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
    boost::program_options::value< std::string >()->default_value("admin"),
    "User name"
  )(
    "password,P",
    boost::program_options::value< std::string >()->default_value(""),
    "User password"
  )(
    "light,L",
    boost::program_options::value< int >()->default_value(2),
    "Light on (1) or off (0)"
  )(
    "ir_mode,I",
    boost::program_options::value< int >()->default_value(0),
    "Switch auto/manual mode for IR light (1 - process switch)"
  )(
    "white_mode,W",
    boost::program_options::value< int >()->default_value(0),
    "Switch auto/manual mode for white light (1 - process switch)"
  )(
    "save,S",
    boost::program_options::value< int >()->default_value(0),
    "Save light settings (1 - process save)"
  )(
    "restore,R",
    boost::program_options::value< int >()->default_value(0),
    "Restore default light settings (1 - process restore)"
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

  bool is_connected = cam.connect(std::chrono::milliseconds (5000));
  std::cout << "Connection " << (is_connected?"successful":"failed") << std::endl;
  if(!is_connected)
    return 2;
  XSDK_HANDLE device_handle = cam.get_device_handle();
  int num_channels = cam.get_num_channels();
  std::cout << "Device Handle: " << int(device_handle) << ". NumChannels: " <<num_channels << std::endl;
  if(device_handle > 0 && num_channels > 0)
  {
    int light_mode = settings["light"].as<int>();
    if(light_mode == 1)
    {
      std::cout << "Light increment...";
      bool res = cam.light_inc();
      std::cout << (res?"success":"fail") << std::endl;
    }
    else
    if(light_mode == 0)
    {
      std::cout << "Light decrement...";
      bool res = cam.light_dec();
      std::cout << (res?"success":"fail") << std::endl;
    }

    int ir_mode = settings["ir_mode"].as<int>();
    if(ir_mode == 1)
    {
      std::cout << "Switching IR light mode (auto/manual)...";
      bool res = cam.ir_switch_mode();
      std::cout << (res?"success":"fail") << std::endl;
    }

    int white_mode = settings["white_mode"].as<int>();
    if(white_mode == 1)
    {
      std::cout << "Switching white light mode (auto/manual)...";
      bool res = cam.white_switch_mode();
      std::cout << (res?"success":"fail") << std::endl;
    }

    int save = settings["save"].as<int>();
    if(save == 1)
    {
      std::cout << "Save light settings...";
      bool res = cam.save_light_settings();
      std::cout << (res?"success":"fail") << std::endl;
    }

    int restore = settings["restore"].as<int>();
    if(restore == 1)
    {
      std::cout << "Restore default light settings...";
      bool res = cam.restore_light_settings();
      std::cout << (res?"success":"fail") << std::endl;
    }
  }

  return 0;
}
