#pragma once
#include "JObject_NetSDK.h"

//ChnMode:通道类型掩码，模拟通道类型为1，数字通道类型为0
//ChnTotalNum:通道总路数
//UseCustomMode:是否使用自定义模式
NS_NETSDK_CFG_BEGIN

#define JK_AVEnc_ChnDAModeState "AVEnc.ChnDAModeState" 
class AVEnc_ChnDAModeState : public JObject
{
public:
	JBoolObj		UseCustomMode;
	JIntObj			ChnTotalNum;
	JStrObj			ChnMode;
	
public:
    AVEnc_ChnDAModeState(JObject *pParent = NULL, const char *szName = JK_AVEnc_ChnDAModeState):
    JObject(pParent,szName),
	UseCustomMode(this, "UseCustomMode"),
	ChnTotalNum(this, "ChnTotalNum"),
	ChnMode(this, "ChnMode"){
	};

    ~AVEnc_ChnDAModeState(void){};
};

NS_NETSDK_CFG_END