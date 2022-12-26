#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_Pts "Pts" 
class Pts : public JObject
{
public:
	JIntObj		StartX;
	JIntObj		StartY;
	JIntObj		StopX;
	JIntObj		StopY;
	

public:
    Pts(JObject *pParent = NULL, const char *szName = JK_Pts):
    JObject(pParent,szName),
	StartX(this, "StartX"),
	StartY(this, "StartY"),
	StopX(this, "StopX"),
	StopY(this, "StopY"){
	};

    ~Pts(void){};
};

NS_NETSDK_CFG_END