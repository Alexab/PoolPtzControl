#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetDNS "NetWork.NetDNS" 
class NetWork_NetDNS : public JObject
{
public:
	JStrObj		Address;			///< 首选DNS地址
	JStrObj		SpareAddress;		///< 备选DNS地址
	
public:
	NetWork_NetDNS(JObject *pParent = NULL, const char *szName = JK_NetWork_NetDNS):
	JObject(pParent,szName),
	Address(this, "Address"),
	SpareAddress(this, "SpareAddress"){
		this->parse("{ \"Name\" : \"NetWork.NetDNS\", \"NetWork.NetDNS\" : { \"Address\" : \"0x72727272\", \"SpareAddress\" : \"0x0101A8C0\" }, \"SessionID\" : \"0x73c\" }");
	};

	~NetWork_NetDNS(void){};
};

NS_NETSDK_CFG_END
