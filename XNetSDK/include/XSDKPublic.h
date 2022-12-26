#pragma once
#ifndef XSDKPUBLIC_H
#define XSDKPUBLIC_H

#include "XBaseTypes.h"

#ifdef __cplusplus             
extern "C" {
#endif

#ifdef OS_WINDOWS
#ifdef XSDK_EXPORTS
#define XSDK_API extern "C" __declspec(dllexport)
#define CALLBACK __stdcall
#elif defined(XSDKAPI_STATIC) 
#define XSDK_API 
#define CALLBACK __stdcall
#else
#define XSDK_API extern "C" __declspec(dllimport)
#define CALLBACK __stdcall
#endif
#else
#define XSDK_API
#define CALLBACK
#endif

	/////////////////////SDK结果回调方式/////////////////////
	typedef struct MsgContent
	{
		void* pMsg;            // 内部使用
		XSDK_HANDLE sender;
		int id;
		int param1;
		int param2;
		int param3;
		const char* szStr;
		char* pObject;
		int nDataLen;
		uint64 lParam;
		int seq;
		void* pUserData;
	}MsgContent;

	typedef int (CALLBACK* PXSDK_MessageCallBack) (XSDK_HANDLE hObject, int nMsgId, int nParam1, int nParam2, int nParam3, const char* szString, void* pObject, int64 lParam, int nSeq, void* pUserData, void* pMsg);
	typedef struct SMsgReceiver
	{		
		/**
		 * @brief 消息方式输出结果。适用系统：Windows窗口消息、IOS或Android
		*/
		UI_HANDLE hWindow;

		/**
		 * @brief 回调函数的方式输出结果
		*/
		PXSDK_MessageCallBack pMsgCallback;

		/**
		 * @brief 用户自定义数据，对应回调函数中的pUserData
		*/
		void* pUserData;

		SMsgReceiver(UI_HANDLE hWindow = NULL, PXSDK_MessageCallBack pMsgCallback = NULL, void* pUserData = NULL)
		{
			this->hWindow = hWindow;
			this->pMsgCallback = pMsgCallback;
			this->pUserData = pUserData;
		}

		/**
		 * @brief 回调函数赋值
		 * @param pMsgCallback 回调函数
		 * @return 本身
		*/
		SMsgReceiver& operator=(PXSDK_MessageCallBack pMsgCallback)
		{
			this->pMsgCallback = pMsgCallback;
			return *this;
		}

		/**
		 * @brief 消息窗口赋值
		 * @param hWindow 消息窗口句柄
		 * @return 本身
		*/
		SMsgReceiver& operator=(UI_HANDLE hWindow)
		{
			this->hWindow = hWindow;
			return *this;
		}
	}SMsgReceiver;

	//typedef void (CALLBACK* PXSDK_DrawCallBack)(XSDK_HANDLE hObject, HDC hDc, void* pUserData);

	typedef struct SXPLSDKVersion
	{
		char sVersion[64];			//SDK版本号
		char sCompileTime[64];  	//SDK编译版本日期
	}SXSDKVersion;

	///////////////SDK初始化参数///////////////////////////////////////////
	typedef struct SXSDKInitParam
	{
		int nLogLevel;			// 日志等级
		char szTempPath[256];	// 临时文件目录
		char szConfigPath[256];	// 配置文件目录

		///////////////SDK使用鉴权///////////////////////////////////////////
		/// UUID与APPKey等获取与使用注意事项：
		/// 1)通过开发者网站注册开发者帐户后自助创建
		//  2)应妥善保管相关信息，切勿泄漏，若被滥用，平台有权停止SDK使用授权
		char szPlatUUID[64];		// 平台客户唯一标志码
		char szPlatAppKey[128];		// 平台应用Key
		char szPlatAppSecret[128];	// 平台应用密钥
		int nPlatMovedCard;			// 平台移动取模基数
		////////////////////////////////////////////////////////////////////

		SMsgReceiver mainMsgCallBack;
	}SXSDKInitParam;

	/**
	 * @brief 初始化SDK
	 * @param pParam 初始化相关信息
	 * @return >=0成功，<0失败
	 * 备注：程序开始前调用 ，只能被调用一次
	*/
	XSDK_API int CALLBACK XSDK_Init(SXSDKInitParam* pParam);

	/**
	 * @brief 反初始化
	 * @return 无
	 * 备注：程序退出前调用 ，只能被调用一次
	*/
	XSDK_API void CALLBACK XSDK_UnInit();
	
	/**
	 * @brief 获取SDK版本信息
	 * @param pSDKVersionInfo 返回版本信息结果
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_GetSDKVersion(SXSDKVersion* pSDKVersionInfo);
	
	/**
	 * @brief 设置程序为前台模式（对应后台模式）
	 * @param nActive 0：后台；1：前台(激活)
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_SetActive(int nActive);
	
	/**
	 * @brief 获取配置APP是否在后台运行等状态
	 * @return 0：后台；1：前台
	*/
	XSDK_API int CALLBACK XSDK_GetActive();

	///////////////////当前程序属性配置(支持Int,String,Array三种方式)///////////////////
	XSDK_API int CALLBACK XSDK_SetSDKIntAttr(int nAttrKey, int nValue);
	XSDK_API int CALLBACK XSDK_GetSDKIntAttr(int nAttrKey, int nDefaultValue);

	XSDK_API int CALLBACK XSDK_SetSDKStrAttr(int nAttrKey, const char* szValue);
	XSDK_API const char* CALLBACK XSDK_GetSDKStrAttr(int nAttrKey, char* pResult, int nMaxSize);

	XSDK_API void* XSDK_GetSDKAttr(int nId, void* pDefValue);
	XSDK_API int XSDK_SetSDKAttr(int nId, void* pAttr);

	XSDK_API int CALLBACK XSDK_GetSDKArrayAttr(int nId, void* pBuffer, int nBufferSize);
	XSDK_API int CALLBACK XSDK_SetSDKArrayAttr(int nId, const void* pArray, int nArraySize);

	///////////////////当前对像属性配置(支持Int,String,Array三种方式)//////////////////////////////////////
	XSDK_API int CALLBACK XSDK_SetObjIntAttr(XSDK_HANDLE hObject, int nAttrKey, int nValue);
	XSDK_API int CALLBACK XSDK_GetObjIntAttr(XSDK_HANDLE hObject, int nAttrKey, int nDefaultValue);

	XSDK_API int CALLBACK XSDK_SetObjStrAttr(XSDK_HANDLE hObject, int nAttrKey, const char* szValue);
	XSDK_API const char* CALLBACK XSDK_GetObjStrAttr(XSDK_HANDLE hObject, int nAttrKey, char* pResult, int nMaxSize);

	XSDK_API void* XSDK_GetObjAttr(XSDK_HANDLE hObject, int nId, void* pDefValue);
	XSDK_API int XSDK_SetObjAttr(XSDK_HANDLE hObject, int nId, void* pAttr);

	XSDK_API int CALLBACK XSDK_GetObjArrayAttr(XSDK_HANDLE hObject, int nId, void* pBuffer, int nBufferSize);
	XSDK_API int CALLBACK XSDK_SetObjArrayAttr(XSDK_HANDLE hObject, int nId, const void* pArray, int nArraySize);

	/**
	 * @brief 错误码对应的字符解释
	 * @param nError 错误码值
	 * @return 返回错误码字符串信息
	*/
	XSDK_API const char* CALLBACK XSDK_StrError(const int nError);

	///////////////////消息Add&Ref///////////////////
	XSDK_API int CALLBACK XSDK_MsgAddRef(void* pMsg);
	XSDK_API void CALLBACK XSDK_MsgRelase(void* pMsg);
	
	/**
	 * @brief 字符格式转化
	 * @param szFromCode 源格式，gbk,gb28181,utf-8
	 * @param szToCode 目标格式
	 * @param pText 源字符串
	 * @param szResult 转化结果
	 * @param nMaxSize 最大字符创长度
	 * @return 结果字符指针
	*/
	XSDK_API const char* CALLBACK XSDK_StrIConv(const char* szFromCode, const char* szToCode, const char* pText, char* szResult, int nMaxSize);

	XSDK_API int CALLBACK XSDK_ExeProgress(const char* pProgressName);

	/**
	 * @brief 获取执行程序的路径和名称
	 * @param szOutAppPath 程序的路径
	 * @param szAppName 程序的名称
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_GetAppPath(char szOutAppPath[260], char szAppName[64]);

#ifdef OS_IOS
	/**
	 * @brief IOS注册窗口回调函数
	 * @param pWnd 窗口对像
	 * @param name 函数名
	 * @return 注册窗口ID(唯一)
	*/
	XSDK_API UI_HANDLE CALLBACK XSDK_RegWnd(LP_WND_OBJ pWnd, const char* name = "OnFunSDKResult:");
	
	/**
	 * @brief IOS注销窗口回调函数
	 * @param hWnd 窗口对像
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_UnRegWnd(UI_HANDLE hWnd);
#endif
#ifdef __cplusplus             
}
#endif

#endif // defined XSDKPUBLIC_H
