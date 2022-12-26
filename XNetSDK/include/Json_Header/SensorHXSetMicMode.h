#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_SensorHXSetMicMode "SensorHXSetMicMode" 
class SensorHXSetMicMode : public JObject
{
public:
	JIntObj		Channel;
	JStrObj		Mode;
	
public:
    SensorHXSetMicMode(JObject *pParent = NULL, const char *szName = JK_SensorHXSetMicMode):
    JObject(pParent,szName),
	Channel(this, "Channel"),
	Mode(this, "Mode"){
	this->Parse("{\"Name\" : \"SensorHXSetMicMode\",\"SensorHXSetMicMode\" : {\"Channel\" :0,\"Mode\" : \"VoiceWakeUp\"}}");
	};

    ~SensorHXSetMicMode(void){};
};

NS_NETSDK_CFG_END