#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

enum network_media 
{
	NM_WIRED = 0,  	///< ��������
	NM_WLAN,       	///< Wifi
	NM_3G,         	///< 3G����
	NM_NR,    		///< ������
};

#define JK_NetOrderInfo "NetOrder" 
class NetOrderInfo : public JObject
{
public:
	JIntObj			nNetOrder;			///< ����ԽС,���ȼ�Խ��,0��������ȼ�
	JIntObj			NetType;			///< ȡֵ��network_media���͵�

public:
	NetOrderInfo(JObject *pParent = NULL, const char *szName = JK_NetOrderInfo):
	JObject(pParent,szName),
	nNetOrder(this, "NetOrder"),
	NetType(this, "NetType"){
	};

	~NetOrderInfo(void){};
};

NS_NETSDK_CFG_END
