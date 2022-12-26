#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_SensorHXManualWakeUp "SensorHXManualWakeUp" 
class SensorHXManualWakeUp : public JObject
{
public:
	JIntObj		Channel;
	
public:
    SensorHXManualWakeUp(JObject *pParent = NULL, const char *szName = JK_SensorHXManualWakeUp):
    JObject(pParent,szName),
	Channel(this, "Channel"){
	this->Parse("{\"Name\" : \"SensorHXManualWakeUp\",\"SensorHXManualWakeUp\" : {\"Channel\" :0}}");
	};

    ~SensorHXManualWakeUp(void){};
};

NS_NETSDK_CFG_END