#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_General_AutoMaintain "General.AutoMaintain" 
class General_AutoMaintain : public JObject
{
public:
	JIntObj		AutoDeleteFilesDays;	///< 自动删除文件时间[0, 30]
	JStrObj		AutoRebootDay;			///< 自动重启设置日期,例如"Tuesday"
	JIntObj		AutoRebootHour;			///< 重启整点时间[0, 23]

public:
    General_AutoMaintain(JObject *pParent = NULL, const char *szName = JK_General_AutoMaintain):
    JObject(pParent,szName),
	AutoDeleteFilesDays(this, "AutoDeleteFilesDays"),
	AutoRebootDay(this, "AutoRebootDay"),
	AutoRebootHour(this, "AutoRebootHour"){
	};

    ~General_AutoMaintain(void){};
};

NS_NETSDK_CFG_END