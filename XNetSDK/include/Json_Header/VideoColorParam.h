#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_VideoColorParam "VideoColorParam" 
class VideoColorParam  : public JObject
{
public:
	JIntObj				Acutance;			///< 锐度   0-15		
	JIntObj				Brightness;			///< 亮度	0-100
	JIntObj				Contrast;			///< 对比度	0-100
	JIntObj				Gain;				///< 增益	0-100 第７位置1表示自动增益		
	JIntObj				Hue;				///< 色度	0-100
	JIntObj				Saturation;			///< 饱和度	0-100
	JIntObj				Whitebalance;		///< 自动白电平控制，bit7置位表示开启自动控制.0x0,0x1,0x2分别代表低,中,高等级
	
public:
	VideoColorParam (JObject *pParent = NULL, const char *szName = JK_VideoColorParam):
	JObject(pParent,szName),
	Acutance(this, "Acutance"),
	Brightness(this, "Brightness"),
	Contrast(this, "Contrast"),
	Gain(this, "Gain"),
	Hue(this, "Hue"),
	Saturation(this, "Saturation"),
	Whitebalance(this, "Whitebalance"){
	};

	~VideoColorParam (void){};
};

NS_NETSDK_CFG_END