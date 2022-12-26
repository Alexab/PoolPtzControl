#pragma once
#include "JObject_NetSDK.h"
#include "OriginalCoordinates.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPIntelAnalysePushImg "OPIntelAnalysePushImg" 
class OPIntelAnalysePushImg : public JObject
{
public:
	JStrObj		FaceDetectType;								//目前有三种类型：FaceDetection，FaceRecognition，PFDR
	JStrObj		PictureType;
	JIntObj		FaceID;
	JIntObj		FaceSN;										//人脸流水号, 同一个人在一次人形报警中有相同的SN, 直到人形报警结束
	JIntObj		AlgorithmVersion;
	JIntObj		Clearness;									//范围未知, 越大清晰度越高
	JIntObj		EnterOrLeave;								//0进入 1离开 2持续
	OriginalCoordinates		m_nOriginalCoordinates;			//人脸坐标
	JStrObj		Time;										//这个字段只用于人形人脸检测

public:
    OPIntelAnalysePushImg(JObject *pParent = NULL, const char *szName = JK_OPIntelAnalysePushImg):
    JObject(pParent,szName),
	FaceDetectType (this, "FaceDetectType"),
	PictureType (this, "PictureType"),
	FaceID (this, "FaceID"),
	FaceSN (this, "FaceSN"),
	AlgorithmVersion (this, "AlgorithmVersion"),
	Clearness (this, "Clearness"),
	EnterOrLeave (this, "EnterOrLeave"),
	m_nOriginalCoordinates (this, "OriginalCoordinates"),
	Time (this, "Time"){
	};

    ~OPIntelAnalysePushImg(void){};
};

NS_NETSDK_CFG_END