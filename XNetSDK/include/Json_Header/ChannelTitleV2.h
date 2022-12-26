#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_ChannelTitle "ChannelTitle" 
class ChannelTitleV2 : public JObject
{
public:
	JObjArray<JStrObj> ChannelTitleEx;
	
public:
	ChannelTitleV2(JObject *pParent = NULL):
	JObject(pParent),
	ChannelTitleEx(this, "ChannelTitle"){
	};

	~ChannelTitleV2(void){};
};

NS_NETSDK_CFG_END