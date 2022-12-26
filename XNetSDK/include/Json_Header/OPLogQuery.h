#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPLogQuery "OPLogQuery" 
class OPLogQuery : public JObject
{
public:
	JStrObj		BeginTime;			///< 查询日志开始时间，格式：YYYY-MM-DD HH:mm:SS
	JStrObj		EndTime;			///< 查询日志结束时间，格式：YYYY-MM-DD HH:mm:SS
	JIntObj		LogPosition;		///< 从上次查询的结束时的日志指针:0
	JStrObj		Type;				///< 日志类型--“LogAll”：所有；"LogSystem"：系统；"LogConfig":配置;"LogStorage"：存储;"LogAlarm":报警;"LogRecord"：录像;"LogAccount":账号;"LogFile":文件

public:
    OPLogQuery(JObject *pParent = NULL, const char *szName = JK_OPLogQuery):
    JObject(pParent,szName),
	BeginTime(this, "BeginTime"),
	EndTime(this, "EndTime"),
	LogPosition(this, "LogPosition"),
	Type(this, "Type"){
		this->Parse("{ \"Name\" : \"OPLogQuery\", \"OPLogQuery\" : { \"BeginTime\" : \"2019-03-27 00:00:00\", \"EndTime\" : \"2019-03-27 23:59:59\", \"LogPosition\" : 0, \"Type\" : \"LogAll\" }, \"SessionID\" : \"0x1\" }");
	};

    ~OPLogQuery(void){};
};

NS_NETSDK_CFG_END