#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_EncodeFunction "EncodeFunction" 
class EncodeFunction : public JObject
{
public:
	JBoolObj		DoubleStream;			///< 双码流功能
	JBoolObj		CombineStream;			///< 组合编码
	JBoolObj		SnapStream;				///< 抓图编码
	JBoolObj		WaterMark;				///< 水印功能------功能废弃(2016.1.16)
	JBoolObj		IFrameRange;			///< I帧间隔
	JBoolObj		LowBitRate;				///< 低码流，家用产品使用
	JBoolObj		SmartH264;				///< H264+
	JBoolObj		IntelligentEncode;		///< 智能编码
	JBoolObj		SmartH264Plus;			///< H264++
	JBoolObj		SmartH264V2;			//新的H264+/H264++
	JBoolObj		CustomChnDAMode;		///< 自定义数模切换功能
	JBoolObj		SmartEncodeDigital;		///Smart编码数字通道
	JBoolObj		MultiChannel;			///多通道编码

public:
    EncodeFunction(JObject *pParent = NULL, const char *szName = JK_EncodeFunction):
    JObject(pParent,szName),
	DoubleStream(this, "DoubleStream"),
	CombineStream(this, "CombineStream"),
	SnapStream(this, "SnapStream"),
	WaterMark(this, "WaterMark"),
	IFrameRange(this, "IFrameRange"),
	LowBitRate(this, "LowBitRate"),
	SmartH264(this, "SmartH264"),
	IntelligentEncode(this, "IntelligentEncode"),
	SmartH264Plus(this, "SmartH264Plus"),
	SmartH264V2(this, "SmartH264V2"),
	CustomChnDAMode(this, "CustomChnDAMode"),
	SmartEncodeDigital(this, "SmartEncodeDigital"),
	MultiChannel(this, "MultiChannel"){
	};

    ~EncodeFunction(void){};
};

NS_NETSDK_CFG_END