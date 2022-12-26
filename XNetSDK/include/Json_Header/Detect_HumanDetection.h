#pragma once
#include "JObject_NetSDK.h"
#include "PedRule.h"

NS_NETSDK_CFG_BEGIN

#define JK_Detect_HumanDetection "Detect.HumanDetection" 
class Detect_HumanDetection : public JObject
{
public:
	JBoolObj		Enable;				/// 是否开启
	JIntObj			ObjectType;			/// 检测对象，0:人  0xFF:所有物体 
	JIntObj			Sensitivity;		/// 人形检测灵敏度
	JIntObj			ShowRule;			/// 是否显示规则
	JIntObj			ShowTrack;			/// 是否显示轨迹
	JObjArray<PedRule>	m_PedRule;

public:
	Detect_HumanDetection(JObject *pParent = NULL, const char *szName = JK_Detect_HumanDetection):
	JObject(pParent,szName),
	Enable(this, "Enable"),
	ObjectType(this, "ObjectType"),
	Sensitivity(this, "Sensitivity"),
	ShowRule(this, "ShowRule"),
	ShowTrack(this, "ShowTrack"),
	m_PedRule(this, "PedRule"){
	};

    ~Detect_HumanDetection(void){};
};

NS_NETSDK_CFG_END