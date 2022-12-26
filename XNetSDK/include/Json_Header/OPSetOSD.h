#pragma once
#include "JObject_NetSDK.h"
#include "OSDInfo.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPSetOSD "OPSetOSD" 
class OPSetOSD : public JObject
{
public:
	JStrObj		strEnc;
	JObjArray<OSDInfo> mOSDInfo;
	
public:
	OPSetOSD(JObject *pParent = NULL, const char *szName = JK_OPSetOSD):
	JObject(pParent,szName),
	strEnc(this, "strEnc"),
	mOSDInfo(this, "OSDInfo"){
		this->Parse("{ \"Name\" : \"OPSetOSD\", \"OPSetOSD\" : { \"OSDInfo\" : [ { \"Info\" : [ \"CAM01\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\" ], \"OSDInfoWidget\" : { \"BackColor\" : \"0xF00000FF\", \"EncodeBlend\" : true, \"FrontColor\" : \"0x40000000\", \"PreviewBlend\" : false, \"RelativePos\" : [ 425, 728, 55318480, 0 ] } } ], \"strEnc\" : \"UTF-8\" }, \"SessionID\" : \"0x29\" }");
	};

	~OPSetOSD(void){};
};

NS_NETSDK_CFG_END