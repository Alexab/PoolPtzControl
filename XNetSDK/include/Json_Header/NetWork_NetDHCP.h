#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetDHCP "NetWork.NetDHCP" 
class NetWork_NetDHCP : public JObject
{
public:
	JBoolObj		Enable;			///< ÊÇ·ñ¿ªÆô
	JStrObj			Interface;		///< Íø¿¨Ãû³Æ 

public:
	NetWork_NetDHCP(JObject *pParent = NULL, const char *szName = JK_NetWork_NetDHCP):
	JObject(pParent,szName),
	Enable(this, "Enable"),
	Interface(this, "Interface"){
	};

	~NetWork_NetDHCP(void){};
};

NS_NETSDK_CFG_END
