#pragma once
#include "JObject_NetSDK.h"
#include "NetOrderInfo.h"

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetOrder "NetWork.NetOrder" 
class NetWork_NetOrder : public JObject
{
public:
	JBoolObj		Enable;							///< �Ƿ������������ȼ�
	JIntObj			NetCount;						///< ����������Ŀ
	JObjArray<NetOrderInfo>		m_NetOrderInfo;		///< �������ȼ�

public:
	NetWork_NetOrder(JObject *pParent = NULL, const char *szName = JK_NetWork_NetOrder):
	JObject(pParent,szName),
	Enable(this, "Enable"),
	NetCount(this, "NetCount"),
	m_NetOrderInfo(this, "NetOrder"){
	};

	~NetWork_NetOrder(void){};
};

NS_NETSDK_CFG_END
