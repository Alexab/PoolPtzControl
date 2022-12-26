#pragma once
#include "JObject_NetSDK.h"

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_Upnp "NetWork.Upnp" 
class NetWork_Upnp : public JObject
{
public:
	JBoolObj		Enable;
	JIntObj			HTTPPort;
	JIntObj			MediaPort;
	JIntObj			MobilePort;
	JBoolObj		State;
	
public:
    NetWork_Upnp(JObject *pParent = NULL, const char *szName = JK_NetWork_Upnp):
    JObject(pParent,szName),
	Enable(this, "Enable"),
	HTTPPort(this, "HTTPPort"),
	MediaPort(this, "MediaPort"),
	MobilePort(this, "MobilePort"),
	State(this, "State"){
	};

    ~NetWork_Upnp(void){};
};

NS_NETSDK_CFG_END