#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_SensorHXGetLightLuxEx "SensorHXGetLightLux" 
class SensorHXGetLightLuxEx : public JObject
{
public:
	JIntObj		Channel;
	JStrObj		Info;
	
public:
    SensorHXGetLightLuxEx(JObject *pParent = NULL, const char *szName = JK_SensorHXGetLightLuxEx):
    JObject(pParent,szName),
	Channel(this, "Channel"),
	Info(this, "Info"){
	};

    ~SensorHXGetLightLuxEx(void){};
};

NS_NETSDK_CFG_END