#pragma once
#include "JObject_NetSDK.h"
#include "RuleLine.h"
#include "RuleRegion.h"

NS_NETSDK_CFG_BEGIN

#define JK_PedRule "PedRule" 
class PedRule : public JObject
{
public:
	JBoolObj		Enable;					///< 是否开启
	JIntObj			RuleType;				 //< 规则类型
	RuleLine		m_RuleLine;
	RuleRegion		m_RuleRegion;

public:
    PedRule(JObject *pParent = NULL, const char *szName = JK_PedRule):
    JObject(pParent,szName),
	Enable(this, "Enable"),
	RuleType(this, "RuleType"),
	m_RuleLine(this, "RuleLine"),
	m_RuleRegion(this, "RuleRegion"){
	};

    ~PedRule(void){};
};

NS_NETSDK_CFG_END