#pragma once
#include "JObject_NetSDK.h"
#include "BroadTrends.h"
NS_NETSDK_CFG_BEGIN

#define JK_Camera_ParamEx "Camera.ParamEx"
class Camera_ParamEx : public JObject //
{
public:
	JIntObj		AeMeansure;			/// 测光模式校正  0:平均测光 1:中央测光**/
	BroadTrends	mBroadTrends;		/// 宽动态
	JIntObj		Dis;				/// 电子防抖设置  0:关闭 1:开启
	JStrObj		ExposureTime;		/// 实际生效的曝光时间
	JIntObj		Ldc;				/// 镜头畸变校正  0:关闭 1:开启
	JIntObj		LowLuxMode;			/// 微光模式 mode：0 关闭 1开启 ==only imx291
	JStrObj		Style;				/// 风格:"typedefault"/"type1"/"type2"

public:
    Camera_ParamEx(JObject *pParent = NULL, const char *szName = JK_Camera_ParamEx):
    JObject(pParent,szName),
	AeMeansure(this, "AeMeansure"),
	mBroadTrends(this, "BroadTrends"),
	Dis(this, "Dis"),
	ExposureTime(this, "ExposureTime"),
	Ldc(this, "Ldc"),
	LowLuxMode(this, "LowLuxMode"),
	Style(this, "Style"){
	};

    ~Camera_ParamEx(void){};
};

NS_NETSDK_CFG_END