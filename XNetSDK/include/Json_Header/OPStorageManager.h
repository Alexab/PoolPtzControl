#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

///硬盘操作"Action"支持的字符串说明
///<1、"SetType":	设置类型
///<2、"Recover":	恢复错误
///<3、"Partition":	分区操作
///<4、"Clear":		清除操作

///<如果Action为"SetType"时，没有"PartitionSize"字段，有"Type"字段
///类型"Type"字符串操作对应的说明
///<a."ReadWrite":	读写驱动器
///<b."ReadOnly":	只读驱动器
///<c."Events":		事件驱动器
///<d."Redundant":	冗余驱动器
///<e."SnapShot":	快照驱动器

///<如果Action为"Clear"时，没有"PartitionSize"字段，有"Type"字段
///类型"Type"字符串操作对应的说明
///<a."Data":		清除录像数据
///<b."Partition":	清除分区

///如果Action为"Partition"时,没有"Type"字段，有"PartitionSize"字段

#define JK_OPStorageManager "OPStorageManager"

struct ConfigPair
{
	const char* name;
	int value;
};

static ConfigPair s_storageControlTypeMapsSetType[] =
{
	{"ReadWrite", 0},
	{"ReadOnly", 1},
	{"Events", 2},
	{"Redundant", 3},
	{"SnapShot", 4},
	{NULL,},
};

static ConfigPair s_storageControlTypeMapsClear[] =
{
	{"Data", 0},
	{"Partition", 1},
	{NULL,},
};


///如果是设置类型或清除操作
class OPStorageManagerA : public JObject
{
public:
	JStrObj		Action;				///< 硬盘操作，支持操作如上所述 
	JIntObj		PartNo;				///< 分区号
	JIntObj		SerialNo;			///< 磁盘序列号
	JStrObj		Type;				///< 类型

public:
	OPStorageManagerA(JObject* pParent = NULL, const char* szName = JK_OPStorageManager) :
		JObject(pParent, szName),
		Action(this, "Action"),
		PartNo(this, "PartNo"),
		SerialNo(this, "SerialNo"),
		Type(this, "Type") {
		this->Parse("{ \"Name\" : \"OPStorageManager\", \"OPStorageManager\" : { \"Action\" : \"Clear\", \"PartNo\" : 0, \"SerialNo\" : 0, \"Type\" : \"Data\" }, \"SessionID\" : \"0x50fb5\" }");
	};

	~OPStorageManagerA(void) {};
};

///如果是恢复错误操作
class OPStorageManagerB : public JObject
{
public:
	JStrObj		Action;				///< 硬盘操作，支持操作如上所述 
	JIntObj		PartNo;				///< 分区号
	JIntObj		SerialNo;			///< 磁盘序列号

public:
	OPStorageManagerB(JObject* pParent = NULL, const char* szName = JK_OPStorageManager) :
		JObject(pParent, szName),
		Action(this, "Action"),
		PartNo(this, "PartNo"),
		SerialNo(this, "SerialNo") {
		this->Parse("{ \"Name\" : \"OPStorageManager\", \"OPStorageManager\" : { \"Action\" : \"Clear\", \"PartNo\" : 0, \"SerialNo\" : 0}, \"SessionID\" : \"0x50fb5\" }");
	};

	~OPStorageManagerB(void) {};
};

NS_NETSDK_CFG_END
