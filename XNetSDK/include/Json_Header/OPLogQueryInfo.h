#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN


////////////////返回的日志类型字符串注释/////////////////
#define LogTypeAccountRestore			"AccountRestore"				//账号还原默认
#define LogTypeAddGroup					"AddGroup"						//添加组
#define LogTypeAddUser					"AddUser"						//增加用户
#define LogTypeClearDriver				"ClearDriver"					//清除驱动器数据
#define LogTypeClearLog					"ClearLog"						//清除日志
#define LogTypeDeleteGroup				"DeleteGroup"					//删除组
#define LogTypeDeleteUser				"DeleteUser"					//删除用户
#define LogTypeDiskChanged				"DiskChanged"					//存储设备变动
#define LogTypeEventLatch				"EventLatch"					//延迟事件
#define LogTypeEventStart				"EventStart"					//报警开始
#define LogTypeEventStop				"EventStop"						//报警结束
#define LogTypeFileAccess				"FileAccess"					//文件存取
#define LogTypeFileAccessError			"FileAccessError"				//文件访问出错
#define LogTypeFileSearch				"FileSearch"					//文件查询
#define LogTypeLogIn					"LogIn"							//用户登录
#define LogTypeLogOut					"LogOut"						//用户登出
#define LogTypeModifyGroup				"ModifyGroup"					//修改组
#define LogTypeModifyPassword			"ModifyPassword"				//修改密码
#define LogTypeModifyTime				"ModifyTime"					//修改系统时间
#define LogTypeModifyUser				"ModifyUser"					//修改用户
#define LogTypePTZTour					"PTZTour"						//巡航路线
#define LogTypeReboot					"Reboot"						//重启
#define LogTypeRecord					"Record"						//录像操作
#define LogTypeSaveConfig				"SaveConfig"					//保存配置
#define LogTypeSetDriverType			"SetDriverType"					//设置驱动器类型
#define LogTypeShutDown					"ShutDown"						//关机
#define LogTypeStorageDeviceError		"StorageDeviceError"			//存储设备出错
#define LogTypeUpdate					"Update"						//更新
#define LogTypeUpgrade					"Upgrade"						//系统升级
#define LogTypeZeroBitrate				"ZeroBitrate"					//无码流
#define LogTypeSaveSystemState			"SaveSystemState"				//保存系统状态
#define LogTypeTimeChanged				"TimeChanged"					//修改时间
#define LogTypeSetTime					"SetTime"						//设置时间


#define JK_OPLogQueryInfo "OPLogQuery"

class OPLogQueryInfo : public JObject
{
public:
	JStrObj		Data;			///< 日志数据
	JIntObj		Position;		///< 从上次查询的结束时的日志指针
	JStrObj		Time;			///< 日志时间
	JStrObj		Type;			///< 日志类型		
	JStrObj		User;			///< 日志用户

public:
    OPLogQueryInfo(JObject *pParent = NULL, const char *szName = JK_OPLogQueryInfo):
    JObject(pParent,szName),
	Data(this, "Data"),
	Position(this, "Position"),
	Time(this, "Time"),
	Type(this, "Type"),
	User(this, "User"){
	};

    ~OPLogQueryInfo(void){};
};

NS_NETSDK_CFG_END