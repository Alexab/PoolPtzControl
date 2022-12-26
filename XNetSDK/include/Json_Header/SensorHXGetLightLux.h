#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_SensorHXGetLightLux "SensorHXGetLightLux" 
class SensorHXGetLightLux : public JObject
{
public:
	JIntObj		Channel;
	
public:
    SensorHXGetLightLux(JObject *pParent = NULL, const char *szName = JK_SensorHXGetLightLux):
    JObject(pParent,szName),
	Channel(this, "Channel"){
	this->Parse("{\"Name\" : \"SensorHXGetLightLux\",\"SensorHXGetLightLux\" : {\"Channel\" :0}}");
	};

    ~SensorHXGetLightLux(void){};
};

NS_NETSDK_CFG_END