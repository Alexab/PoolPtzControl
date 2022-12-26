#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPMachine "OPMachine" 
class OPMachine : public JObject
{
public:
	JStrObj		Action;

public:
	OPMachine(JObject *pParent = NULL, const char *szName = JK_OPMachine):
	JObject(pParent,szName),
	Action(this, "Action"){
		this->Parse("{ \"Name\" : \"OPMachine\", \"OPMachine\" : { \"Action\" : \"Shutdown\" }, \"SessionID\" : \"0x1b\" }");
	};

	~OPMachine(void){};
};

NS_NETSDK_CFG_END