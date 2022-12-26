#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_IntelDataWriteRsp "IntelDataWriteRsp" 
class IntelDataWriteRsp : public JObject
{
public:
	JIntObj		Index;

public:
	IntelDataWriteRsp(JObject *pParent = NULL, const char *szName = JK_IntelDataWriteRsp):
	JObject(pParent,szName),
	Index(this, "Index"){
	};

	~IntelDataWriteRsp(void){};
};

NS_NETSDK_CFG_END