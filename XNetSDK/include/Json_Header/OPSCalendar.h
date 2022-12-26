#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPSCalendar "OPSCalendar" 

class OPSCalendar : public JObject
{
public:
	JStrObj		Event;
	JStrObj		FileType;
	JIntObj		Month;
	JStrObj		Rev;
	JIntObj		Year;

public:
	OPSCalendar(JObject *pParent = NULL, const char *szName = JK_OPSCalendar):
	JObject(pParent,szName),
	Event(this, "Event"),
	FileType(this, "FileType"),
	Month(this, "Month"),
	Rev(this, "Rev"),
	Year(this, "Year")
	{
		this->Parse("{ \"Name\" : \"OPSCalendar\", \"OPSCalendar\" : { \"Event\" : \"*\", \"FileType\" : \"h264\", \"Month\" : 3, \"Rev\" : \"\", \"Year\" : 2020 }, \"SessionID\" : \"0x95\" }");
	};

	~OPSCalendar(void){};
};

NS_NETSDK_CFG_END