#pragma once
#include "JObject_NetSDK.h"
#include "ExposureParam.h"
#include "GainParam.h"
NS_NETSDK_CFG_BEGIN

#define JK_Camera_Param "Camera.Param" 
class Camera_Param: public JObject  //获取曝光时间、情景模式、电子慢快门、色彩模式
{
public:
	JIntObj		AeSensitivity;		/// ae灵敏度配置
	JIntHex		ApertureMode;		/// 自动光圈模式
	JIntHex		BLCMode;			/// 背光补偿模式
	JIntHex		DayNightColor;		/// 日夜模式，取值有彩色、自动切换和黑白
	JIntObj		Day_nfLevel;		/// noise filter 等级，0-5,0不滤波，1-5 值越大滤波效果越明显
	JIntObj		DncThr;				/// 日夜转换阈值
	JIntObj		ElecLevel;			/// 参考电平值
	JIntHex		EsShutter;			/// 电子慢快门功能
	ExposureParam mExposureParam;	/// 曝光配置
	GainParam	mGainParam;			/// 增益配置
	JIntObj		IRCUTMode;			/// IR-CUT切换 0 = 红外灯同步切换 1 = 自动切换
	JIntObj		IrcutSwap;			/// ircut 正常序= 0        反序= 1
	JIntObj		Night_nfLevel;		/// 
	JIntHex		PictureFlip;		/// 图片上下翻转
	JIntHex		PictureMirror;		/// 图片左右翻转(镜像)
	JIntHex		RejectFlicker;		/// 日光灯防闪功能
	JIntHex		WhiteBalance;		/// 白平衡

public:
	Camera_Param(JObject *pParent = NULL, const char *szName = JK_Camera_Param):
	JObject(pParent,szName),
	AeSensitivity(this, "AeSensitivity"),
	ApertureMode(this, "ApertureMode"),
	BLCMode(this, "BLCMode"),
	DayNightColor(this, "DayNightColor"),
	Day_nfLevel(this, "Day_nfLevel"),
	DncThr(this, "DncThr"),
	ElecLevel(this, "ElecLevel"),
	EsShutter(this, "EsShutter"),
	mExposureParam(this, "ExposureParam"),
	mGainParam(this, "GainParam"),
	IRCUTMode(this, "IRCUTMode"),
	IrcutSwap(this, "IrcutSwap"),
	Night_nfLevel(this, "Night_nfLevel"),
	PictureFlip(this, "PictureFlip"),
	PictureMirror(this, "PictureMirror"),
	RejectFlicker(this, "RejectFlicker"),
	WhiteBalance(this, "WhiteBalance"){
	};

	~Camera_Param(void){};
};

NS_NETSDK_CFG_END