#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OSDInfoWidget "OSDInfoWidget" 
class OSDInfoWidget : public JObject
{
public:
	JStrObj		BackColor;		/// 物件的后景MakeRGB，和透明度
	JBoolObj	EncodeBlend;	/// 编码叠加
	JStrObj		FrontColor;		/// 物件的前景MakeRGB，和透明度
	JBoolObj	PreviewBlend;	/// 预览叠加
	JObjArray<JIntObj>	RelativePos;	/// 物件边距与整长的比例*8191([左，上，右，下])

public:
	OSDInfoWidget(JObject *pParent = NULL, const char *szName = JK_OSDInfoWidget):
	JObject(pParent,szName),
	BackColor(this, "BackColor"),
	EncodeBlend(this, "EncodeBlend"),
	FrontColor(this, "FrontColor"),
	PreviewBlend(this, "PreviewBlend"),
	RelativePos(this, "RelativePos"){
	};

	~OSDInfoWidget(void){};
};

NS_NETSDK_CFG_END