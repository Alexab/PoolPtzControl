#pragma once
#include "JObject_NetSDK.h"

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_MidDAS "NetWork.MidDAS" 
class NetWork_MidDAS : public JObject
{
public:
	JBoolObj		Enable;				//DAS功能是否开启
	JBoolObj		MidEnable;			//中心服务器是否生效，如果生效，用中心服务器提供的ip和端口号，如果不生效，用设置的直接ip和端口号
	JStrObj			UserName;			//用户名
	JStrObj			Password;			//密码
	JStrObj			ServerAddr;			//集群服务器地址
	
public:
    NetWork_MidDAS(JObject *pParent = NULL, const char *szName = JK_NetWork_MidDAS):
    JObject(pParent,szName),
	Enable(this, "Enable"),
	MidEnable(this, "MidEnable"),
	UserName(this, "UserName"),
	Password(this, "Password"),
	ServerAddr(this, "ServerAddr"){
	};

    ~NetWork_MidDAS(void){};
};

NS_NETSDK_CFG_END