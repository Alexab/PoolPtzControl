#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_fVideo_Volume "fVideo.Volume" 
class fVideo_Volume : public JObject
{
public:
	JStrObj		AudioMode;
	JIntObj		LeftVolume;
	JIntObj		RightVolume;	
	
public:
    fVideo_Volume(JObject *pParent = NULL, const char *szName = JK_fVideo_Volume):
    JObject(pParent,szName),
	AudioMode(this, "AudioMode"),
	LeftVolume(this, "LeftVolume"),
	RightVolume(this, "RightVolume"){
	};

    ~fVideo_Volume(void){};
};

NS_NETSDK_CFG_END