#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_SPVMN "NetWork.SPVMN" 
class NetWork_SPVMN : public JObject
{
public:
	JObjArray<JIntObj>	AlarmLevel; 			//报警等级
	JObjArray<JStrObj>	Alarmid;				//设备中摄像头ID
	JObjArray<JIntObj>	CamreaLevel;			//报警等级
	JObjArray<JStrObj>	Camreaid;				//设备中摄像头ID
	JBoolObj	bCsEnable;						//使能标记
	JIntObj	iHsIntervalTime;					//心跳间隔时间,单位是秒
	JIntObj	iRsAgedTime;						//重新发送注册时间间隔，单位为秒
	JIntObj	sCsPort;							//服务器端口
	JIntObj	sUdpPort;							//本地绑定udp端口
	JStrObj	szConnPass;							//设备接入密码
	JStrObj	szCsIP;								//服务器地址
	JStrObj	szDeviceNO;							//设备序列号
	JStrObj	szServerDn;							//服务器所在的域名称
	JStrObj	szServerNo;							//服务器序列号
	JStrObj	uiAlarmStateBlindEnable;			//屏幕遮挡告警使能
	JStrObj	uiAlarmStateConnectEnable;			//用户连接告警使能
	JStrObj	uiAlarmStateGpinEnable;				//外部报警使能
	JStrObj	uiAlarmStateLoseEnable;				//视频丢失告警使能
	JStrObj	uiAlarmStateMotionEnable;			//视频动态侦测告警使能
	JStrObj	uiAlarmStatePerformanceEnable;		//系统异常告警使能
	JIntObj HeartBeatCount;						//心跳次数

public:
	NetWork_SPVMN(JObject *pParent = NULL, const char *szName = JK_NetWork_SPVMN):
	JObject(pParent,szName),
	AlarmLevel(this, "AlarmLevel"),
	Alarmid(this, "Alarmid"),
	CamreaLevel(this, "CamreaLevel"),
	Camreaid(this, "Camreaid"),
	bCsEnable(this, "bCsEnable"),
	iHsIntervalTime(this, "iHsIntervalTime"),
	iRsAgedTime(this, "iRsAgedTime"),
	sCsPort(this, "sCsPort"),
	sUdpPort(this, "sUdpPort"),
	szConnPass(this, "szConnPass"),
	szCsIP(this, "szCsIP"),
	szDeviceNO(this, "szDeviceNO"),
	szServerDn(this, "szServerDn"),
	szServerNo(this, "szServerNo"),
	uiAlarmStateBlindEnable(this, "uiAlarmStateBlindEnable"),
	uiAlarmStateConnectEnable(this, "uiAlarmStateConnectEnable"),
	uiAlarmStateGpinEnable(this, "uiAlarmStateGpinEnable"),
	uiAlarmStateLoseEnable(this, "uiAlarmStateLoseEnable"),
	uiAlarmStateMotionEnable(this, "uiAlarmStateMotionEnable"),
	uiAlarmStatePerformanceEnable(this, "uiAlarmStatePerformanceEnable"),
	HeartBeatCount(this, "HeartBeatCount"){
	};

	~NetWork_SPVMN(void){};
};

NS_NETSDK_CFG_END