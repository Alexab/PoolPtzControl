#include <iostream>
#include <cstring>

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

int main() {

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

  PtzCameraControl cam("http://10.10.10.10", 80, "root", "root");

  cam.connect();
  XSDK_HANDLE device_handle = cam.get_device_handle();
  std::cout << "Device Handle: " << int(device_handle) << std::endl;

  return 0;
}
