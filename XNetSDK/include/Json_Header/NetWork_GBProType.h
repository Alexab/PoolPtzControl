#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_GBProType "NetWork.GBProType" 
class NetWork_GBProType : public JObject
{
public:
	JIntObj	SIPTranType;				//连接协议值1、2和3分别对应UDP、TCP和TCP&UDP
	JIntObj	TalkTransType;				

public:
	NetWork_GBProType(JObject *pParent = NULL, const char *szName = JK_NetWork_GBProType):
	JObject(pParent,szName),
	SIPTranType(this, "SIPTranType"),
	TalkTransType(this, "TalkTransType"){
	};

	~NetWork_GBProType(void)
	{
		this->Parse("{\"Name\":\"NetWork.GBProType\",\"NetWork.GBProType\":{\"SIPTranType\":1,\"TalkTransType\":1},\"Ret\":100,\"SessionID\":\"0x00000083\"}");
	};
};

NS_NETSDK_CFG_END