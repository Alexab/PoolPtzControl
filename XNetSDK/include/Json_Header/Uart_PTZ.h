#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_Uart_PTZ "Uart.PTZ" 
class Uart_PTZ  : public JObject
{
public:
	JStrObj		ProtocolName;
	JIntObj		PortNo;
	JIntObj		DeviceNo;
	JIntObj		NumberInMatrixs;
	JObjArray<JIntObj>	Attribute;

public:
	Uart_PTZ (JObject *pParent = NULL, const char *szName = JK_Uart_PTZ):
	JObject(pParent,szName),
	ProtocolName(this, "ProtocolName"),
	PortNo(this, "PortNo"),
	DeviceNo(this, "DeviceNo"),
	NumberInMatrixs(this, "NumberInMatrixs"),
	Attribute(this, "Attribute"){
	};

	~Uart_PTZ (void){};
};

NS_NETSDK_CFG_END