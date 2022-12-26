#pragma once
#ifndef _XNetSDK_H_
#define _XNetSDK_H_
#include "XSDKPublic.h"
#include "XNetSDKDefine.h"

#ifdef __cplusplus             
extern "C" {
#endif
	/**
	 * @brief 获取SDK版本号和编译时间
	 * @param pVersionInfo 版本信息
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_GetXNetSDKVersion(SXSDK_Version* pVersionInfo);

	/**
	 * @brief 登录设备（异步）
	 * @param pParam 登录设备的信息
	 * @param nTimeout 超时时间
	 * @param nSeq 用户自定义值
	 * @return >0成功，<=0失败
	 * 备注：该接口通过回调函数获取登录结果及连接成功后的登录句柄
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_DevLogin(SXSDKLoginParam* pParam, int nTimeout, int nSeq);

	/**
	 * @brief 登出设备
	 * @param hDevice 登录句柄
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_DevLogout(XSDK_HANDLE hDevice);

	/**
	 * @brief 获取系统配置（异步）
	 * @param hDevice 登录句柄
	 * @param szCommandName 配置命令字
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败
	 * 备注：通过回调函数判断
	*/
	XSDK_API int CALLBACK XSDK_DevGetSysConfig(XSDK_HANDLE hDevice, const char* szCommandName, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_GET);

	/**
	 * @brief 获取通道配置（异步）
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szCommandName 配置命令字
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败
	 * 备注：通过回调函数判断
	*/
	XSDK_API int CALLBACK XSDK_DevGetChnConfig(XSDK_HANDLE hDevice, int nChannel, const char* szCommandName, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_GET);
	
	/**
	 * @brief 设置系统配置
	 * @param hDevice 登录句柄
	 * @param szCommandName 配置命令字
	 * @param pConfig 需要设置的配置的Json内容
	 * @param nConfigLen 传入的Json内容长度
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败
	 * 备注：通过回调函数判断
	*/
	XSDK_API int CALLBACK XSDK_DevSetSysConfig(XSDK_HANDLE hDevice, const char* szCommandName, const char* pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

	/**
	 * @brief 设置通道配置
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szCommandName 配置命令字
	 * @param pConfig 需要设置的配置的Json内容
	 * @param nConfigLen 传入的Json内容长度
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @return >=0成功，<0失败
	 * 备注：通过回调函数判断
	*/
	XSDK_API int CALLBACK XSDK_DevSetChnConfig(XSDK_HANDLE hDevice, int nChannel, const char* szCommandName, const char* pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

	/**
	 * @brief 发送数据
	 * @param hDevice 登录句柄
	 * @param szCommandName 配置命令字
	 * @param pConfig 需要发送的Json内容
	 * @param nConfigLen 传入的Json内容长度
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @param nMsgId 自定义消息ID值
	 * @return >=0成功，<0失败
	 * 备注：通过回调函数判断
	*/
	XSDK_API int CALLBACK XSDK_DevSendData(XSDK_HANDLE hDevice, const char* szCommandName, const char* pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand, int nMsgId = ESXSDK_DEV_GENERAL_COMMAND);
	
	/**
	 * @brief 发送数据拓展
	 * @param hDevice 登录句柄
	 * @param szCommandName 配置命令字
	 * @param pConfig 需要发送的Json内容
	 * @param nConfigLen 传入的Json内容长度
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @param nCommand 消息ID值
	 * @param nMsgId 自定义消息ID值
	 * @param nChannelOrTotalPacket 保留参数
	 * @param nEndFlagOrCurPacket 保留参数
	 * @param nReserved1 保留参数
	 * @param nReserved2 保留参数
	 * @return >=0成功，<0失败
	 * 备注：通过回调函数判断
	*/
	XSDK_API int CALLBACK XSDK_DevSendDataEx(XSDK_HANDLE hDevice, const char* szCommandName, const char* pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand, int nMsgId = ESXSDK_DEV_GENERAL_COMMAND, unsigned char nChannelOrTotalPacket = 0, unsigned char nEndFlagOrCurPacket = 0, unsigned char nReserved1 = 0, unsigned char nReserved2 = 0);

	/**
	 * @brief 开启或关闭设备报警回调
	 * @param hDevice 登录句柄
	 * @param bListener 0：关闭；1：开启
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_DevSetAlarmListener(XSDK_HANDLE hDevice, int bListener);

	/**
	 * @brief 搜索设备
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	 * 备注：回调函数获取搜索到的设备信息
	*/
	XSDK_API int CALLBACK XSDK_SearchDevices(int nTimeout);

	/**
	 * @brief 云台控制
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szPTZCommand 云台控制命令
	 * @param nStep 步长
	 * @param bStop 是否5停止
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_DevPtzControl(XSDK_HANDLE hDevice, int nChannel, const char* szPTZCommand, int nStep, bool bStop);

	/**
	 * @brief 预置点操作
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szPTZCommand 云台控制命令
	 * @param nPreset 预置点值
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_DevPtzPreset(XSDK_HANDLE hDevice, int nChannel, const char* szPTZCommand, int nPreset);

	/**
	 * @brief 设置巡航点
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param nPresetPoint 预置点值
	 * @param nStep 步长
	 * @param nTourIndex 巡航点值
	 * @param bAdd 是否添加
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_SetPtzTourPoint(XSDK_HANDLE hDevice, int nChannel, int nPresetPoint, int nStep, int nTourIndex, bool bAdd);

	/**
	 * @brief 开始巡航
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param nTourIndex 巡航点值
	 * @param bStart 是否开始
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_DevPtzTour(XSDK_HANDLE hDevice, int nChannel, int nTourIndex, bool bStart);

	/**
	 * @brief 删除巡航点
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param nTourIndex 巡航点值
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_DeleteDevPtzTour(XSDK_HANDLE hDevice, int nChannel, int nTourIndex);

	/**
	 * @brief 查找录像文件
	 * @param hDevice 登录句柄
	 * @param pParam 查询条件
	 * @param nTimeout 超时时间
	 * @param nSeq 用户自定义值
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回查询结果，且函数一次最多返回64条（）
	*/
	XSDK_API int CALLBACK XSDK_DevFindFile(XSDK_HANDLE hDevice, SXSDKQueryRecordReq* pParam, int nTimeout, int nSeq);

	/**
	 * @brief 设置设备系统时间
	 * @param hDevice 登录句柄
	 * @param szTime 时间格式：2018-07-25 17:20:37; == NULL或""时，默认为当前系统时间
	 * @param nSeq 用户自定义值
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
 	*/
	XSDK_API int CALLBACK XSDK_DevSynTime(XSDK_HANDLE hDevice, const char* szTime = "", int nSeq = 0);

	/**
	 * @brief 设备通道抓图
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param szPicType 图片类型，暂时不用
	 * @param nSeq 用户自定义值
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
	*/
	XSDK_API int CALLBACK XSDK_DevSnap(XSDK_HANDLE hDevice, int nChannel, const char* szPicType, int nSeq = 0);

	/**
	 * @brief 强制I帧
	 * @param hDevice 登录句柄
	 * @param nChannel 设备通道号（从0开始）
	 * @param nStreamType 码流类型(0主码流,1子码流)
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
	*/
	XSDK_API int CALLBACK XSDK_MakeKeyFrame(XSDK_HANDLE hDevice, int nChannel, int nStreamType);

	/**
	 * @brief 实时预览
	 * @param hDevice 登录句柄
	 * @param pParam 预览请求条件
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。对应预览句柄
	 * 备注：通过回调函数获取结果。需要与XSDK_MediaStop配对使用
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRealPlay(XSDK_HANDLE hDevice, SXMediaRealPlayReq* pParam, int nSeq = 0, int nTimeout = 0);

	/**
	 * @brief 按时间录像回放
	 * @param hDevice 登录句柄
	 * @param pParam 回放请求条件
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。对应回放句柄
	 * 备注：通过回调函数获取结果。需要与XSDK_MediaStop配对使用
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordPlay(XSDK_HANDLE hDevice, SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);

	/**
	 * @brief 按文件名称回放
	 * @param hDevice 登录句柄
	 * @param pParam 回放请求条件
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。对应回放句柄
	 * 备注：通过回调函数获取结果
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordPlayByName(XSDK_HANDLE hDevice, SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);

	/**
	 * @brief 按时间下载
	 * @param hDevice 登录句柄
	 * @param pParam 下载请求条件
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。对应下载句柄
	 * 备注：通过回调函数获取结果 
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordDownload(XSDK_HANDLE hDevice, SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);

	/**
	 * @brief 按文件名称下载
	 * @param hDevice 登录句柄
	 * @param pParam 下载请求条件
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。对应下载句柄
	 * 备注：通过回调函数获取结果 
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordDownloadByName(XSDK_HANDLE hDevice, SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);
	
	/**
	 * @brief 获取播放句柄
	 * @param hDataSource XSDK_MediaRecordPlay 或 XSDK_MediaRecordPlay 或 XSDK_MediaRecordPlayByName返回值
	 * @return >0成功，<=0失败。对应播放句柄
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_GetPlayHandle(XSDK_HANDLE hDataSource);

	/**
	 * @brief 录像回放/下载控制->暂停/继续
	 * @param hMedia 媒体句柄
	 * @param bPause 是否暂停
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_MediaPause(XSDK_HANDLE hMedia, bool bPause);

	/**
	 * @brief 录像回放跳转
	 * @param hMedia 媒体句柄
	 * @param szTime 跳转时间。格式：YYYY-MM-DD HH:mm:SS
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_MediaSeekToTime(XSDK_HANDLE hMedia, const char* szTime);

	/**
	 * @brief 回放速度控制
	 * @param hMedia 媒体句柄
	 * @param nSpeed -1~-4:慢放1~4档; 1~4：快放1~4档;0:恢复
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_MediaSetSpeed(XSDK_HANDLE hMedia, int nSpeed);

	/**
	 * @brief 人脸识别图片回调
	 * @param hDevice 登录句柄
	 * @param pParam 人脸请求信息
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。对应人脸句柄
	 * 备注：通过回调函数获取结果  
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaGetFaceImage(XSDK_HANDLE hDevice, SXMediaFaceImageReq* pParam, int nSeq = 0, int nTimeout = 0);

	/**
	 * @brief 实时预览/录像回放/下载--停止
	 * @param nMediaId 媒体句柄
	 * @return >=0成功，<0失败
	*/
	XSDK_API void CALLBACK XSDK_MediaStop(XSDK_HANDLE nMediaId);

	/**
	 * @brief 对密码进行MD5加密，适用于用户密码修改
	 * @param inputPswBuf 输入密码数据
	 * @param outputPswBuf 输出密码数据
	 * @param PswSize 输入密码数据长度
	 * @return >0成功，<=0失败
	 * 备注：加密密码长度最大512
	*/
	XSDK_API int CALLBACK XSDK_EncryptPassword(const char* inputPswBuf, signed char* outputPswBuf, int PswSize);

	/**
	 * @brief 跨网段修改设备IP
	 * @param lpInputbuffer 需要发送的配置SXSDK_CONFIG_NET_COMMON_V2
	 * @param buffersize 数据长度
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_ModifyDevIP(const char* lpInputbuffer, int buffersize, int nTimeout);
	
	/**
	 * @brief 修改设备密码
	 * @param hDevice 登录句柄
	 * @param pUserName 用户名
	 * @param pOldPwd 原密码
	 * @param pNewPwd 新密码
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_ModifyDevicePassword(XSDK_HANDLE hDevice, const char* pUserName, const char* pOldPwd, const char* pNewPwd, int nSeq, int nTimeout);

	/**
	 * @brief 升级设备固件
	 * @param hDevice 登录句柄
	 * @param szFileName 固件名
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回升级进度
	*/
	XSDK_API int CALLBACK XSDK_DevUpgrade(XSDK_HANDLE hDevice, const char* szFileName, int nSeq, int nTimeout);

	/**
	 * @brief 开启设备主动注册服务
	 * @param szServerIP 服务器IP
	 * @param nServerPort 监听端口
	 * @return 此服务操作句柄，可用来关闭服务
	 * 备注：如果端口被占用，SDK内部会不断重试，直到成功
	 * 有设备连接成功后，回调函数返回登录句柄
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_StartDASServer(const char* szServerIP, int nServerPort);

	/**
	 * @brief 关闭设备主动注册服务
	 * @param hServer 主动注册服务句柄
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_StopDASServer(XSDK_HANDLE hServer);

	/**
	 * @brief 获取主动注册连接的设备句柄
	 * @param szDeviceId DAS配置设置的ID值
	 * @return 连接的设备句柄
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_GetDASDevHandle(const char* szDeviceId);

	/**
	 * @brief 打开对讲功能
	 * @param hDevice 登录句柄
	 * @param pParam 对讲请求信息
	 * @return >0成功，<=0失败。对应对讲句柄
	 * 备注：通过回调函数获取结果  
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_StartTalk(XSDK_HANDLE hDevice, SXMediaTalkReq* pParam);

	/**
	 * @brief 发送对讲数据
	 * @param hMedia 对讲句柄
	 * @param pBuffer 发送的音频数据
	 * @param nBufLen 音频数据长度
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
	*/
	XSDK_API int CALLBACK XSDK_SendTalkData(XSDK_HANDLE hMedia, const char* pBuffer, int nBufLen);

	/**
	 * @brief 打开透明串口
	 * @param hDevice 登录句柄
	 * @param szComType 串口类型
	 * @return >0成功，<=0失败。对应串口句柄
	 * 备注：通过回调函数获取结果
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_OpenTransCom(XSDK_HANDLE hDevice, const char* szComType);

	/**
	 * @brief 关闭透明串口
	 * @param hTranport 串口句柄
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_CloseTransCom(XSDK_HANDLE hTranport);

	/**
	 * @brief 向串口写数据
	 * @param hDevice 登录句柄
	 * @param nSerialType 0:RS232;1:RS485
	 * @param pBuffer 串口数据
	 * @param nBufLen 数据长度
	 * @param nSeq 用户自定义值
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
	*/
	XSDK_API int CALLBACK XSDK_TransComWrite(XSDK_HANDLE hDevice, int nSerialType, const char* pBuffer, int nBufLen, int nSeq);

	/**
	 * @brief 获取重置密码相关信息
	 * @param nDevPort 设备端口
	 * @param sDevId 设备IP
	 * @param szCommandName 配置命令字 
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
	*/
	XSDK_API int CALLBACK XSDK_GetResetPswInfo(int nDevPort, const char* sDevId, const char* szCommandName, int nSeq, int nTimeout);

	/**
	 * @brief 设置重置密码相关信息
	 * @param nDevPort 设备端口
	 * @param sDevId 设备IP
	 * @param szCommandName 配置命令字
	 * @param pConfig 设置的数据信息
	 * @param nConfigLen 数据长度
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
	*/
	XSDK_API int CALLBACK XSDK_SetResetPswInfo(int nDevPort, const char* sDevId, const char* szCommandName, const char* pConfig, int nConfigLen, int nSeq, int nTimeout);

	/**
	 * @brief 发送文件数据到设备上（目前主要用于发送自定义报警语音文件）
	 * @param hDevice 登录句柄
	 * @param fileName 文件名
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_SendFileToDev(XSDK_HANDLE hDevice, const char* fileName, int nSeq, int nTimeout);

	/**
	 * @brief 对讲NVR所连接的IPC前端
	 * @param hDevice 登录句柄
	 * @param nChannel 通道号
	 * @param pParam 对讲请求信息
	 * @return >0成功，<=0失败。对应对讲句柄
	 * 备注：通过回调函数获取结果
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_Talk_NVRCrossIPC(XSDK_HANDLE hDevice, int nChannel, SXMediaTalkReq* pParam);

	/**
	 * @brief 云升级设备固件
	 * @param hDevice 登录句柄
	 * @param pParam 升级请求信息
	 * @return >=0成功，<0失败
	 * @return >0成功，<=0失败。对应云升级句柄
	 * 备注：通过回调函数获取结果
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_Upgrade_Cloud(XSDK_HANDLE hDevice, SXCloudUpgradeVersion* pParam);

	/**
	 * @brief 停止云升级
	 * @param hDevUpgrade 云升级句柄
	 * @return 无
	*/
	XSDK_API void CALLBACK XSDK_Stop_Upgrade_Cloud(XSDK_HANDLE hDevUpgrade);
	
	/**
	 * @brief 异步获取指定序列号设备的服务状态（DSS等服务状态，不是本地登录状态）
	 *        异步回调消息ID：ESXSDK_DEV_ON_GET_STATE
	 *        调用后，该SN自动加入服务状态的监听队列，变更时会通过消息ESXSDK_DEV_UPDATE_DEVSTATUS通知
	 *		  XSDK_CancelDevServerStatusListen函数取消监听设备服务状态
	 * @param sDeviceSn 设备序列号，多个设备以";"分隔开
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >=0成功，<0失败
	 * 备注：回调函数返回结果。暂时不支持
	*/
	XSDK_API int CALLBACK XSDK_GetDevServerStatus(const char* sDeviceSn, int nSeq = 0, int nTimeout = 10);
	
	/**
	 * @brief 取消监听设备服务状态
	 * @param sDeviceSn 设备序列号，多个设备以";"分隔开
	 * @return 无
	 * 备注：暂时不支持
	*/
	XSDK_API void CALLBACK XSDK_CancelDevServerStatusListen(const char* sDeviceSn);

	/**
	 * @brief 从设备上导出文件
	 * @param hDevice 登录句柄
	 * @param sFileName 文件名
	 * @param nFileSize 文件长度
	 * @param nSeq 用户自定义值
	 * @param nTimeout 超时时间
	 * @return >0成功，<=0失败。对应导出操作句柄
	 * 备注：通过回调函数获取结果 
	*/
	XSDK_API XSDK_HANDLE CALLBACK XSDK_ExportFileFromDev(XSDK_HANDLE hDevice, const char* sFileName, int nFileSize, int nSeq, int nTimeout);
	
	/**
	 * @brief 判断系统能力集是否支持
	 * @param hDevice 登录句柄
	 * @param sJson 需要判断的Json字符串,格式例如"SystemFunction/OtherFunction/SupportWriteLog"
	 * @param bDefEnable 默认是否支持
	 * @return 返回true表示支持，返回false表示不支持
	*/
	XSDK_API bool CALLBACK XSDK_IsSysFunctionSupport(XSDK_HANDLE hDevice, const char* sJson, bool bDefEnable = false);
	
	/**
	 * @brief 硬盘控制管理
	 * @param hDevice 登录句柄
	 * @param pStorageControl 控制操作
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_StorageManage(XSDK_HANDLE hDevice, XSDK_StorageDeviceControl* pStorageControl);
	
	/**
	 * @brief 获取字体点阵
	 * @param szSourceData 源字符串（UTF8格式）
	 * @param dstInfo 点阵信息结果返回
	 * @return >=0成功，<0失败
	*/
	XSDK_API int CALLBACK XSDK_GetFontLatticeInfo(const char* szSourceData, XSDK_LatticeInfo* dstInfo);

	/**
	 * @brief 设置通道名称点阵信息
	 * @param hDevice 登录句柄
	 * @param nFontWidth 字体宽
	 * @param nFontHeight 字体高
	 * @param pTitleLattice 字体高
	 * @param nTitleLatticeLen 通道名称数据长度
	 * @return >=0成功，<0失败
	 * 备注：点阵数据最大支持24*24格式
	*/
	XSDK_API int XSDK_DevSetTitleByLattice(XSDK_HANDLE hDevice, short nFontWidth, short nFontHeight, const unsigned char* pTitleLattice, int nTitleLatticeLen);

#ifdef __cplusplus
}
#endif

#endif //_XNetSDK_H_
