#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPSetOSDInfo "OPSetOSDInfo" 
class OPSetOSDInfo : public JObject
{
public:
	JIntObj		Channel;		//要设置的通道
	JIntObj		Index;			//设置通道标题和时间标题之外的区域，取值0和1
	JIntObj		xPosition;		//范围0-1000
	JIntObj		yPosition;		//范围0-1000
	JStrObj		String;			//单次最多64个字符
	
public:
	OPSetOSDInfo(JObject *pParent = NULL, const char *szName = JK_OPSetOSDInfo):
	JObject(pParent,szName),
	Channel(this, "Channel"),
	Index(this, "Index"),
	xPosition(this, "xPosition"),
	yPosition(this, "yPosition"),
	String(this, "String"){
		this->Parse("{ \"Name\" : \"OPSetOSDInfo\", \"OPSetOSDInfo\" : { \"Channel\" : 0, \"Index\" : 1, \"String\" : \"1111122222\", \"xPosition\" : 500, \"yPosition\" : 300 }, \"SessionID\" : \"0x19\" }");
	};

	~OPSetOSDInfo(void){};
};

NS_NETSDK_CFG_END