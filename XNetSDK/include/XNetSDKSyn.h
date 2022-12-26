#pragma once
#ifndef _XNetSDKSyn_H_
#define _XNetSDKSyn_H_
#include "XNetSDK.h"
/*************************************************************************************
*同步接口定义
***************************************************************************************/

#ifdef __cplusplus             
extern "C" {
#endif
	/**
	 * @brief 登录设备（同步）
	 * @param pParam 登录设备的信息
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。接口直接返回结果，不需要回调函数判断。
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_DevLoginSyn(SXSDKLoginParam* pParam, int nTimeout);

	/**
	 * @brief 获取系统配置（同步）
	 * @param hDevice 登录句柄
	 * @param szCommandName 配置命令字
	 * @param pOutBuffer 接收设备返回的配置的Json数据
	 * @param pInOutBufferSize 返回的数据长度
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败。接口直接返回结果，不需要回调函数判断。
	 */
	XSDK_API int CALLBACK XSDK_DevGetSysConfigSyn(XSDK_HANDLE hDevice, const char* szCommandName, char* pOutBuffer, int* pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_GET);

	/**
	 * @brief 获取通道配置（同步）
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szCommandName 配置命令字
	 * @param pOutBuffer 接收设备返回的配置的Json数据
	 * @param pInOutBufferSize 返回的数据长度
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败。接口直接返回结果，不需要回调函数判断。
	*/
	XSDK_API int CALLBACK XSDK_DevGetChnConfigSyn(XSDK_HANDLE hDevice, int nChannel, const char* szCommandName, char* pOutBuffer, int* pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_GET);

	/**
	 * @brief 设备系统配置设置（同步）
	 * @param hDevice 登录句柄
	 * @param szCommandName 配置命令字
	 * @param pConfig 设置的配置的Json数据
	 * @param nConfigLen 设置的数据长度
	 * @param pOutBuffer 接收设备返回的结果Json数据
	 * @param pInOutBufferSize 接收设备返回的结果Json数据长度
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败。接口直接返回结果，不需要回调函数判断。
	*/
	XSDK_API int CALLBACK XSDK_DevSetSysConfigSyn(XSDK_HANDLE hDevice, const char* szCommandName, const char* pConfig, int nConfigLen, char* pOutBuffer, int* pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

	/**
	 * @brief 设备通道配置设置（同步）
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szCommandName 配置命令字
	 * @param pConfig 设置的配置的Json数据
	 * @param nConfigLen 设置的数据长度
	 * @param pOutBuffer 接收设备返回的结果Json数据
	 * @param pInOutBufferSize 接收设备返回的结果Json数据长度
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败。接口直接返回结果，不需要回调函数判断。
	*/
	XSDK_API int CALLBACK XSDK_DevSetChnConfigSyn(XSDK_HANDLE hDevice, int nChannel, const char* szCommandName, const char* pConfig, int nConfigLen, char* pOutBuffer, int* pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

	/**
	 * @brief 设备局域网搜索
	 * @param pRet 搜索返回的设备结果
	 * @param nMaxCount 最大搜索个数
	 * @return 返回搜索到的实际设备个数
	*/
	XSDK_API int CALLBACK XSDK_SearchDevicesSyn(SXSDK_CONFIG_NET_COMMON* pRet, int nMaxCount);

	/**
	 * @brief 设备端抓图（同步）
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szPicType 图片类型。暂时没有使用
	 * @param pOutBuffer 返回的图片数据。一般为JPG格式
	 * @param pInOutBufferSize 返回的数据长度
	 * @return >=0成功，<0失败。接口直接返回结果，不需要回调函数判断。
	*/
	XSDK_API int CALLBACK XSDK_DevSnapSyn(XSDK_HANDLE hDevice, int nChannel, const char* szPicType, unsigned char* pOutBuffer, int* pInOutBufferSize);

	/**
	 * @brief 查找录像文件（同步）
	 * @param hDevice 登录句柄
	 * @param pParam 查找条件
	 * @param pFiles 返回的文件结果
	 * @param nMaxCount 最大查找个数
	 * @param nTimeout 超时时间
	 * @return 返回查找到的文件个数
	*/
	XSDK_API int CALLBACK XSDK_DevFindFileSyn(XSDK_HANDLE hDevice, SXSDKQueryRecordReq* pParam, SXSDKQueryRecordRes* pFiles, int nMaxCount, int nTimeout);

	/**
	 * @brief 按时间查找录像文件对应每分钟（同步）
	 * @param hDevice 登录句柄
	 * @param pParam 查找条件
	 * @param pFiles 返回查找的结果
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败。接口直接返回结果，不需要回调函数判断。
	*/
	XSDK_API int CALLBACK XSDK_DevFindFileByTimeSyn(XSDK_HANDLE hDevice, SXSDKSearchByTimeReq* pParam, SXSDKSearchByTimeRes* pFiles, int nTimeout);

	/**
	 * @brief 查询录像日历（同步）
	 * @param hDevice 登录句柄
	 * @param pParam 查找条件
	 * @param pCalendarInfo 返回查找的结果
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败。接口直接返回结果，不需要回调函数判断。
	*/
	XSDK_API int CALLBACK XSDK_SearchCalendarSyn(XSDK_HANDLE hDevice, SXSDKSearchCalendarReq* pParam, SXSDKSearchCalendarRes* pCalendarInfo, int nTimeout);

#ifdef __cplusplus
}
#endif

#endif //_XNetSDKSyn_H_
