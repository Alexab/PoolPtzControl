#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_Video "Video" 
class Video : public JObject
{
public:
	JIntObj		BitRate;				/// 0-4096k,该列表主要由客户端保存，设备只接收实际的码流值而不是下标。
	JStrObj		BitRateControl;			///码流控制
	JStrObj		Compression;			///压缩模式(视频格式)
	JIntObj		FPS;					///帧率值
	JIntObj		GOP;					///描述两个I帧之间的间隔时间，2-12 
	JIntObj		Quality;				///码流的画质 档次1-6	
	JStrObj		Resolution;				///分辨率

public:
	Video(JObject *pParent = NULL, const char *szName = JK_Video):
	JObject(pParent,szName),
	BitRate(this, "BitRate"),
	BitRateControl(this, "BitRateControl"),
	Compression(this, "Compression"),
	FPS(this, "FPS"),
	GOP(this, "GOP"),
	Quality(this, "Quality"),
	Resolution(this, "Resolution"){
	};

	~Video(void){};
};

NS_NETSDK_CFG_END