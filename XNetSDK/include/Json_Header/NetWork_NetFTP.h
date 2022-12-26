#pragma once
#include "JObject_NetSDK.h"
#include "Server.h"

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetFTP "NetWork.NetFTP" 
class NetWork_NetFTP : public JObject
{
public:
	JBoolObj		Enable;
	JStrObj			Directory;
	JIntObj			MaxFileLen;
	Server			m_nServer;
	
public:
    NetWork_NetFTP(JObject *pParent = NULL, const char *szName = JK_NetWork_NetFTP):
    JObject(pParent,szName),
	Enable(this, "Enable"),
	Directory(this, "Directory"),
	MaxFileLen(this, "MaxFileLen"),
	m_nServer(this, "Server"){
	};

    ~NetWork_NetFTP(void){};
};

NS_NETSDK_CFG_END