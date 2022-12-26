#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OtherFunction "OtherFunction" 
class OtherFunction : public JObject
{
public:
	JBoolObj DownLoadPause;
	JBoolObj USBsupportRecord;
	JBoolObj SDsupportRecord;
	JBoolObj SupportOnvifClient;
	JBoolObj SupportNetLocalSearch;
	JBoolObj SupportMaxPlayback;
	JBoolObj SupportNVR;
	JBoolObj SupportC7Platform;
	JBoolObj SupportMailTest;
	JBoolObj SupportOSDInfo;
	JBoolObj HideDigital;
	JBoolObj NotSupportAH;							//水平锐度AcutanceHorizontal
	JBoolObj NotSupportAV;							//垂直锐度AcutanceVertial
	JBoolObj SupportBT;								//宽动态BroadTrends
	JBoolObj NotSupportTalk	;						//对讲
	JBoolObj AlterDigitalName;						//支持修改数字通道名称
	JBoolObj SupportShowConnectStatus;
	JBoolObj SupportPlayBackExactSeek;
	JBoolObj TitleAndStateUpload;
	JBoolObj NOHDDRECORD;
	JBoolObj MusicFilePlay;
	JBoolObj SupportSetDigIP;
	JBoolObj SupportShowProductType;
	JBoolObj SupportCamareStyle;
	JBoolObj Supportonviftitle;
	JBoolObj SupportDimenCode;
	JBoolObj SupportStorageNAS;
	JBoolObj ShowFalseCheckTime;
	JBoolObj SupportTimeZone;
	JBoolObj ShowAlarmLevelRegion;
	JBoolObj SupportPOS;							//支持POS
	JBoolObj HddLowSpaceUseMB;						//硬盘空间不足报警用MB
	JBoolObj SupportCustomOemInfo;					//定制OEM客户版本信息
	JBoolObj SupportDigitalEncode;					//数字通道编码配置
	JBoolObj SupportResumePtzState;					//开机恢复云台状态
	JBoolObj SupportSnapCfg;
	JBoolObj SupportAbnormitySendMail;				//存储设备存在及存储异常及存储空间不足发邮件}
	JBoolObj SupportDigitalPre;						//数字通道支持预录
	JBoolObj SupportWriteLog;						//报警页面添加是否写日志勾选框
	JBoolObj SuppportChangeOnvifPort;				//支持修改onvif端口
	JBoolObj SupportCommDataUpload;					//支持串口数据透传
	JBoolObj SupportTextPassword;					//保存可以反解的密码用于onvif鉴权
	JBoolObj SupportCloudUpgrade;
	JBoolObj SupportUserProgram;					//支持客户启动小程序
	JBoolObj SupportModifyFrontcfg;					//
	JBoolObj SupportFTPTest;						//ftp测试
	JBoolObj SupportPtzIdleState;					//云台空闲动作配置
	JBoolObj SupportImpRecord;						//web端是否提供关键录像搜索选项
	JBoolObj SupportCameraMotorCtrl;				//IE端支持机器人马达控制
	JBoolObj SupportEncodeAddBeep;					//设置编码每隔30秒加入beep声
	JBoolObj SupportFishEye;						//鱼眼功能
	JBoolObj SupportSPVMNNasServer;					//安徽超清定制
	JBoolObj SupportSmallChnTitleFont;				//使用12*18的通道标题点阵
	JBoolObj SupportCfgCloudupgrad;					//支持云升级功能配置修改
	JBoolObj SupportStorageFailReboot;
	JBoolObj SupportSplitControl;					//修改DVR预览画面分割
	JBoolObj SupportRTSPClient;						//数字通道连接RTSP前端
	JBoolObj SupportLowLuxMode;						//摄像机是否支持微光模式
	JBoolObj SupportSwitchResolution;				//修改前端数字通道分辨率	
	JBoolObj SupportSlowMotion;						//摄像机是否支持慢动作
	JBoolObj SupportCorridorMode;					//支持走廊模式
	JBoolObj SupportWIFINVR;						//是WIFINVR设备
	JBoolObj SupportSnapSchedule;					//是否支持定时抓图
	JBoolObj SupportPWDSafety;						//是否支持密码找回},
	JBoolObj SupportPlateDetect;					//支持车牌侦测
	JBoolObj SupportBreviary;						//是否支持缩略图
	JBoolObj SupportIntelligentPlayBack;			//是否支持智能快放
	JBoolObj SupportFaceDetect;						//是否支持人脸识别
	JBoolObj SupportDeviceInfoNew;					//是否支持新设备信息
	JBoolObj SupportBallCameraTrackDetect;			//支持球机跟踪识别
	JBoolObj SpecialNight;							//夜间特殊模式控制
	JBoolObj SupportSetHardwareAbility;				//支持设置设备硬件能力集
	JBoolObj SupportSafetyEmail;					//支持通过Email重置密码 
	JBoolObj SupportSensorAbilitySetting;			///支持合封模组支持的sensor等级
	JBoolObj SupportAlarmVoiceTips;
	JBoolObj SupportAlarmLinkLight;	
	JBoolObj SupportSetRtcTime;						//支持Rtc时间校正功能
	JBoolObj SupportAudioFormat;					//支持音频编码
	JBoolObj SupportSoftPhotosensitive;				//软光敏
	JBoolObj SupportCloudUpgradeIPC;
	JBoolObj SupportFileUpgradeIPC;					//支持IE发送文件通过NVR给IPC升级
	JBoolObj SupportParkingGuide;					//支持车位引导功能
	JBoolObj SupportLimitNetLoginUsers;				//限制网络登陆的用户数
	JBoolObj SupportCoaxialParamCtrl;				//同轴参数控制
	JBoolObj SupportShowH265X;						//显示H265X编码
	JBoolObj SupportLogStorageCtrl;					//日志存储控制
	JBoolObj SupportAdminContactInfo;				//支持设置管理员联系方式
	JBoolObj SupportWarnWeakPWD;					//显示弱密码提醒
	JBoolObj SupportStringChangedXPOE;				//支持通道模式显示为XPOE
	JBoolObj SupportAlarmVoiceTipsType;				//支持报警提示音类型修改
	JBoolObj SupportAcrossIPCTalk;					//支持前端IPC对讲
	JBoolObj SupportSetVolume;						//支持设置喇叭音量
	JBoolObj SupportFaceDetectV2;			
	JBoolObj SupportFaceksHumanDetect;				//支持旷视人形检测
	JBoolObj SupportFacekshttpcommunication;		//支持旷视http传输
	JBoolObj SupportFaceRecognition;				//支持人脸识别 
	JBoolObj SupportCustomizeLpRect;				//是否支持任意形状的车位

public:
    OtherFunction(JObject *pParent = NULL, const char *szName = JK_OtherFunction):
    JObject(pParent,szName),
	DownLoadPause(this, "DownLoadPause"),
	USBsupportRecord(this, "USBsupportRecord"),
	SDsupportRecord(this, "SDsupportRecord"),
	SupportOnvifClient(this, "SupportOnvifClient"),
	SupportNetLocalSearch(this, "SupportNetLocalSearch"),
	SupportMaxPlayback(this, "SupportMaxPlayback"),
	SupportNVR(this, "SupportNVR"),
	SupportC7Platform(this, "SupportC7Platform"),
	SupportMailTest(this, "SupportMailTest"),
	SupportOSDInfo(this, "SupportOSDInfo"),
	HideDigital(this, "HideDigital"),
	NotSupportAH(this, "NotSupportAH"),
	NotSupportAV(this, "NotSupportAV"),
	SupportBT(this, "SupportBT"),
	NotSupportTalk(this, "NotSupportTalk"),
	AlterDigitalName(this, "AlterDigitalName"),
	SupportShowConnectStatus(this, "SupportShowConnectStatus"),
	SupportPlayBackExactSeek(this, "SupportPlayBackExactSeek"),
	TitleAndStateUpload(this, "TitleAndStateUpload"),
	NOHDDRECORD(this, "NOHDDRECORD"),
	MusicFilePlay(this, "MusicFilePlay"),
	SupportSetDigIP(this, "SupportSetDigIP"),
	SupportShowProductType(this, "SupportShowProductType"),
	SupportCamareStyle(this, "SupportCamareStyle"),
	Supportonviftitle(this, "Supportonviftitle"),
	SupportDimenCode(this, "SupportDimenCode"),
	SupportStorageNAS(this, "SupportStorageNAS"),
	ShowFalseCheckTime(this, "ShowFalseCheckTime"),
	SupportTimeZone(this, "SupportTimeZone"),
	ShowAlarmLevelRegion(this, "ShowAlarmLevelRegion"),
	SupportPOS(this, "SupportPOS"),
	HddLowSpaceUseMB(this, "HddLowSpaceUseMB"),
	SupportCustomOemInfo(this, "SupportCustomOemInfo"),
	SupportDigitalEncode(this, "SupportDigitalEncode"),
	SupportResumePtzState(this, "SupportResumePtzState"),
	SupportSnapCfg(this, "SupportSnapCfg"),
	SupportAbnormitySendMail(this, "SupportAbnormitySendMail"),
	SupportDigitalPre(this, "SupportDigitalPre"),
	SupportWriteLog(this, "SupportWriteLog"),
	SuppportChangeOnvifPort(this, "SuppportChangeOnvifPort"),
	SupportCommDataUpload(this, "SupportCommDataUpload"),
	SupportTextPassword(this, "SupportTextPassword"),
	SupportCloudUpgrade(this, "SupportCloudUpgrade"),
	SupportUserProgram(this, "SupportUserProgram"),
	SupportModifyFrontcfg(this, "SupportModifyFrontcfg"),
	SupportFTPTest(this, "SupportFTPTest"),
	SupportPtzIdleState(this, "SupportPtzIdleState"),
	SupportImpRecord(this, "SupportImpRecord"),
	SupportCameraMotorCtrl(this, "SupportCameraMotorCtrl"),
	SupportEncodeAddBeep(this, "SupportEncodeAddBeep"),
	SupportFishEye(this, "SupportFishEye"),
	SupportSPVMNNasServer(this, "SupportSPVMNNasServer"),
	SupportSmallChnTitleFont(this, "SupportSmallChnTitleFont"),
	SupportCfgCloudupgrad(this, "SupportCfgCloudupgrad"),
	SupportStorageFailReboot(this, "SupportStorageFailReboot"),
	SupportSplitControl(this, "SupportSplitControl"),
	SupportRTSPClient(this, "SupportRTSPClient"),
	SupportLowLuxMode(this, "SupportLowLuxMode"),
	SupportSwitchResolution(this, "SupportSwitchResolution"),
	SupportSlowMotion(this, "SupportSlowMotion"),
	SupportCorridorMode(this, "SupportCorridorMode"),
	SupportWIFINVR(this, "SupportWIFINVR"),
	SupportSnapSchedule(this, "SupportSnapSchedule"),
	SupportPWDSafety(this, "SupportPWDSafety"),
	SupportPlateDetect(this, "SupportPlateDetect"),
	SupportBreviary(this, "SupportBreviary"),
	SupportIntelligentPlayBack(this, "SupportIntelligentPlayBack"),
	SupportFaceDetect(this, "SupportFaceDetect"),
	SupportDeviceInfoNew(this, "SupportDeviceInfoNew"),
	SupportBallCameraTrackDetect(this, "SupportBallCameraTrackDetect"),
	SpecialNight(this, "SpecialNight"),
	SupportSetHardwareAbility(this, "SupportSetHardwareAbility"),
	SupportSafetyEmail(this, "SupportSafetyEmail"),
	SupportSensorAbilitySetting(this, "SupportSensorAbilitySetting"),
	SupportAlarmVoiceTips(this, "SupportAlarmVoiceTips"),
	SupportAlarmLinkLight(this, "SupportAlarmLinkLight"),
	SupportSetRtcTime(this, "SupportSetRtcTime"),
	SupportAudioFormat(this, "SupportAudioFormat"),
	SupportSoftPhotosensitive(this, "SupportSoftPhotosensitive"),
	SupportCloudUpgradeIPC(this, "SupportCloudUpgradeIPC"),
	SupportFileUpgradeIPC(this, "SupportFileUpgradeIPC"),
	SupportParkingGuide(this, "SupportParkingGuide"),
	SupportLimitNetLoginUsers(this, "SupportLimitNetLoginUsers"),
	SupportCoaxialParamCtrl(this, "SupportCoaxialParamCtrl"),
	SupportShowH265X(this, "SupportShowH265X"),
	SupportLogStorageCtrl(this, "SupportLogStorageCtrl"),
	SupportAdminContactInfo(this, "SupportAdminContactInfo"),
	SupportWarnWeakPWD(this, "SupportWarnWeakPWD"),
	SupportStringChangedXPOE(this, "SupportStringChangedXPOE"),
	SupportAlarmVoiceTipsType(this, "SupportAlarmVoiceTipsType"),
	SupportAcrossIPCTalk(this, "SupportAcrossIPCTalk"),
	SupportSetVolume(this, "SupportSetVolume"),
	SupportFaceDetectV2(this, "SupportFaceDetectV2"),
	SupportFaceksHumanDetect(this, "SupportFaceksHumanDetect"),
	SupportFacekshttpcommunication(this, "SupportFacekshttpcommunication"),
	SupportFaceRecognition(this, "SupportFaceRecognition"),
    SupportCustomizeLpRect(this, "SupportCustomizeLpRect"){
	};

    ~OtherFunction(void){};
};

NS_NETSDK_CFG_END