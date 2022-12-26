#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_ExposureParam "ExposureParam" 
class ExposureParam : public JObject //曝光
{
public:
	JIntHex		LeastTime;	/// 自动曝光时间下限或手动曝光时间，单位微秒
	JIntObj		Level;		/// 曝光等级
	JIntHex		MostTime;	/// 自动曝光时间上限，单位微秒

public:
	ExposureParam(JObject *pParent = NULL, const char *szName = JK_ExposureParam):
	JObject(pParent,szName),
	LeastTime(this, "LeastTime"),
	Level(this, "Level"),
	MostTime(this, "MostTime"){
	};

	~ExposureParam(void){};
};

NS_NETSDK_CFG_END