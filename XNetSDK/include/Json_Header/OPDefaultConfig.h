#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPDefaultConfig "OPDefaultConfig" 
class OPDefaultConfig : public JObject
{
public:
	JBoolObj		Account;			// 用户管理
	JBoolObj		Alarm;				// 报警
	JBoolObj		CameraPARAM;		// 网络摄像头配置
	JBoolObj		CommPtz;			// 云台，串口
	JBoolObj		Encode;				// 编码配置
	JBoolObj		Factory;			// 恢复出厂设置配置
	JBoolObj		General;			// 普通配置
	JBoolObj		NetCommon;			// 通用网络
	JBoolObj		NetServer;			// 网络服务
	JBoolObj		Preview;			// 预览配置
	JBoolObj		Record;				// 录像配置

public:
	OPDefaultConfig(JObject *pParent = NULL, const char *szName = JK_OPDefaultConfig):
	JObject(pParent,szName),
	Account(this, "Account"),
	Alarm(this, "Alarm"),
	CameraPARAM(this, "CameraPARAM"),
	CommPtz(this, "CommPtz"),
	Encode(this, "Encode"),
	Factory(this, "Factory"),
	General(this, "General"),
	NetCommon(this, "NetCommon"),
	NetServer(this, "NetServer"),
	Preview(this, "Preview"),
	Record(this, "Record"){
		this->Parse("{ \"Name\" : \"OPDefaultConfig\", \"OPDefaultConfig\" : { \"Account\" : false, \"Alarm\" : false, \"CameraPARAM\" : false, \"CommPtz\" : false, \"Encode\" : false, \"Factory\" : false, \"General\" : false, \"NetCommon\" : false, \"NetServer\" : false, \"Preview\" : false, \"Record\" : false }, \"SessionID\" : \"0x4d\" }");
	};

    ~OPDefaultConfig(void){};
};

NS_NETSDK_CFG_END