#pragma once
#include "JObject_NetSDK.h"
#include "OSDInfoWidget.h"
NS_NETSDK_CFG_BEGIN

#define JK_OSDInfo "OSDInfo" 
class OSDInfo : public JObject
{
public:
	JObjArray<JStrObj>	Info;	/// 叠加信息，最多叠加12行，每行最多64个字符
	OSDInfoWidget		mOSDInfoWidget;
	
public:
	OSDInfo(JObject *pParent = NULL, const char *szName = JK_OSDInfo):
	JObject(pParent,szName),
	Info(this, "Info"),
	mOSDInfoWidget(this, "OSDInfoWidget"){
	};

	~OSDInfo(void){};
};

NS_NETSDK_CFG_END