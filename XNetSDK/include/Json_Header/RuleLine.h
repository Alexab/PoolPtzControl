#pragma once
#include "JObject_NetSDK.h"
#include "Pts.h"

NS_NETSDK_CFG_BEGIN

#define JK_RuleLine "RuleLine" 
class RuleLine : public JObject
{
public:
	JIntObj		AlarmDirect;	// 顺起始点终止点法线方向为正向,逆起始点终止点法线方向为反向
	Pts			m_Pts;

public:
    RuleLine(JObject *pParent = NULL, const char *szName = JK_RuleLine):
    JObject(pParent,szName),
	AlarmDirect(this, "AlarmDirect"),
	m_Pts(this, "Pts"){
	};

    ~RuleLine(void){};
};

NS_NETSDK_CFG_END