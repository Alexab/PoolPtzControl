#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_SensorHXGetTempWetEx "SensorHXGetTempWet" 
class SensorHXGetTempWetEx : public JObject
{
public:
	JIntObj		Channel;
	JStrObj		Info;
	
public:
    SensorHXGetTempWetEx(JObject *pParent = NULL, const char *szName = JK_SensorHXGetTempWetEx):
    JObject(pParent,szName),
	Channel(this, "Channel"),
	Info(this, "Info"){
	};

    ~SensorHXGetTempWetEx(void){};
};

NS_NETSDK_CFG_END