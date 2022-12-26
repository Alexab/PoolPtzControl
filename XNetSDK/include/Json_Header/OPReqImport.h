#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPReqImport "OPReqImport" 
class OPReqImport : public JObject
{
public:
	JIntObj Channel;	
	JIntObj Length;
	JStrObj	IntelType;
	JStrObj	Opr;
	JIntObj	Index;
	
public:
	OPReqImport(JObject *pParent = NULL, const char *szName = JK_OPReqImport):
	JObject(pParent,szName),
	Channel(this, "Channel"),
	Length(this, "Length"),
	IntelType(this, "IntelType"),
	Index(this, "Index"),
	Opr(this, "Opr"){
		this->Parse("{\"Name\" : \"OPReqImport\",\"OPReqImport\" : {\"Channel\" : 0,\"Length\" : 0,\"Index\" : 0,\"IntelType\" : \"CarPlate\",\"Opr\" : \"Stop\"},\"SessionID\" : \"0x5a91\"}");
	};

	~OPReqImport(void){};
};

NS_NETSDK_CFG_END