#pragma once
#include "JObject_NetSDK.h"
#include "PtsV2.h"

NS_NETSDK_CFG_BEGIN

#define JK_RuleRegion "RuleRegion" 
class RuleRegion : public JObject
{
public:
	JIntObj		AlarmDirect;	// 顺起始点终止点法线方向为正向,逆起始点终止点法线方向为反向
	JIntObj		PtsNum;			// 禁区描点数 	
	JObjArray<PtsV2>	m_PtsV2;
	
public:
    RuleRegion(JObject *pParent = NULL, const char *szName = JK_RuleRegion):
    JObject(pParent,szName),
	AlarmDirect(this, "AlarmDirect"),
	PtsNum(this, "PtsNum"),
	m_PtsV2(this, "Pts"){
	};

    ~RuleRegion(void){};
};

NS_NETSDK_CFG_END