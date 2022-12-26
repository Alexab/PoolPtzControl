#pragma once
#include "JObject_NetSDK.h"

NS_NETSDK_CFG_BEGIN

#define JK_Decoder "Decoder" 
class Decoder : public JObject
{
public:
	JIntObj		Channel;
	JStrObj		ConfName;
	JStrObj		DevType;
	JBoolObj	Enable;
	JStrObj		IPAddress;
	JIntObj		Interval;
	JStrObj		MainRtspUrl;
	JStrObj		PassWord;
	JIntObj		Port;
	JStrObj		Protocol;
	JStrObj		StreamType;
	JStrObj		SubRtspUrl;
	JStrObj		UserName;
	
public:
	Decoder(JObject *pParent = NULL, const char *szName = JK_Decoder):
	JObject(pParent,szName),
	Channel(this, "Channel"),
	ConfName(this, "ConfName"),
	DevType(this, "DevType"),
	Enable(this, "Enable"),
	IPAddress(this, "IPAddress"),
	Interval(this, "Interval"),
	MainRtspUrl(this, "MainRtspUrl"),
	PassWord(this, "PassWord"),
	Port(this, "Port"),
	Protocol(this, "Protocol"),
	StreamType(this, "StreamType"),
	SubRtspUrl(this, "SubRtspUrl"),
	UserName(this, "UserName"){
	};

	~Decoder(void){};
};

NS_NETSDK_CFG_END