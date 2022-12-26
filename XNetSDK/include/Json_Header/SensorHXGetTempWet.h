#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_SensorHXGetTempWet "SensorHXGetTempWet" 
class SensorHXGetTempWet : public JObject
{
public:
	JIntObj		Channel;
	
public:
    SensorHXGetTempWet(JObject *pParent = NULL, const char *szName = JK_SensorHXGetTempWet):
    JObject(pParent,szName),
	Channel(this, "Channel"){
		this->Parse("{\"Name\" : \"SensorHXGetTempWet\",\"SensorHXGetTempWet\" : {\"Channel\" :0}}");
	};

    ~SensorHXGetTempWet(void){};
};

NS_NETSDK_CFG_END