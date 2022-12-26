#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

enum network_media 
{
	NM_WIRED = 0,  	///< 有线网卡
	NM_WLAN,       	///< Wifi
	NM_3G,         	///< 3G网卡
	NM_NR,    		///< 种类数
};

#define JK_NetOrderInfo "NetOrder" 
class NetOrderInfo : public JObject
{
public:
	JIntObj			nNetOrder;			///< 数字越小,优先级越高,0是最高优先级
	JIntObj			NetType;			///< 取值是network_media类型的

public:
	NetOrderInfo(JObject *pParent = NULL, const char *szName = JK_NetOrderInfo):
	JObject(pParent,szName),
	nNetOrder(this, "NetOrder"),
	NetType(this, "NetType"){
	};

	~NetOrderInfo(void){};
};

NS_NETSDK_CFG_END
