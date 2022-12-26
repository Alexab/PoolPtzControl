#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

////////////////////前端连接状态Status枚举如下/////
#define S_STATUS_NONE		"None"				///无
#define S_STATUS_NOCONFIG	"NoConfig"			///未配置
#define S_STATUS_NOLOGIN	"NoLogin"			///未登录
#define S_STATUS_NOCONNECT	"NoConnect"			///未连接
#define S_STATUS_CONNECTED	"Connected"			///已连接
#define S_STATUS_UNKNOWN	"UnKnown"			///未知
#define S_STATUS_OFFLINE	"Offline"			///不在线

#define JK_NetWork_ChnStatus "NetWork.ChnStatus" 
class NetWork_ChnStatus : public JObject
{
public:
	JStrObj		ChnName;
	JStrObj		CurRes;
	JStrObj		MaxRes;
	JStrObj		Status;

public:
    NetWork_ChnStatus(JObject *pParent = NULL, const char *szName = JK_NetWork_ChnStatus):
    JObject(pParent,szName),
	ChnName(this, "ChnName"),
	CurRes(this, "CurRes"),
	MaxRes(this, "MaxRes"),
	Status(this, "Status"){
	};

    ~NetWork_ChnStatus(void){};
};

NS_NETSDK_CFG_END