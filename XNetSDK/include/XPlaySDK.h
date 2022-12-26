#pragma once
#ifndef _XPLAYSDK_H_
#define _XPLAYSDK_H_

#include "XPlayDefPub.h"
#include "XSDKPublic.h"

#ifdef __cplusplus             
extern "C" {
#endif

#ifdef OS_WINDOWS
#ifdef XPLAYSDK_EXPORTS
#define XPLAY_API extern "C" __declspec(dllexport)
#define CALLBACK __stdcall
#elif defined(XPLAYSDK_STATIC)
#define XPLAY_API
#define CALLBACK
#else
#define XPLAY_API extern "C" __declspec(dllimport)
#define CALLBACK __stdcall
#endif
#else
#define XPLAY_API
#define CALLBACK
#endif

	// 版本兼容
#define XPLAY_Init XSDK_Init
#define XPLAY_UnInit XSDK_UnInit
	
	/**
	 * @brief 获取播放SDK版本信息
	 * @param pSDKVersionInfo 版本相关信息
	 * @return 无
	*/
	XPLAY_API void CALLBACK XPLAY_GetXPlaySDKVersion(SXPLSDKVersion* pSDKVersionInfo);
	
	/**
	 * @brief 初始化x-access-token(帐户登录返回值)，用于SDK鉴权
	 * @param szServerIP 平台服务器
	 * @param nServerPort Port
	 * @param pXAccessToken 帐户登录返回值
	 * @return >0成功，<=0失败
	*/
	XPLAY_API int CALLBACK XPLAY_SetXAccessToken(const char* szServerIP, int nServerPort, const char* pXAccessToken);

	/**
	 * @brief 视频文件播放
	 * @param user 接收者
	 * @param szFileName 文件名
	 * @param hWnd 窗口句柄
	 * @param nDecodeType 解码结果类型
	 * @param pParam 扩展参数
	 * @return >0播放句柄，<=0失败
	*/
	XPLAY_API XPLAY_HANDLE CALLBACK XPLAY_OpenFilePlay(SMsgReceiver user, const char* szFileName, LP_WND_OBJ hWnd, int nDecodeType = 0, void* pParam = NULL);
	
	/**
	 * @brief 视频流播放
	 * @param user 接收者
	 * @param hWnd 窗口句柄
	 * @param nStreamType 数据流类型
	 * @param nDecodeType 解码结果类型
	 * @param pParam 扩展参数
	 * @return >0播放句柄，<=0失败
	*/
	XPLAY_API XPLAY_HANDLE CALLBACK XPLAY_OpenPlay(SMsgReceiver user, LP_WND_OBJ hWnd, EDECODE_TYPE nStreamType = EDECODE_REAL_TIME_DEFALUT, int nDecodeType = 0, void* pParam = NULL);

	/**
	 * @brief 媒体流播放
	 * @param user 接收者
	 * @param szUrl 媒体URL
	 * @param pUrlExInfo Url拓展参数（例如平台infoEx中的信息)
	 * @param hWnd 窗口句柄
	 * @param bFileStream 是否是文件流
	 * @param pParam 扩展参数
	 * @return >0播放句柄，<=0失败
	*/
	XPLAY_API XPLAY_HANDLE CALLBACK XPLAY_OpenByURL(SMsgReceiver user, const char* szUrl, const char* pUrlExInfo, LP_WND_OBJ hWnd, bool bFileStream, void* pParam = NULL);

	/**
	 * @brief 输入码流数据
	 * @param hPlayer 播放句柄
	 * @param pBuf 码流数据
	 * @param nSize 数据大小
	 * @return >0成功，<=0失败
	 * 备注：配合接口XPLAY_OpenPlay使用
	*/
	XPLAY_API int CALLBACK XPLAY_InputData(XPLAY_HANDLE hPlayer, unsigned char* pBuf, int nSize);
	
	/**
	 * @brief 媒体流URL下载
	 * @param user 接收者
	 * @param szUrl 媒体URL
	 * @param pUrlExInfo Url拓展参数（例如平台infoEx中的信息)
	 * @param szFileName 保存的文件名
	 * @return >0下载句柄，<=0失败
	*/
	XPLAY_API XPLAY_HANDLE CALLBACK XPLAY_DownloadByURL(SMsgReceiver user, const char* szUrl, const char* pUrlExInfo, const char* szFileName);
	
	/**
	 * @brief 开始播放/下载视频
	 * @param hPlayer 播放句柄
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_Play(XPLAY_HANDLE hPlayer);
	
	/**
	 * @brief 停止播放/下载
	 * @param hPlayer 播放句柄
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_Stop(XPLAY_HANDLE hPlayer);
	
	/**
	 * @brief 暂停播放
	 * @param hPlayer 播放句柄
	 * @param bPause 是否暂停
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_Pause(XPLAY_HANDLE hPlayer, bool bPause);

	/**
	 * @brief 播放速度控制
	 * @param hPlayer 播放句柄
	 * @param nSpeed 慢放1~4档:-1~-4;快放1~4档:1~4
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_SetPlaySpeed(XPLAY_HANDLE hPlayer, int nSpeed);
	
	/**
	 * @brief 播放句柄
	 * @param hPlayer 
	 * @return >=0成功，<0失败
	 * 备注：暂不支持该接口
	*/
	XPLAY_API int CALLBACK XPLAY_PlayNextFrame(XPLAY_HANDLE hPlayer);

	/**
	 * @brief 播放前一帧
	 * @param hPlayer 播放句柄
	 * @return >=0成功，<0失败
	 * 备注：暂不支持该接口
	*/
	XPLAY_API int CALLBACK XPLAY_PlayPreviousFrame(XPLAY_HANDLE hPlayer);

	/**
	 * @brief 设置当前播放位置
	 * @param hPlayer 播放句柄
	 * @param nPos 播放位置(0-100)
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_SetPlayPosition(XPLAY_HANDLE hPlayer, int nPos);
	
	/**
	 * @brief 打开音频
	 * @param hPlayer 播放句柄
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_PlaySound(XPLAY_HANDLE hPlayer);

	/**
	 * @brief 关闭音频
	 * @param hPlayer 播放句柄
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_StopSound(XPLAY_HANDLE hPlayer);
	
	/**
	 * @brief 设置音量
	 * @param hPlayer 播放句柄
	 * @param nVolume 音量
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_SetVolume(XPLAY_HANDLE hPlayer, int nVolume);
	
	/**
	 * @brief 抓图（异步）
	 * @param hPlayer 播放句柄
	 * @param szFileName 文件名
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_CatchPicture(XPLAY_HANDLE hPlayer, const char* szFileName);
	
	/**
	 * @brief 抓图（同步）
	 * @param hPlayer 播放句柄
	 * @param szFileName 文件名
	 * @param nTimeout 超时时间
	 * @return 接口直接返回错误码，>=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_CatchPictureSyn(XPLAY_HANDLE hPlayer, const char* szFileName, int nTimeout);
	
	/**
	 * @brief 抓取图片数据
	 * @param hPlayer 播放句柄
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_CatchPictureBuffer(XPLAY_HANDLE hPlayer);

	/**
	 * @brief 设置视频画面
	 * @param hPlayer 播放句柄
	 * @param nBrightness 亮度, 默认64
	 * @param nContrast 对比度, 默认64
	 * @param nSaturation 饱和度, 默认64
	 * @param nHue 色调, 默认64
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_SetColor(XPLAY_HANDLE hPlayer, int nBrightness, int nContrast, int nSaturation, int nHue);
	
	/**
	 * @brief 本地视频录像
	 * @param hPlayer 播放句柄
	 * @param szFileName 文件名
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_StartRecordData(XPLAY_HANDLE hPlayer, const char* szFileName);

	/**
	 * @brief 停止录像
	 * @param hPlayer 播放句柄
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_StopRecordData(XPLAY_HANDLE hPlayer);
	
	/**
	 * @brief 设置视频流畅度
	 * @param hPlayer 播放句柄
	 * @param nLevel 等级0-6
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_AdjustFluency(XPLAY_HANDLE hPlayer, int nLevel);
	
	/**
	 * @brief 只播放I帧
	 * @param hPlayer 播放句柄
	 * @param bPlayOnlyIFrame 是否只播I帧
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_PlayOnlyPlayIFrame(XPLAY_HANDLE hPlayer, bool bPlayOnlyIFrame);

	/**
	 * @brief 设置局部区域
	 * @param hPlayer 播放句柄
	 * @param pSrcRect 区域坐标;如果传NULL，则恢复画面
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_PlaySetDisplayRegion(XPLAY_HANDLE hPlayer, XPlayRECT* pSrcRect);
	
	/**
	 * @brief OSD叠加
	 * @param hPlayer 播放句柄
	 * @param pProc 回调函数
	 * @param pUserData 用户指针
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_SetDrawOSD(XPLAY_HANDLE hPlayer, PXSDK_DrawCallBack pProc, void* pUserData);

	/**
	 * @brief 录制音频
	 * @param user 接收者
	 * @param nBitsPerSample 采样位深度
	 * @param nSamplesPerSec 采样率
	 * @param nLength 音频数据包长度
	 * @return >0音频采集句柄，<=0失败
	*/
	XPLAY_API XPLAY_HANDLE CALLBACK XPLAY_StartCaptureAudio(SMsgReceiver user, int nBitsPerSample, int nSamplesPerSec, int nLength);
	
	/**
	 * @brief 停止音频录制
	 * @param hAudioPlayer 音频采集句柄
	 * @return >=0成功，<0失败
	*/
	XPLAY_API int CALLBACK XPLAY_StopCaptureAudio(XPLAY_HANDLE hAudioPlayer);
	
	/**
	 * @brief 转换文件格式
	 * @param user 接收者
	 * @param szSourceFileName 源文件
	 * @param szDestFileName 转换后的文件
	 * @param nType 文件类型FileFormatType
	 * @return >=0成功，<0失败
	 * 备注：暂不支持该接口
	*/
	XPLAY_API int CALLBACK XPLAY_PlayConvertFile(SMsgReceiver user, const char* szSourceFileName, const char* szDestFileName, int nType);

#ifdef __cplusplus
}
#endif

#endif //_XPlaySDK_H_
