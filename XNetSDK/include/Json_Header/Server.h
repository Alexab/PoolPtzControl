#pragma once
#include "JObject_NetSDK.h"

NS_NETSDK_CFG_BEGIN

#define JK_Server "Server" 
class Server : public JObject
{
public:
	JStrObj			Address;
	JBoolObj		Anonymity;
	JStrObj			Name;
	JStrObj			Password;
	JIntObj			Port;
	JStrObj			UserName;
	
public:
    Server(JObject *pParent = NULL, const char *szName = JK_Server):
    JObject(pParent,szName),
	Address(this, "Address"),
	Anonymity(this, "Anonymity"),
	Name(this, "Name"),
	Password(this, "Password"),
	Port(this, "Port"),
	UserName(this, "UserName"){
	};

    ~Server(void){};
};

NS_NETSDK_CFG_END