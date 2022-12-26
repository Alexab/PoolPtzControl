#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPNetKeyboard "OPNetKeyboard" 
class OPNetKeyboard : public JObject
{
public:
	JStrObj	Status;
	JStrObj	Value;
	
public:
	OPNetKeyboard(JObject *pParent = NULL, const char *szName = JK_OPNetKeyboard):
	JObject(pParent,szName),
	Status(this, "Status"),
	Value(this, "Value"){
		this->Parse("{\"Name\" : \"OPNetKeyboard\",\"OPNetKeyboard\" : {\"Status\" : \"KeyUp\",\"Value\" : \"AutoTour\"},\"SessionID\" : \"0x5a91\"}");
	};

	~OPNetKeyboard(void){};
};

NS_NETSDK_CFG_END