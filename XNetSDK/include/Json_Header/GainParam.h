#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_GainParam "GainParam" 
class GainParam : public JObject
{
public:
	JIntObj		AutoGain;	/// 自动增益是否启用，0:不开启  1:开启
	JIntObj		Gain;		/// 自动增益上限(自动增益启用)或固定增益值

public:
	GainParam(JObject *pParent = NULL, const char *szName = JK_GainParam):
	JObject(pParent,szName),
	AutoGain(this, "AutoGain"),
	Gain(this, "Gain"){
	};

	~GainParam(void){};
};

NS_NETSDK_CFG_END