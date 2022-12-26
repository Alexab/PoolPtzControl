#pragma once
#include "JObject_NetSDK.h"
#include "ExtraFormat.h"
#include "MainFormat.h"
NS_NETSDK_CFG_BEGIN

//Attribute校验方式
#define NOPARITY "None"				//无
#define ODDPARITY "Odd"				//奇校验
#define EVENPARITY "Even"			//偶校验
#define MARKPARITY "Mark"			//标志位校验
#define SPACEPARITY "Space"			//空检验

#define JK_Uart_RS485 "Uart.RS485"  
class Uart_RS485 : public JObject
{
public:
	JStrObj		ProtocolName;
	JIntObj		DeviceNo;
	JIntObj		NumberInMatrixs;
	JIntObj		PortNo;
	JObjArray<JIntObj>	Attribute;

public:
	Uart_RS485(JObject *pParent = NULL, const char *szName = JK_Uart_RS485):
	JObject(pParent,szName),
	ProtocolName(this, "ProtocolName"),
	DeviceNo(this, "DeviceNo"),
	NumberInMatrixs(this, "NumberInMatrixs"),
	PortNo(this, "PortNo"),
	Attribute(this, "Attribute"){
	};

	~Uart_RS485(void){};
};

NS_NETSDK_CFG_END