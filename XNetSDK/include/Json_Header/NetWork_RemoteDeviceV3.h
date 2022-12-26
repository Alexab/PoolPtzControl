#pragma once
#include "JObject_NetSDK.h"
#include "Decoder.h"

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_RemoteDeviceV3 "NetWork.RemoteDeviceV3" 
class NetWork_RemoteDeviceV3 : public JObject
{
public:
	JBoolObj	Enable;
	JStrObj		ConnType;
	JIntObj		TourIntv;
	JStrObj		SingleConnId;
	JBoolObj	EnCheckTime;
	JBoolObj	SynchResolution;
	JObjArray<Decoder>	m_ndecoder;
public:
	NetWork_RemoteDeviceV3(JObject *pParent = NULL, const char *szName = JK_NetWork_RemoteDeviceV3):
	JObject(pParent,szName),
	Enable(this, "Enable"),
	ConnType(this, "ConnType"),
	TourIntv(this, "TourIntv"),
	SingleConnId(this, "SingleConnId"),
	EnCheckTime(this, "EnCheckTime"),
	SynchResolution(this, "SynchResolution"),
	m_ndecoder(this, "Decoder"){
	};

	~NetWork_RemoteDeviceV3(void){};
};

NS_NETSDK_CFG_END