#pragma once
#include "JObject.h"
#include "OSDInfo.h"
NS_NETSDK_CFG_BEGIN

#define JK_fVideo_OSDInfo "fVideo.OSDInfo" 
class fVideo_OSDInfo : public JObject
{
public:
	JStrObj		strEnc;		///编码格式默认“UTF-8”
	JObjArray<OSDInfo> mOSDInfo;
	
public:
	fVideo_OSDInfo(JObject *pParent = NULL, const char *szName = JK_fVideo_OSDInfo):
	JObject(pParent,szName),
	strEnc(this, "strEnc"),
	mOSDInfo(this, "OSDInfo"){
		this->Parse("{ \"Name\" : \"fVideo.OSDInfo\", \"fVideo.OSDInfo\" : { \"OSDInfo\" : [ { \"Info\" : [ \"CAM01\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\", \"\" ], \"OSDInfoWidget\" : { \"BackColor\" : \"0xF00000FF\", \"EncodeBlend\" : true, \"FrontColor\" : \"0x40000000\", \"PreviewBlend\" : false, \"RelativePos\" : [ 425, 728, 55318480, 0 ] } } ], \"strEnc\" : \"UTF-8\" }, \"SessionID\" : \"0x29\" }");
	};

	~fVideo_OSDInfo(void){};
};

NS_NETSDK_CFG_END