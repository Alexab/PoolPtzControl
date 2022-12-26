#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPFileQueryByTime "OPFileQuery" 

class OPFileQueryByTime : public JObject
{
public:
	JStrObj		BeginTime;
	JStrObj		EndTime;
	JStrObj		SubType;
	JIntObj		HighChannel;
	JStrObj		HighStreamType;
	JIntObj		LowChannel;
	JStrObj		LowStreamType;
	JIntObj		Sync;
	JStrObj		Type;

public:
	OPFileQueryByTime(JObject *pParent = NULL, const char *szName = JK_OPFileQueryByTime):
	JObject(pParent,szName),
	BeginTime(this, "BeginTime"),
	EndTime(this, "EndTime"),
	SubType(this, "Event"),
	HighChannel(this, "HighChannel"),
	HighStreamType(this, "HighStreamType"),
	LowChannel(this, "LowChannel"),
	LowStreamType(this, "LowStreamType"),
	Sync(this, "Sync"),
	Type(this, "Type")
	{
		this->Parse("{ \"Name\" : \"OPFileQuery\", \"OPFileQuery\" : { \"BeginTime\" : \"2020-03-30 00:00:00\", \"EndTime\" : \"2020-03-30 14:52:23\", \"Event\" : \"*\", \"HighChannel\" : 0, \"HighStreamType\" : \"0x00105CC8\", \"LowChannel\" : 1, \"LowStreamType\" : \"0x00000000\", \"Sync\" : 0, \"Type\" : \"h264\" }, \"SessionID\" : \"0x14ff5\" }");
	};

	~OPFileQueryByTime(void){};
};

NS_NETSDK_CFG_END