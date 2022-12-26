#pragma once
#include "JObject_NetSDK.h"
#include "ExtraFormat.h"
#include "MainFormat.h"
NS_NETSDK_CFG_BEGIN

#define JK_Uart_Comm "Uart.Comm" 
class Uart_Comm : public JObject
{
public:
	JStrObj		ProtocolName;
	JIntObj		PortNo;
	JObjArray<JIntObj>	Attribute;

public:
	Uart_Comm(JObject *pParent = NULL, const char *szName = JK_Uart_Comm):
	JObject(pParent,szName),
	ProtocolName(this, "ProtocolName"),
	PortNo(this, "PortNo"),
	Attribute(this, "Attribute"){
	};

	~Uart_Comm(void){};
};

NS_NETSDK_CFG_END