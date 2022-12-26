#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_DAS "NetWork.DAS" 
class NetWork_DAS : public JObject
{
public:
	JStrObj			DeviceID;				//设备的ID号--按自己需求设置
	JBoolObj		Enable;					//是否开启DAS
	JStrObj			Password;				//设备密码
	JIntObj			Port;					//端口号--主要是用于监听的端口(和XSDK_StartDASServer接口端口一致)
	JStrObj			ServerAddr;				//服务器地址
	JStrObj			UserName;				//用户名
	
public:
	NetWork_DAS(JObject *pParent = NULL, const char *szName = JK_NetWork_DAS):
	JObject(pParent,szName),
	DeviceID(this, "DeviceID"),
	Enable(this, "Enable"),
	Password(this, "Password"),
	Port(this, "Port"),
	ServerAddr(this, "ServerAddr"),
	UserName(this, "UserName"){
	};

	~NetWork_DAS(void){};
};

NS_NETSDK_CFG_END