#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OriginalCoordinates "OriginalCoordinates" 
class OriginalCoordinates : public JObject
{
public:
	JIntObj		bottom;
	JIntObj		left;				
	JIntObj		right;
	JIntObj		top;			
	
public:
    OriginalCoordinates(JObject *pParent = NULL, const char *szName = JK_OriginalCoordinates):
    JObject(pParent,szName),
	bottom (this, "bottom"),
	left (this, "left"),
	right (this, "right"),
	top (this, "top"){
	};

    ~OriginalCoordinates(void){};
};

NS_NETSDK_CFG_END