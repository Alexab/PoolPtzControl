#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetOrder "NetOrder" 
class NetOrder : public JObject
{
public:
	JBoolObj		NetOrder;			///< 网络优先级能力
	
public:
	NetOrder(JObject *pParent = NULL, const char *szName = JK_NetOrder):
	JObject(pParent,szName),
	NetOrder(this, "NetOrder"){
	};

	~NetOrder(void){};
};

NS_NETSDK_CFG_END
