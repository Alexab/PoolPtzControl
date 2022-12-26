#pragma once
#include "JObject_NetSDK.h"
#include "Server.h"

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetNTP "NetWork.NetNTP" 
class NetWork_NetNTP : public JObject
{
public:
	JBoolObj		Enable;
	JIntObj			TimeZone;
	JIntObj			UpdatePeriod;
	Server			m_nServer;
	
	
public:
    NetWork_NetNTP(JObject *pParent = NULL, const char *szName = JK_NetWork_NetNTP):
    JObject(pParent,szName),
	Enable(this, "Enable"),
	TimeZone(this, "TimeZone"),
	UpdatePeriod(this, "UpdatePeriod"),
	m_nServer(this, "Server"){
	};

    ~NetWork_NetNTP(void){};
};

NS_NETSDK_CFG_END