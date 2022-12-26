#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_SystemInfo "SystemInfo"
#define JK_SystemInfo_MsgId 1020
class SystemInfo : public JObject 
{
public:
	JIntObj		AlarmInChannel;				//报警输入通道数
	JIntObj		AlarmOutChannel;			//报警输出通道数
	JIntObj		AudioInChannel;				//音频输入通道数
	JStrObj		BuildTime;					//软件创建时间
	JIntObj		CombineSwitch;				//组合编码通道分割模式是否支持切换
	JIntHex		DeviceRunTime;				//系统运行时间
	JIntObj		DigChannel;					//数字通道数
	JStrObj		EncryptVersion;				//加密版本信息
	JIntObj		ExtraChannel;				//扩展通道数
	JStrObj		HardWare;					//设备型号
	JStrObj		HardWareVersion;			//硬件版本信息
	JStrObj		SerialNo;					//设备序列号
	JStrObj		SoftWareVersion;			//固件版本信息
	JIntObj		TalkInChannel;				//对讲输入通道数
	JIntObj		TalkOutChannel;				//对讲输出通道数
	JStrObj		UpdataTime;					//更新时间
	JIntHex		UpdataType;					//更新内容
	JIntObj		VideoInChannel;				//视频输入通道数
	JIntObj		VideoOutChannel;			//视频输出通道数

public:
	SystemInfo(JObject *pParent = NULL, const char *szName = JK_SystemInfo):
	JObject(pParent,szName),
	AlarmInChannel(this, "AlarmInChannel"),
	AlarmOutChannel(this, "AlarmOutChannel"),
	AudioInChannel(this, "AudioInChannel"),
	BuildTime(this, "BuildTime"),
	CombineSwitch(this, "CombineSwitch"),
	DeviceRunTime(this, "DeviceRunTime"),
	DigChannel(this, "DigChannel"),
	EncryptVersion(this, "EncryptVersion"),
	ExtraChannel(this, "ExtraChannel"),
	HardWare(this, "HardWare"),
	HardWareVersion(this, "HardWareVersion"),
	SerialNo(this, "SerialNo"),
	SoftWareVersion(this, "SoftWareVersion"),
	TalkInChannel(this, "TalkInChannel"),
	TalkOutChannel(this, "TalkOutChannel"),
	UpdataTime(this, "UpdataTime"),
	UpdataType(this, "UpdataType"),
	VideoInChannel(this, "VideoInChannel"),
	VideoOutChannel(this, "VideoOutChannel"){
		this->Parse("{ \"Name\" : \"SystemInfo\", \"Ret\" : 100, \"SessionID\" : \"0x2c\", \"SystemInfo\" : { \"AlarmInChannel\" : 2," "\"AlarmOutChannel\" : 1, \"AudioInChannel\" : 1, \"BuildTime\" : \"2017-04-12 19:13:16\", \"CombineSwitch\" : 0," "\"DeviceRunTime\" : \"0x00001D66\", \"DigChannel\" : 0, \"EncryptVersion\" : \"Unknown\", \"ExtraChannel\" : 0, \"HardWare\" :" "\"HI3518E_53H13_S39\", \"HardWareVersion\" : \"Unknown\", \"SerialNo\" : \"558aa5ddab9c31cb\", \"SoftWareVersion\" :" "\"V4.02.R12.D4806531.10002.142100.00000\", \"TalkInChannel\" : 1, \"TalkOutChannel\" : 1, \"UpdataTime\" : \"\", \"UpdataType\" :" "\"0x00000000\", \"VideoInChannel\" : 1, \"VideoOutChannel\" : 1, \"DeviceType\" : 0 } }");
	};

	~SystemInfo(void){};
};

NS_NETSDK_CFG_END