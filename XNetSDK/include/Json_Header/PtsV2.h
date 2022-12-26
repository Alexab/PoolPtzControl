#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_PtsV2 "Pts" 
class PtsV2 : public JObject
{
public:
	JIntObj		X;
	JIntObj		Y;
	

public:
    PtsV2(JObject *pParent = NULL, const char *szName = JK_PtsV2):
    JObject(pParent,szName),
	X(this, "X"),
	Y(this, "Y"){
	};

    ~PtsV2(void){};
};

NS_NETSDK_CFG_END