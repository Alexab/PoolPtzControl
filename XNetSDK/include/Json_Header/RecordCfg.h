#pragma once
#include "JsonCfgBase.h"

NS_NETSDK_CFG_BEGIN

/////////////////////////录像模式字符串及其注释//////////////////////
#define RECORD_MODE_CLOSED		"ClosedRecord"		///< 关闭录像
#define RECORD_MODE_MANUAL		"ManualRecord"		///< 手动录像
#define RECORD_MODE_CONFIG		"ConfigRecord"		///< 按配置录像

#define JK_Record "Record"
class RecordCfg : public JObject 
{
public:
    JObjArray<JObjArray<JIntHex> > Mask;			///< 录像类型掩码
	JIntObj		PacketLength;						///< 录像打包长度（分钟）[1, 255]
	JIntObj		PreRecord;							///< 预录时间，为零时表示关闭
	JStrObj		RecordMode;							///< 录像模式
	JBoolObj	Redundancy;							///< 冗余开关
	JObjArray<JObjArray<JStrObj> >	TimeSection;	///< 录像时间段


public:
	RecordCfg(JObject *pParent = NULL, const char *szName = JK_Record):
	JObject(pParent,szName),
	Mask(this, "Mask"),
	PacketLength(this, "PacketLength"),
	PreRecord(this, "PreRecord"),
	RecordMode(this, "RecordMode"),
	Redundancy(this, "Redundancy"),
	TimeSection(this, "TimeSection"){
	};

	~RecordCfg(void){};
};

NS_NETSDK_CFG_END