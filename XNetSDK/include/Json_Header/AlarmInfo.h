#pragma once
#include "JObject_NetSDK.h"

NS_NETSDK_CFG_BEGIN

#define JK_AlarmInfo "AlarmInfo" 
class AlarmInfo : public JObject
{
public:
	JIntObj		Channel;
	JStrObj		Event;
	JStrObj		StartTime;
	JStrObj		Status;
	JStrObj		ExtInfo;

public:
	AlarmInfo(JObject *pParent = NULL, const char *szName = JK_AlarmInfo):
	JObject(pParent,szName),
	Channel(this, "Channel"),
	Event(this, "Event"),
	StartTime(this, "StartTime"),
	Status(this, "Status"),
	ExtInfo(this, "ExtInfo"){
	};

	~AlarmInfo(void){};
};

NS_NETSDK_CFG_END