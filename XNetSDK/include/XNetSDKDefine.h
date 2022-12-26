#pragma once
#ifndef _XNetSDKDefine_H_
#define _XNetSDKDefine_H_
#include "XSDKPublic.h"

typedef struct SXNetSDKInitParam
{
}SXNetSDKInitParam;

#define N_XSDK_IP_MAX_SIZE 128
#define SXSDK_NAME_LEN			32
#define SXSDK_PTZ_PRESETNUM		256
/////////////云台基本控制///////////
#define S_XPTZ_DirectionLeftUp	"DirectionLeftUp"
#define S_XPTZ_DirectionUp		"DirectionUp"
#define S_XPTZ_DirectionRightUp "DirectionRightUp"
#define S_XPTZ_DirectionLeft	"DirectionLeft"
#define S_XPTZ_DirectionRight	"DirectionRight"
#define S_XPTZ_DirectionLeftDown "DirectionLeftDown"
#define S_XPTZ_DirectionDown	"DirectionDown"
#define S_XPTZ_DirectionRightDown "DirectionRightDown"
#define S_XPTZ_IrisSmall	"IrisSmall"
#define S_XPTZ_IrisLarge	"IrisLarge"
#define S_XPTZ_FocusNear	"FocusNear"
#define S_XPTZ_FocusFar		"FocusFar"
#define S_XPTZ_ZoomWide		"ZoomWide"
#define S_XPTZ_ZoomTile		"ZoomTile"
////////////预置点操作///////////
#define S_XPTZ_GotoPreset	"GotoPreset"
#define S_XPTZ_SetPreset	"SetPreset"
#define S_XPTZ_ClearPreset	"ClearPreset"
///////////串口类型/////////////
#define S_XTRANS_COMM_RS232	"RS232"
#define S_XTRANS_COMM_RS485	"RS485"

typedef enum EXSDK_ERROR
{
	EXSDK_ER_OK = 0,
	EXSDK_ER_OBJ_NOT_EXIST = -1239510,
	EXSDK_ER_VALUE_NOT_EXIST = -1239511,
	EXSDK_ER_ERROR = -100000,
	EXSDK_ER_PARAM_ERROR = -99999,
	EXSDK_ER_CREATE_FILE = -99998,
	EXSDK_ER_OPEN_FILE = -99997,
	EXSDK_ER_WRITE_FILE = -99996,
	EXSDK_ER_READ_FILE = -99995,
	EXSDK_ER_NO_SUPPORTED = -99994,
	EXSDK_ER_NET = -99993,					// NET ERROR
	EXSDK_ER_OBJ_EXIST = -99992,
	EXSDK_ER_TIMEOUT = -99991,
	EXSDK_ER_NOT_FOUND = -99990,
	EXSDK_ER_NEW_BUFFER = -99989,
	EXSDK_ER_NET_RECV = -99988,
	EXSDK_ER_NET_SEND = -99987,
	EXSDK_ER_OBJECT_BUSY = -99986,
	EXSDK_ER_SERVER_INTERNAL_ERROR = -99985, //服务器内部错误
	EXSDK_ER_SERVER_BIND_PORT = -99984,		//监听端口bind失败（端口被占用）
	EXSDK_ER_SERVER_LISTEN = -99983,		// 监听服务器启动失败
	EXSDK_ER_NET_SEND_BUF_FULL = -99982,	// 发送缓冲区满了
	EXSDK_ER_NO_BUFFER = -99981,			// 缓冲区大小不够或缓冲区满

	EXSDK_ER_USER_CANCEL = -90000,
	EXSDK_ER_Dev_NotLogin = -90002,			// 设备未登录
	EXSDK_ER_Dev_NotFound = -70119,			// Not Found
	EXSDK_ER_UserOrPassword = -70203,		// 登录设备密码错误
	EXSDK_ER_Illegal_User = -70205,		    // 非法用户
	EXSDK_ER_EE_NET_SOCKET = -1010,			// socket异常
	EXSDK_ER_JSON_PARSE = -69999,			// Json解析异常
}EXSDK_ERROR;

typedef enum EXSDK_UPGRADE_ERROR
{
	EXSDK_ER_NET_OPERATION_UPGRADE_ALAREADY_START = 511,		///< 已经开始升级
	EXSDK_ER_NET_OPERATION_UPGRADE_NOT_START = 512,				///< 未开始升级
	EXSDK_ER_NET_OPERATION_UPGRADE_DATA_ERROR = 513,			///< 升级数据错误
	EXSDK_ER_NET_OPERATION_UPGRADE_FAILED = 514,				///< 升级失败
	EXSDK_ER_NET_OPERATION_UPGRADE_SUCCESS = 515,				///< 升级成功
}EXSDK_UPGRADE_ERROR;

typedef enum ESXSDK_CMD
{
	ESXSDK_MSG_BEGIN = 12000,
	ESXSDK_DEV_LOGIN = 12001,				// 登录结果返回--XSDK_DevLogin

	ESXSDK_MEDIA_START_REAL_PLAY = 12002,	// 实时视频结果返回--XSDK_MediaRealPlay
	ESXSDK_MEDIA_START_FACE_IMAGE = 12003,	// 请求人脸抓图返回--XSDK_MediaGetFaceImage
	ESXSDK_MEDIA_START_RECORD_PLAY = 12004,	// 录像回放结果返回--XSDK_MediaRecordPlay
	ESXSDK_MEDIA_DOWN_RECORD_FILE = 12005,	// 录像下载
	ESXSDK_MEDIA_DOWN_IMAGES_FILE = 12006,	// 图片或缩略图下载
	ESXSDK_MEDIA_START_TALK = 12007,        // 开始对讲回调
	ESXSDK_MEDIA_STOPT_TALK = 12008,        // 结束对讲（服务器内部使用）
	ESXSDK_MEDIA_ON_INFO = 12010,			// 媒体信息回调
	ESXSDK_MEDIA_SET_PARAM = 12011,			// 修改参数
	ESXSDK_MEDIA_START_RECORD_PLAY_BYNAME = 12012,	// 按文件名称进行录像回放

	// 设备协议交互ESXSDK_DEV_GENERAL_COMMAND
	ESXSDK_DEV_GENERAL_COMMAND = 12100,		// 通用交互返回
	ESXSDK_DEV_GET_SYS_CONFIG = 12101,		// 设备系统配置获取
	ESXSDK_DEV_SET_SYS_CONFIG = 12102,		// 设备系统配置设置
	ESXSDK_DEV_GET_CHN_CONFIG = 12103,		// 设备通道配置获取
	ESXSDK_DEV_SET_CHN_CONFIG = 12104,		// 设备通道配置设置
	ESXSDK_DEV_FIND_FILE = 12105,			// 查询录像文件
	ESXSDK_DEV_SNAP = 12106,				// 设备通道抓图
	ESXSDK_DEV_TRANSPORT_OPEN = 12107,		// 打开设备透明串口
	ESXSDK_DEV_TRANSCOMWRITE = 12108,		// 向透明串口发送数据
	ESXSDK_DEV_ON_RECV_TRANSPORT_DATA = 12109,// 接收透明串口返回的数据
	ESXSDK_DEV_ON_SEARCH_CALENDAR = 12110,	// 查询录像日历
	ESXSDK_DEV_FIND_FILE_BYTIME = 12111,	// 按时间查询录像

	ESXSDK_DEV_USER_COMMAND_BEGIN = 12280,	 // 用户自定义消息ID开始
	ESXSDK_DEV_GENERAL_COMMAND_END1 = 12300,// 通用交互返回
	ESXSDK_DEV_GENERAL_COMMAND_END2 = 12499,// 通用交互内部使用

	ESXSDK_ON_DEV_STATE = 12500,			// 设备状态返回，param1参考：EXSDK_DEV_STATE
	ESXSDK_ON_DEV_ALARM_MSG = 1504,			// 设备报警回调消息ID
	ESXSDK_ON_SEARCH_DEVICES = 13001,		// 局域网设备搜索--XSDK_SearchDevices
	ESXSDK_MEDIA_ON_PLAY_STATE = 13002,		// 媒体状态回调
	ESXSDK_MEDIA_PAUSE = 13003,				// 媒体暂停/播放
	ESXSDK_MEDIA_SEEK_TO_TIME = 13004,		// 媒体Seek
	ESXSDK_MEDIA_SET_SPEED = 13005,			// 媒体Seek

	ESXSDK_DEV_UPGRADE = 13006,				// 升级设备返回

	ESXSDK_ON_DAS_SERVER_START = 13007,		// DAS服务器启动结果返回
	ESXSDK_ON_DAS_DEVICE_REGIST = 13008,	// DAS设备注册
	ESXSDK_DEV_SEND_COMMAND = 13009,		// 发送命令

	ESXSDK_DEV_SENDFILE = 13010,			// 发送文件的返回

	ESXSDK_DEV_UPGRADE_CLOUD = 13011,		// 云升级设备


	ESXSDK_DEV_ON_GET_STATE = 13013,		// 获取设备服务状态返回值
	ESXSDK_DEV_UPDATE_DEVSTATUS = 13014,	// 设备服务状态更新回调

	ESXSDK_PTL_DATA_TRANSPORT = 15000,		// 协议数据直接转发

	ESXSDK_DEV_EXPORTFILE = 15001,			// 导出文件数据返回

	ESXSDK_MSG_END = 16000,
}ESXSDK_CMD;

typedef enum ESXSDK_DEV_COMMAND
{
	EXCMD_GENERAL = -1,
	//C1: 登录,登出,保活
	EXCMD_LOGIN_REQ = 1000,
	EXCMD_LOGIN_RSP = 1001,
	EXCMD_LOGOUT_REQ = 1002,
	EXCMD_LOGOUT_RSP = 1003,
	EXCMD_FORCELOGOUT_REQ = 1004,
	EXCMD_FORCELOGOUT_RSP = 1005,
	EXCMD_KEEPALIVE_REQ = 1006,
	EXCMD_KEEPALIVE_RSP = 1007,

	EXCMD_LOGIN_DAS_REQ = 1008,
	EXCMD_LOGIN_DAS_RSP = 1009,

	EXCMD_LOGIN_INFO_ENCRYPT_REQ = 1010,
	EXCMD_LOGIN_INFO_ENCRYPT_RSP = 1011,

	//C2: 系统信息,存储信息
	EXCMD_SYSINFO_REQ = 1020,
	EXCMD_SYSINFO_RSP = 1021,

	//C3: 编码配置, 遮挡,叠加,图像颜色
	//C4: 录像设置
	//C5: 动检,遮挡,视频丢失,外部告警,网络告警,存储告警
	//C6: 通用网络配置,网络服务配置
	//C7: 串口配置
	//C8: 云台配置,预置点,巡航
	//C9: 本地轮巡,TV调解,视频输入,输出,音频输入
	//C10: 通用配置,本地化配置
	//C11: 自动维护
	EXCMD_CONFIG_SET = 1040,
	EXCMD_CONFIG_SET_RSP = 1041,
	EXCMD_CONFIG_GET = 1042,
	EXCMD_CONFIG_GET_RSP = 1043,
	EXCMD_DEFAULT_CONFIG_GET = 1044,
	EXCMD_DEFAULT_CONFIG_GET_RSP = 1045,
	EXCMD_CONFIG_CHANNELTILE_SET = 1046,
	EXCMD_CONFIG_CHANNELTILE_SET_RSP = 1047,
	EXCMD_CONFIG_CHANNELTILE_GET = 1048,
	EXCMD_CONFIG_CHANNELTILE_GET_RSP = 1049,

	EXCMD_CONFIG_CHANNELTILE_DOT_SET = 1050,
	EXCMD_CONFIG_CHANNELTILE_DOT_SET_RSP = 1051,

	//系统调试
	EXCMD_SYSTEM_DEBUG_REQ = 1052,
	EXCMD_SYSTEM_DEBUG_RSP = 1053,
	//OSD三行点阵信息
	EXCMD_CONFIG_OSDINFO_DOT_SET = 1054,
	EXCMD_CONFIG_OSDINFO_DOT_SET_RSP = 1055,

	//C12: 能力级查询
	EXCMD_ABILITY_GET = 1360,
	EXCMD_ABILITY_GET_RSP = 1361,

	//C13: 云台控制
	EXCMD_PTZ_REQ = 1400,
	EXCMD_PTZ_RSP = 1401,

	//C14: 监视控制
	EXCMD_MONITOR_REQ = 1410,
	EXCMD_MONITOR_RSP = 1411,
	EXCMD_MONITOR_DATA = 1412,
	EXCMD_MONITOR_CLAIM = 1413,
	EXCMD_MONITOR_CLAIM_RSP = 1414,

	//C15: 回放控制
	EXCMD_PLAY_REQ = 1420,
	EXCMD_PLAY_RSP = 1421,
	EXCMD_PLAY_DATA = 1422,
	EXCMD_PLAY_EOF = 1423,
	EXCMD_PLAY_CLAIM = 1424,
	EXCMD_PLAY_CLAIM_RSP = 1425,
	EXCMD_DOWNLOAD_DATA = 1426,

	//C16: 语音对讲控制
	EXCMD_TALK_REQ = 1430,
	EXCMD_TALK_RSP = 1431,
	EXCMD_TALK_CU_PU_DATA = 1432,
	EXCMD_TALK_PU_CU_DATA = 1433,
	EXCMD_TALK_CLAIM = 1434,
	EXCMD_TALK_CLAIM_RSP = 1435,
	EXCMD_TALK_NVR_TO_IPC_REQ = 1436, //NVR和其连接的前端开始对讲
	EXCMD_TALK_NVR_TO_IPC_RSP = 1437,

	//C17: 文件查询包括录像文件,图片文件,日志文件
	EXCMD_FILESEARCH_REQ = 1440,
	FILESEARCH_RSP = 1441,
	EXCMD_LOGSEARCH_REQ = 1442,
	EXCMD_LOGSEARCH_RSP = 1443,
	EXCMD_FILESEARCH_BYTIME_REQ = 1444,
	EXCMD_FILESEARCH_BYTIME_RSP = 1445,

	// 查询日历
	EXCMD_FILESEARCH_CALENDAR_REQ = 1446,
	EXCMD_FILESEARCH_CALENDAR_RSP = 1447,

	//C18: 系统管理
	EXCMD_SYSMANAGER_REQ = 1450,
	EXCMD_SYSMANAGER_RSP = 1451,

	// 系统时间和录像模式查询
	EXCMD_TIMEQUERY_REQ = 1452,
	EXCMD_TIMEQUERY_RSP = 1453,

	//C19: 硬盘管理
	EXCMD_DSIKMANAGER_REQ = 1460,
	EXCMD_DSIKMANAGER_RSP = 1461,

	//C20: 用户管理
	EXCMD_FULLAUTHORITYLIST_GET = 1470,
	EXCMD_FULLAUTHORITYLIST_GET_RSP = 1471,
	EXCMD_USERS_GET = 1472,
	EXCMD_USERS_GET_RSP = 1473,
	EXCMD_GROUPS_GET = 1474,
	EXCMD_GROUPS_GET_RSP = 1475,
	EXCMD_ADDGROUP_REQ = 1476,
	EXCMD_ADDGROUP_RSP = 1477,
	EXCMD_MODIFYGROUP_REQ = 1478,
	EXCMD_MODIFYGROUP_RSP = 1479,
	EXCMD_DELETEGROUP_REQ = 1480,
	EXCMD_DELETEGROUP_RSP = 1481,
	EXCMD_ADDUSER_REQ = 1482,
	EXCMD_ADDUSER_RSP = 1483,
	EXCMD_MODIFYUSER_REQ = 1484,
	EXCMD_MODIFYUSER_RSP = 1485,
	EXCMD_DELETEUSER_REQ = 1486,
	EXCMD_DELETEUSER_RSP = 1487,
	EXCMD_MODIFYPASSWORD_REQ = 1488,
	EXCMD_MODIFYPASSWORD_RSP = 1489,

	//C21: 布警/撤警,告警上报
	EXCMD_GUARD_REQ = 1500,
	EXCMD_GUARD_RSP = 1501,
	EXCMD_UNGUARD_REQ = 1502,
	EXCMD_UNGUARD_RSP = 1503,
	EXCMD_ALARM_REQ = 1504,
	EXCMD_ALARM_RSP = 1505,
	EXCMD_NET_ALARM_REQ = 1506,
	EXCMD_NET_ALARM_RSP = 1507,
	EXCMD_ALARMCENTER_MSG_REQ = 1508,

	//C22: 系统升级控制
	EXCMD_UPGRADE_REQ = 1520,
	EXCMD_UPGRADE_RSP = 1521,
	EXCMD_UPGRADE_DATA = 1522,
	EXCMD_UPGRADE_DATA_RSP = 1523,
	EXCMD_UPGRADE_PROGRESS = 1524,
	EXCMD_UPGRADE_INFO_REQ = 1525,
	EXCMD_UPGRADE_INFO_RSQ = 1526,
	EXCMD_UPGRADE_RESULT = 1527, //升级结果通知

	//C23: 设备自动搜索
	EXCMD_IPSEARCH_REQ = 1530,
	EXCMD_IPSEARCH_RSP = 1531,
	EXCMD_IP_SET_REQ = 1532,
	EXCMD_IP_SET_RSP = 1533,

	//C24: 系统信息导入导出
	EXCMD_CONFIG_IMPORT_REQ = 1540,
	EXCMD_CONFIG_IMPORT_RSP = 1541,
	EXCMD_CONFIG_EXPORT_REQ = 1542,
	EXCMD_CONFIG_EXPORT_RSP = 1543,
	EXCMD_LOG_EXPORT_REQ = 1544,
	EXCMD_LOG_EXPORT_RSP = 1545,

	//C25: 网络键盘
	EXCMD_NET_KEYBOARD_REQ = 1550,
	EXCMD_NET_KEYBOARD_RSP = 1551,

	//  网络抓拍
	EXCMD_NET_SNAP_REQ = 1560,
	EXCMD_NET_SNAP_RSP = 1561,

	EXCMD_SET_IFRAME_REQ = 1562,
	EXCMD_SET_IFRAME_RSP = 1563,

	//  透明串口
	EXCMD_RS232_READ_REQ = 1570,
	EXCMD_RS232_READ_RSP = 1571,
	EXCMD_RS232_WRITE_REQ = 1572,
	EXCMD_RS232_WRITE_RSP = 1573,
	EXCMD_RS485_READ_REQ = 1574,
	EXCMD_RS485_READ_RSP = 1575,
	EXCMD_RS485_WRITE_REQ = 1576,
	EXCMD_RS485_WRITE_RSP = 1577,

	EXCMD_TRANSPARENT_COMM_REQ = 1578,
	EXCMD_TRANSPARENT_COMM_RSP = 1579,
	EXCMD_RS485_TRANSPARENT_DATA_REQ = 1580,
	EXCMD_RS485_TRANSPARENT_DATA_RSP = 1581,
	EXCMD_RS232_TRANSPARENT_DATA_REQ = 1582,
	EXCMD_RS232_TRANSPARENT_DATA_RSP = 1583,

	//网络登录时间同步
	EXCMD_SYNC_TIME_REQ = 1590,
	EXCMD_SYNC_TIME_RSP = 1591,
	//ui截图
	EXCMD_PHOTO_GET_REQ = 1600,
	EXCMD_PHOTO_GET_RSP = 1601,

	//上传数据
	EXCMD_UPLOAD_DATA_START_REQ = 1610,
	EXCMD_UPLOAD_DATA_START_RSP = 1611,
	EXCMD_UPLOAD_DATA_STOP_REQ = 1612,
	EXCMD_UPLOAD_DATA_STOP_RSP = 1613,

	//1614 - 1629预留MSG，区分上传数据类型
	EXCMD_VEHICLE_INFO_REQ = 1614,
	EXCMD_VEHICLE_INFO_RSP = 1615,

	EXCMD_RECORD_STATE_REQ = 1616,
	EXCMD_RECORD_STATE_RSP = 1617,

	EXCMD_DIGITCHN_STATE_REQ = 1618,
	EXCMD_DIGITCHN_STATE_RSP = 1619,

	EXCMD_TITLE_INFO_REQ = 1620,
	EXCMD_TITLE_INFO_RSP = 1621,

	//人数统计数据
	EXCMD_CPC_DATA_SEARCH_REQ = 1630,
	EXCMD_CPC_DATA_SEARCH_RSP = 1631,
	EXCMD_CPC_DATA_CLEAR_REQ = 1632,
	EXCMD_CPC_DATA_CLEAR_RSP = 1633,

	//远程搜索
	EXCMD_NET_LOCALSEARCH_REQ = 1634,
	EXCMD_NET_LOCALSEARCH_RSP = 1635,

	//邮件测试
	EXCMD_NET_MAILTEST_REQ = 1636,
	EXCMD_NET_MAILTEST_RSP = 1637,

	//手机信息
	EXCMD_PHONE_INFO_SET = 1638,
	EXCMD_PHONE_INFO_SET_RSP = 1639,

	//硬盘信息
	EXCMD_NET_RECORD_INFO_REQ = 1640,
	EXCMD_NET_RECORD_INFO_RSP = 1641,

	//文件操作，包括删除增加文件夹
	EXCMD_NET_FILE_OPRATE_REQ = 1642,
	EXCMD_NET_FILE_OPRATE_RSP = 1643,

	//默认配置导出，就出厂的默认的配置
	EXCMD_NET_CUSTOM_CFG_EXPORT_REQ = 1644,
	EXCMD_NET_CUSTOM_CFG_EXPORT_RSP = 1645,

	//本地音频文件搜索
	EXCMD_MUSICFILESEARCH_REQ = 1646,
	EXCMD_MUSICFILESEARCH_RSP = 1647,

	//本地音频文件播放控制
	EXCMD_MUSICPLAY_REQ = 1648,
	EXCMD_MUSICPLAY_RSP = 1649,

	EXCMD_AUTHORIZATION_REQ = 1650,
	EXCMD_AUTHORIZATION_RSQ = 1651,

	EXCMD_SET_DIG_IP_REQ = 1652,
	EXCMD_SET_DIG_IP_RSP = 1653,

	//设置OSD信息，提供给客户
	EXCMD_SET_OSD_INFO_REQ = 1654,
	EXCMD_SET_OSD_INFO_RSP = 1655,

	//OSD叠加，用于实时的叠加，不保存配置
	EXCMD_SET_OSD_INFO_REQ_V2 = 1656,
	EXCMD_SET_OSD_INFO_RSP_V2 = 1657,

	//语言导出导入
	EXCMD_EXPORT_LANGUAGE_REQ = 1666,
	EXCMD_EXPORT_LANGUAGE_RSP = 1667,
	EXCMD_IMPORT_LANGUAGE_REQ = 1668,
	EXCMD_IMPORT_LANGUAGE_RSP = 1669,
	EXCMD_DELETE_LANGUAGE_REQ = 1770,
	EXCMD_DELETE_LANGUAGE_RSP = 1771,

	//DDNS Apply aps按键功能
	EXCMD_NET_DDNSAPPLY_REQ = 1774,
	EXCMD_NET_DDNSAPPLY_RSP = 1775,
	//DDNS 外网IP地址消息(APS客户定制)
	EXCMD_NET_DDNSIPADDRESS_REQ = 1776,
	EXCMD_NET_DDNSIPADDRESS_RSP = 1777,

	//云升级控制
	EXCMD_CLOUD_VERSION_REQ = 2000,
	EXCMD_CLOUD_VERSION_RSP = 2001,
	EXCMD_CLOUD_UPGRADE_START_REQ = 2002,
	EXCMD_CLOUD_UPGRADE_START_RSP = 2003,
	EXCMD_CLOUD_UPGRADE_STOP_REQ = 2004,
	EXCMD_CLOUD_UPGRADE_STOP_RSP = 2005,
	EXCMD_CLOUD_UPGRADE_PROGRESS = 2006,

	//FTP
	EXCMD_NET_FTPTEST_REQ = 2008,
	EXCMD_NET_FTPTEST_RSP = 2009,
	//对讲恢复音频开关
	EXCMD_TLAK_ONLY_RECVCONFIG_REQ = 2010,
	EXCMD_TLAK_ONLY_RECVCONFIG_RSP = 2011,

	//设置录像指示灯状态
	EXCMD_FB_EXTRA_STATE_REQ = 2012,
	EXCMD_FB_EXTRA_STATE_RSP = 2013,

	//获取录像指示灯状态
	EXCMD_FB_EXTRA_GET_STATE_REQ = 2014,
	EXCMD_FB_EXTRA_GET_STATE_RSP = 2015,
	EXCMD_CLOUD_NEW_VERSION_REQ = 2016,		//新版本客户端使用该命令查询版本信息
	EXCMD_CLOUD_NEW_VERSION_RSP = 2017,
	EXCMD_CLOUD_NEW_UPGRADE_START_REQ = 2018,
	EXCMD_CLOUD_NEW_UPGRADE_START_RSP = 2019,


	EXCMD_NET_SPLIT_CONTROL_REQ = 2020,
	EXCMD_NET_SPLIT_CONTROL_RSP = 2021,

	EXCMD_CONSUMER_STATE_UPLOAD_REQ = 2022,
	EXCMD_CONSUMER_STATE_UPLOAD_RSP = 2023,

	EXCMD_ELECT_STATE_REQ = 2024,
	EXCMD_ELECT_STATE_RSP = 2025,

	//鱼眼校准圆心
	EXCMD_NET_FISHEYE_MODIFY_CENTER_REQ = 2026,
	EXCMD_NET_FISHEYE_MODIFY_CENTER_RSP = 2027,

	EXCMD_NET_FILE_BACKUP_REQ = 2030,	//备份到u盘控制
	EXCMD_NET_FILE_BACKUP_RSP = 2031,

	//设置一种语言
	EXCMD_SET_SUPPORT_LANGUAGE_REQ = 2036,
	EXCMD_SET_SUPPORT_LANGUAGE_RSP = 2037,

	EXCMD_GET_BREVIARY_PIC_REQ = 2038,  // 录像缩略图请求
	EXCMD_GET_BREVIARY_PIC_RSP = 2039,  // 录像缩略图请求返回
	EXCMD_GET_BREVIARY_PIC_DATA_RSP = 2140,// 录像缩略图数据返回

	EXCMD_MUSICBOX_STATE_REQ = 2050,
	MUSICBOX_STATE_RSP = 2051,

	EXCMD_FACE_IMAGE_GET_REQ = 2060,
	EXCMD_FACE_IMAGE_GET_RSP = 2061,

	EXCMD_FACE_IMAGE_CLAIM_REQ = 2062,
	EXCMD_FACE_IMAGE_CLAIM_RSP = 2063,
	EXCMD_FACE_IMAGE_DATA = 2064,

	// 智能分析上报的子链接保活(普通的连接可能没有)
	// 让服务器那边确认设备子链接是否还存在,不需要回复
	EXCMD_INTEL_ANALYSE_OPT_KEEPALIVE = 2066,
	EXCMD_INTEL_ANALYSE_OPT_KEEPALIVE_RSP = 2067,

	//获取设备信息：1.录像情况 2.设备连接信号情况 3.连接人数 4.设备版本信息
	EXCMD_DEVICE_INFORMATION_REQ = 2088,
	EXCMD_DEVICE_INFORMATION_RSP = 2089,

	EXCMD_EXTERNAL_SENSOR_OPERATE_REQ = 2128,

	// 订阅巡航上报结束
	EXCMD_PTZ_TOUR_END_RSP = 2141,

	//图片导入基本操作
	EXCMD_INTEL_FACE_PIC_IMPORT_REQ = 2170,			//图片导入请求
	EXCMD_INTEL_FACE_PIC_IMPORT_RSP = 2171,
	EXCMD_INTEL_FACE_PICDATA_IMPORT_REQ = 2172,		//图片数据导入
	EXCMD_INTEL_FACE_PICDATA_IMPORT_RSP = 2173,
	EXCMD_INTEL_FACE_IMPORT_RESULT_REQ = 2174,		//导入图片结果请求
	EXCMD_INTEL_FACE_IMPORT_RESULT_RSP = 2175,
	EXCMD_INTEL_FACE_EXPORT_RESULT_REQ = 2176,		//导出所有结果
	EXCMD_INTEL_FACE_EXPORT_RESULT_RSP = 2177,
	EXCMD_INTEL_FACE_DATA_WRITE_RSP = 2178,			//数据写FPGA返回和2172和2173对应	

	//云升级IPC控制
	EXCMD_CLOUD_IPC_VERSION_REQ = 2250,		//IPC版本查询请求
	EXCMD_CLOUD_IPC_VERSION_RSP = 2251,		//IPC版本查询应答
	EXCMD_CLOUD_IPC_UPGRADE_START_REQ = 2252,		//云升级IPC开始 请求
	EXCMD_CLOUD_IPC_UPGRADE_START_RSP = 2253,		//云升级IPC开始 应答
	EXCMD_CLOUD_IPC_UPGRADE_STOP_REQ = 2254,		//云升级IPC结束 请求
	EXCMD_CLOUD_IPC_UPGRADE_STOP_RSP = 2255,		//云升级IPC结束 应答
	EXCMD_CLOUD_IPC_DOWNLOAD_PROGRESS = 2256,		//云升级IPC下载进度
	EXCMD_CLOUD_IPC_UPGRADE_PROGRESS = 2257,		//云升级IPC进度
	EXCMD_CLOUD_IPC_UPGRADE_RESULT = 2258, 		//云升级IPC结果通知

	//IE发送文件升级IPC控制
	EXCMD_FILE_UPGRADE_IPC_INFO_REQ = 2260,		//前端IPC当前版本信息请求
	EXCMD_FILE_UPGRADE_IPC_INFO_RSP = 2261,		//前端IPC当前版本信息响应
	EXCMD_FILE_UPGRADE_IPC_REQ = 2262,			//升级IPC请求
	EXCMD_FILE_UPGRADE_IPC_RSP = 2263,			//升级IPC响应
	EXCMD_FILE_UPGRADE_IPC_DATA = 2264,			//发送升级IPC的数据包
	EXCMD_FILE_UPGRADE_IPC_DATA_RSP = 2265,		//数据包响应
	EXCMD_FILE_UPGRADE_IPC_PROGRESS = 2266,		//升级进度
	EXCMD_FILE_UPGRADE_IPC_RESULT = 2267,		//升级结果通知


	//获取对应通道支持那些智能（PEA ，OSC，AVD）
	EXCMD_NET_GET_DEVICE_INTELL_ABILITY_REQ = 2270,
	EXCMD_NET_GET_DEVICE_INTELL_ABILITY_RSP = 2271,

	//获取对应通道智能配置
	EXCMD_NET_GET_DEVICE_INTELL_INFO_REQ = 2272,
	EXCMD_NET_GET_DEVICE_INTELL_INFO_RSP = 2273,

	//设置对应通道智能配置	
	EXCMD_NET_SET_DEVICE_INTELL_INFO_REQ = 2274,
	EXCMD_NET_SET_DEVICE_INTELL_INFO_RSP = 2275,

	//设置任意通道配置
	EXCMD_NET_SET_DEVICE_INTELL_ALL_INFO_REQ = 2276,
	EXCMD_NET_SET_DEVICE_INTELL_ALL_INFO_RSP = 2277,

	EXCMD_MODEINDEX_UPLOAD_REQ = 3014,

	EXCMD_FACE_RECOGNITION_OPT_DATA = 3016,

	//发送文件数据到设备
	EXCMD_FILE_TRANS_REQ = 3500,
	EXCMD_FILE_TRANS_RSP = 3501,
	EXCMD_FILE_DATA_SEND_REQ = 3502,
	EXCMD_FILE_DATA_SEND_RSP = 3503,
	EXCMD_FILE_DATA_RECV_REQ = 3504,		//web端接收文件,设备端发送
	EXCMD_FILE_DATA_RECV_RSP = 3505,

	//手机端使用
//	EXCMD_GENERALSTATE_UPLOAD_REQ = 3016,  //通用状态上报
//	EXCMD_GENERALSTATE_UPLOAD_RSP = 3017,
EXCMD_GET_LOGIN_ENCRYPTION_TYPE = 99999,//获取设备登录密码加密类型
}ESXSDK_DEV_COMMAND;

// 设备状态枚举
typedef enum ESDK_STATE_DEV
{
	ESTATE_DEV_Destory = -500,		// 对像被销毁
	ESTATE_DEV_None = 0,
	ESTATE_DEV_NetDisConnect = 2,	// 设备断线
	ESTATE_DEV_Logined = 6,			// 设备登录成功
}ESDK_STATE_DEV;

// 通道状态枚举
typedef enum EMediaChnState
{
	EState_Media_NetDisConnect = 2,	// 通道断线
	EState_Media_NetConnecting = 3,	// 正在连接
	EState_Media_NetConnected = 4,	// 网络连接成功
	EState_Media_RecvData = 8,		// 正在接收数据
	EState_Media_DataEnd = 9,		// 数据接收结束
}EMediaChnState;

typedef enum EUpgradeStep
{
	EUpgradeStep_Down = 1,
	// 进度0~100:	下载升级文件过程（通过服务器升级）

	EUpgradeStep_SendFile = 2,
	// 进度0~100:	发送文件进度（发送升级包到设备）

	EUpgradeStep_SendFile_Complete = 3,
	// 进度0:	发送文件完成

	EUpgradeStep_Upgrade = 4,
	// 进度0~100:   升级过程进度
	// 进度515:		升级完成，需要重启

	EUpgradeStep_Upgrade_Complete = 5,
	// 进度0:		升级完成

	EUpgradeStep_Complete = 6,
	// 进度1:   升级过程结束等待设备重启
	// 进度50:  设备正在重启
	// 进度100: 设备重启成功
	// 小于0:   失败错误返回
}EUpgradeStep;

////////////////////////////About Device////////////////////////////
//IP addr
typedef union _SXSDK_IPAddress
{
	unsigned char	c[4];
	unsigned short	s[2];
	unsigned int 	l;
}SXSDK_IPAddress;

typedef enum SDK_DevType
{
	SDK_DEV_TYPE_IPC,
	SDK_DEV_TYPE_DVR,
	SDK_DEV_TYPE_HVR,
	SDK_DEV_TYPE_POEIPC,
	SDK_DEV_TYPE_NVR,
	SDK_DEV_TYPE_RTSPIPC,
	SDK_DEV_TYPE_NR
}SDK_DevType;

////!普通网络设置 --
typedef struct SXSDK_CONFIG_NET_COMMON
{
	//!主机名
	char HostName[64];
	//!主机IP
	SXSDK_IPAddress HostIP;
	//!子网掩码
	SXSDK_IPAddress Submask;
	//!网关IP
	SXSDK_IPAddress Gateway;
	char pLocalLinkAddr[32];	//本地链路地址
	char pAddr[64];				//ipv6地址
	char DefaultUser[8];		///< 默认随机用户名
	char DefaultPwd[10];		///< 默认密码随机
	char pGateway[64];
	//!HTTP服务端口
	int HttpPort;
	//!TCP侦听端口
	int TCPPort;
	//!SSL侦听端口
	int SSLPort;
	//!UDP侦听端口
	int UDPPort;
	//!最大连接数
	int MaxConn;
	//!监视协议 {"TCP","UDP","MCAST",…}
	int MonMode;
	//!限定码流值
	int MaxBps;
	int  TransferPlan;			///传输策略
	bool bUseHSDownLoad;		///是否启用高速录像下载测率
	char sMac[64];				///MAC地址
	char sSn[64]; 				///序列号
	int  DeviceType;   			///设备类型,手机区分是插座还是普通设备

	int ChannelNum;				///通道数
	int	Device_Type;			///设备类型，见enum SDK_DevType
	char Version[64];			//版本信息
	char BuildDate[64];  			//版本日期
	char OtherFunction[49];		///用来保存修改其它厂家IP所需信息 
	char Manufacturer;			///设备生产商，见枚举SDK_Manufacturer
	char Resume[6];				///保留
}SXSDK_CONFIG_NET_COMMON;

////跨网段修改IP
typedef struct SXSDK_CONFIG_NET_COMMON_V2
{
	char HostName[64];						///主机名 
	SXSDK_IPAddress HostIP;					///主机IP
	SXSDK_IPAddress Submask;				///子网掩码
	SXSDK_IPAddress Gateway;				///网关IP  
	int  HttpPort;							///HTTP服务端口   
	int  TCPPort;							///TCP侦听端口   
	int  SSLPort;							///SSL侦听端口
	int  UDPPort;							///UDP侦听端口  
	int  MaxConn;							///最大连接数
	int  MonMode;							///监视协议 {"TCP","UDP","MCAST",…}
	int  MaxBps;							///限定码流值
	int  TransferPlan;						///传输策略
	bool bUseHSDownLoad; 					///是否启用高速录像下载测率
	char sMac[64];							///MAC地址
	char UserName[64];						///设备用户名
	char Password[64];						///设备密码
	char LocalMac[64];
	int  nPasswordType;
	char Resume[92];						///保留
}SXSDK_CONFIG_NET_COMMON_V2;

typedef struct SXSDK_DevAttr
{
	int AliveInterval;
	int ChannelNum;
	char DeviceType[64];
	int ExtraChannel;
	int nTotalChnCount;
}SXSDK_DevAttr;


////////Login////////
typedef enum EDEV_CNN_TYPE
{
	EDEV_CNN_TYPE_UNKOWN = -1,
	EDEV_CNN_TYPE_IP_DNS = 0,
	EDEV_CNN_TYPE_DAS = 1,
	EDEV_CNN_TYPE_P2P = 2,
	EDEV_CNN_TYPE_RPS = 3,
	EDEV_CNN_TYPE_SDK = 4,
	EDEV_CNN_TYPE_AUTO = 100,
}EDEV_NET_TYPE;

typedef struct SXSDKLoginParam
{
	char sDevId[128]; // ip/dns/sn
	int  nDevPort;
	char sUserName[64];
	char sPassword[64];
	EDEV_NET_TYPE  nCnnType;
}SXSDKLoginParam;

typedef struct SXSDKDASDeviceInfo
{
	char sDevIP[64];
	int  nDevPort;
	int  nChannelNum;
	char sDevId[128];
	char sDevType[64];
	char sUserName[64];
	char sPassword[64];
	char sEncryptType[64];
	char sRes[512];
}SXSDKDASDeviceInfo;

// 录像相关参数
#define  EMFileType_mp4     "mp4"			//MP4录像
#define  EMFileType_jpg     "jpg"			//图片
#define  EMFileType_idximg  "idximg"		//索引图片
#define  EMFileType_recod   "h264"			//录像

#define  EMFileSubType_ALL		"*"			// 全部录像或抓图
#define  EMFileSubType_ALARM	"A"			// 报警录像或抓图
#define  EMFileSubType_DETECT	"M"			// 动检报警录像或抓图
#define  EMFileSubType_HANDLE	"H"			// 手动录像或手动抓图
#define  EMFileSubType_KEY		"K"			// 关键录像或关键抓图
#define  EMFileSubType_URGENT		"V"		// 紧急录像
#define  EMFileSubType_ORIGINAL		"R"		// 原始录像
#define  EMFileSubType_INDUCTION	"P"		// 感应图片
typedef struct SXSDKQueryRecordReq
{
	int nChannel;
	int nStreamType;		// 0:Main 1:SubStream
	char sBeginTime[32];	// YYYY-MM-DD HH:mm:SS	
	char sEndTime[32];		// YYYY-MM-DD HH:mm:SS	
	char sFileType[32];
	char sFileSubType[32];
}SXSDKQueryRecordReq;

typedef struct SXSDKQueryRecordRes
{
	int nChannel;
	int nFileLength;
	int nDiskNo;
	int nSerialNo;
	int nStreamType;
	char sFileType[32];
	char sFileSubType[32];
	char sBeginTime[32];	// YYYY-MM-DD HH:mm:SS	
	char sEndTime[32];		// YYYY-MM-DD HH:mm:SS	
	char sFileName[128];	// 文件名称	
}SXSDKQueryRecordRes;

///查询录像日历
typedef struct SXSDKSearchCalendarReq
{
	int year;
	int month;
	char fileType[8];			/// 查询文件类型h264, jpg, idximg, *
	char sEvent[8];				/// 查询事件类型 (普通，报警)
	char rev[16];
}SXSDKSearchCalendarReq;

typedef struct SXSDKSearchCalendarRes
{
	int mask;					/// 掩码
}SXSDKSearchCalendarRes;

///按时间查询录像对应每一分钟
typedef struct  SXSDKSearchByTimeReq
{
	int nHighChannel;				///< 33~64录像通道号掩码
	int nLowChannel;				///< 1~32录像通道号掩码
	char sFileType[32];
	char sFileSubType[32];
	char sBeginTime[32];			///< YYYY-MM-DD HH:mm:SS	
	char sEndTime[32];				///< YYYY-MM-DD HH:mm:SS	
	char nHighStreamType[32];		///< 33~64录像的码流类型,二进制位为0代表主码流，1代表辅码流
	char nLowStreamType[32];		///< 1~32录像的码流类型,二进制位为0代表主码流，1代表辅码流
	int  iSync;						///< 是否需要同步
} SXSDKSearchByTimeReq;

//每个通道的录像信息
typedef struct SXSDKSearchByTimeInfo
{
	int iChannel;			    ///< 录像通道号
	///< 录像记录用720个字节的5760位来表示一天中的1440分钟
	///< 0000:无录像 0001:F_COMMON 0002:F_ALERT 0003:F_DYNAMIC 0004:F_CARD 0005:F_HAND
	unsigned char cRecordBitMap[720];
}SXSDKSearchByTimeInfo;

typedef struct SXSDKSearchByTimeRes
{
	int nInfoNum;									///< 通道的录像记录信息个数
	SXSDKSearchByTimeInfo ByTimeInfo[64];			///< 通道的录像记录信息
}SXSDKSearchByTimeRes;

////////Device PTZ////////
typedef enum SXSDK_PTZ_ControlType
{
	SXSDK_PTZ_UP_CONTROL = 0,			//up
	SXSDK_PTZ_DOWN_CONTROL,				//down
	SXSDK_PTZ_LEFT_CONTROL,				//left
	SXSDK_PTZ_RIGHT_CONTROL,			//right
	SXSDK_PTZ_ZOOM_ADD_CONTROL,			//zoom+
	SXSDK_PTZ_ZOOM_DEC_CONTROL,			//zoom- 
	SXSDK_PTZ_FOCUS_ADD_CONTROL,		//focus+ 
	SXSDK_PTZ_FOCUS_DEC_CONTROL,		//focus- 
	SXSDK_PTZ_APERTURE_ADD_CONTROL,		//aperture+ 
	SXSDK_PTZ_APERTURE_DEC_CONTROL,		//aperture-
	SXSDK_PTZ_POINT_MOVE_CONTROL,		//move to preset
	SXSDK_PTZ_POINT_SET_CONTROL,		//set
	SXSDK_PTZ_POINT_DEL_CONTROL,		//delete
	SXSDK_PTZ_POINT_LOOP_CONTROL,		//tour in presets 
	SXSDK_PTZ_LAMP_CONTROL,             //lamp and wiper
	SXSDK_EXTPTZ_LEFTTOP,				//left-up
	SXSDK_EXTPTZ_RIGHTTOP,				//right-up
	SXSDK_EXTPTZ_LEFTDOWN,				//left-down 
	SXSDK_EXTPTZ_RIGHTDOWN,				//right-down 
}SXSDK_PTZ_ControlType;


typedef struct SXSDK_PRESET_INFO
{
	unsigned char 	ucChannel;					//channel
	unsigned char 	ucPresetID;					//preset No. 
	unsigned char	iSpeed;						//preset speed speed 1~15 level
	unsigned char	iDWellTime;					//preset delay time 1~255 
	unsigned char	szPresetName[SXSDK_NAME_LEN];		//preset name
}SXSDK_PRESET_INFO;

typedef struct  SXSDK_PTZ_PRESET_SCHEDULE
{
	unsigned int dwSize;
	unsigned int dwCount;
	SXSDK_PRESET_INFO	struPreset[SXSDK_PTZ_PRESETNUM];
}SXSDK_PTZ_PRESET_SCHEDULE;
#define	SXSDK_DEV_PRESET_CFG			90		//configure of PTZ preset


////////////////////////////About Media////////////////////////////
typedef enum EXSDK_DATA_FORMATE
{
	EXSDK_DATA_FORMATE_NULL = 0x80000000,	// 数据不回调（只需要显示或解码）
	EXSDK_DATA_FORMATE_NONE = 0,			// 数据以原数据回调（带私有头）
	EXSDK_DATA_FORMATE_FRAME = 103,			// 数据按帧格式回调
	EXSDK_DATA_MEDIA_ON_PLAY_STATE = ESXSDK_MEDIA_ON_PLAY_STATE,// 媒体状态回调EMediaChnState
	EXSDK_DATA_FORMATE_FACE_IMAGE = 2064,						// 人脸识别图片
}EXSDK_DATA_FORMATE;

#define XSDK_SAMPLE_FREQ_4000	1
#define XSDK_SAMPLE_FREQ_8000	2
#define XSDK_SAMPLE_FREQ_11025	3
#define XSDK_SAMPLE_FREQ_16000	4
#define XSDK_SAMPLE_FREQ_20000	5
#define XSDK_SAMPLE_FREQ_22050	6
#define XSDK_SAMPLE_FREQ_32000	7
#define XSDK_SAMPLE_FREQ_44100	8
#define XSDK_SAMPLE_FREQ_48000	9

// Frame Type:  
#define XSDK_FRAME_TYPE_UNKNOWN			0
#define XSDK_FRAME_TYPE_VIDEO			1
#define XSDK_FRAME_TYPE_AUDIO			2
#define XSDK_FRAME_TYPE_DATA			3

// Sub Type:
#define XSDK_FRAME_TYPE_VIDEO_I_FRAME	0
#define XSDK_FRAME_TYPE_VIDEO_P_FRAME	1
#define XSDK_FRAME_TYPE_VIDEO_B_FRAME	2
#define XSDK_FRAME_TYPE_VIDEO_S_FRAME	3
#define XSDK_FRAME_TYPE_DATA_TEXT		5
#define XSDK_FRAME_TYPE_DATA_INTL		6

// Encode type:
#define XSDK_ENCODE_UNKNOWN				0
#define XSDK_ENCODE_VIDEO_MPEG4			1
#define XSDK_ENCODE_VIDEO_H264			2
#define XSDK_ENCODE_VIDEO_H265			3
#define XSDK_ENCODE_VIDEO_JPEG          0xF2
#define XSDK_ENCODE_VIDEO_SVAC          5
#define XSDK_ENCODE_VIDEO_SVAC_NEW      6
#define XSDK_ENCODE_AUDIO_PCM8			7	// 8BITS,8K
#define XSDK_ENCODE_AUDIO_G729			8
#define XSDK_ENCODE_AUDIO_IMA			9
#define XSDK_ENCODE_AUDIO_PCM_MULAW		10
#define XSDK_ENCODE_AUDIO_G721			11
#define XSDK_ENCODE_AUDIO_PCM8_VWIS		12	// 16BITS,8K
#define XSDK_ENCODE_AUDIO_ADPCM			13	// 16BITS,8K/16K
#define XSDK_ENCODE_AUDIO_G711A			14	// 16BITS,8K
#define XSDK_ENCODE_AUDIO_AAC			15
#define XSDK_ENCODE_AUDIO_AAC2          16
#define XSDK_ENCODE_AUDIO_G711U			22
#define XSDK_ENCODE_AUDIO_TALK          30
#define XSDK_ENCODE_AUDIO_MP4			100
#define XSDK_ENCODE_YUV420				0x1000000

typedef struct SXSDK_FRAME_INFO
{
	unsigned char* pHeader;				//码流数据带有私有头
	unsigned char* pContent;			//码流数据去除私有头
	int nLength;						//对应pHeader的长度
	int nFrameLength;					//对应pContent的长度

	int nType;							//对应上面的Frame Type
	int nSubType;						//对应上面的SubType

	int nEncodeType; 					//对应上面的Encode type。例如MPEG4/H264, PCM, MSADPCM, etc.

	int nYear;							//此帧的年、月、日、时、分、秒
	int nMonth;
	int nDay;
	int nHour;
	int nMinute;
	int nSecond;
	uint64 nTimeStamp;					//此帧时间戳（毫秒）

	int  nFrameRate;					//视频帧率
	int	 nWidth;						//视频的宽高
	int	 nHeight;

	int nChannels;						//音频的通道
	int nBitsPerSample;					//采样的位深
	int nSamplesPerSecond;				//采样率

	int nParam1;						// 扩展用
	int nParam2;						// 扩展用
	uint64 nPos;
}SXSDK_FRAME_INFO;

/////////////////////////////////////////////////////////
typedef struct SXSDK_IA_COMM_RES_S
{
	char resultType; 		//识别类型类型  0:车牌  1:人脸识别  
	char picSubType; 		//0:大图  1:小图 2:一组图片传输完成
	char picFormat;  		//0:jpg  1:bmp   2:yuv
	char tagNum;			//目标个数
	unsigned int framID;	//帧ID
	unsigned int tagsec;	//事件发生时的时间秒
	unsigned int tagusec;	//事件发生时的时间微妙
	char channel;
	char reserved[3];
}SXSDK_IA_COMM_RES_S;

typedef struct SXSDK_FACE_DETECT		//人脸信息
{
	char sex;//性别
	char age;//年龄
	char resv[26];
}SXSDK_FACE_DETECT;

typedef struct SXSDK_RECT_S
{
	int leftX;
	int topY;
	int width;
	int height;
} SXSDK_RECT_S;

typedef struct SXSDK_FR_TARGET_INFO	//人脸检测
{
	SXSDK_RECT_S stRect;
	SXSDK_FACE_DETECT face;
	char resv[12];
}SXSDK_FR_TARGET_INFO;

typedef struct SDK_IA_FR_REC_S		//人脸检测
{
	SXSDK_IA_COMM_RES_S comm;
	int index;						//当前图片的索引号
	SXSDK_FR_TARGET_INFO info;		// FR_TARGET_INFO
}SXSDK_IA_FR_REC_S;


typedef enum EDASUserCheck
{
	EDASUserCheck_UserPwd = 0,			// 通过用户名或密码校验
	EDASUserCheck_Def_UserAndPwd = 1,	// 用户名为DeviceSN，Password为设备SN+ID==>md5
}EDASUserCheck;

typedef enum EXSDK_ATTR_Inside
{
	EXSDK_ATTR_ENABLE_PTL_ENCODE = 1024,	// 启用/关闭设备协议加密功能
	EXSDK_Str_ATTR_DevAttr_Type = 1025,		// 获取设备类型（返回字符串）
	EXSDK_Int_ATTR_DevAttr_Chnnel = 1026,	// 获取设备总通道数

	EXSDK_ATTR_Set_DASCheckType = 1030,		// EDASUserCheck_UserPwd说明:使用用户名和密码(默认)
											// EDASUserCheck_Def_UserAndPwd说明:
											//    a)用户名：设备SN
											//    b)密码为：用户名+"@"+ID生成的md5值
											//    c)ID为空时，改为SN
											//    d)第一次注册时，SDK按上述规则进行自行修改
											//     （用户只配置下ID和DAS服务器信息即可）
}EXSDK_ATTR_Inside;

// 上报方式枚举
typedef enum ENUM_GPS_METHOD
{
	GPS_METHOD_None = -1,
	GPS_METHOD_Timing = 0,// 定时上报
	GPS_METHOD_Intell,// 智能上报
	GPS_METHOD_Change,// 变化上报
}ENUM_GPS_METHOD;

typedef struct SXSDK_GPSConfig
{
	bool bEnable;
	int nMethod;
	int nInterval;
	int nDistance;
	int nAcceleration;
}SXSDK_GPSConfig;

typedef struct SXSDK_Version
{
	char sVersion[64];			//SDK版本号
	char sCompileTime[64];  	//SDK编译版本日期
}SXSDK_Version;

/// 存储设备控制类型
enum XSDK_StorageDeviceControlTypes
{
	XSDK_STORAGE_DEVICE_CONTROL_SETTYPE,		///< 设置类型
	XSDK_STORAGE_DEVICE_CONTROL_RECOVER,		///< 恢复错误
	XSDK_STORAGE_DEVICE_CONTROL_PARTITIONS,		///< 分区操作
	XSDK_STORAGE_DEVICE_CONTROL_CLEAR,			///< 清除操作
};

/// 清除磁盘数据类型
enum XSDK_StorageDeviceClearTypes
{
	XSDK_STORAGE_DEVICE_CLEAR_DATA,			///< 清除录像数据
	XSDK_STORAGE_DEVICE_CLEAR_PARTITIONS,	///< 清除分区
};

/// 驱动器类型
enum XSDK_FileSystemDriverTypes
{
	XSDK_DRIVER_READ_WRITE,		///< 读写驱动器
	XSDK_DRIVER_READ_ONLY,		///< 只读驱动器
	XSDK_DRIVER_EVENTS,			///< 事件驱动器
	XSDK_DRIVER_REDUNDANT,		///< 冗余驱动器
	XSDK_DRIVER_SNAPSHOT,		///< 快照驱动器
};

/// 存储设备控制
typedef struct XSDK_StorageDeviceControl
{
	int iAction;		///< 见enum SDK_StorageDeviceControlTypes
	int iSerialNo;		///< 磁盘序列号
	int iPartNo;		///< 分区号
	int iType;			///< enum XSDK_StorageDeviceClearTypes或者XSDK_FileSystemDriverTypes
	int iPartSize[4];	///< 各个分区的大小
}XSDK_StorageDeviceControl;

typedef struct XSDK_LatticeInfo
{
	unsigned char MatrixData[64 * 24 * 24];		//支持最多64个字符，单个字符最大的点阵格式24 * 24
	int iWidth;									//总字符宽
	int iHeight;								//总字符高
}XSDK_LatticeInfo;

// 编码格式配置
typedef enum ESDK_CAPTURE_SIZE
{
	SDK_CAPTURE_SIZE_D1,		///< 720*576(PAL)	720*480(NTSC)   800*480
	SDK_CAPTURE_SIZE_HD1,		///< 352*576(PAL)	352*480(NTSC)
	SDK_CAPTURE_SIZE_BCIF,		///< 720*288(PAL)	720*240(NTSC)
	SDK_CAPTURE_SIZE_CIF,		///< 352*288(PAL)	352*240(NTSC)
	SDK_CAPTURE_SIZE_QCIF,		///< 176*144(PAL)	176*120(NTSC)
	SDK_CAPTURE_SIZE_VGA,		///< 640*480(PAL)	640*480(NTSC)
	SDK_CAPTURE_SIZE_QVGA,		///< 320*240(PAL)	320*240(NTSC)
	SDK_CAPTURE_SIZE_SVCD,		///< 480*480(PAL)	480*480(NTSC)
	SDK_CAPTURE_SIZE_QQVGA,		///< 160*128(PAL)	160*128(NTSC)
	SDK_CAPTURE_SIZE_ND1 = 9,   ///< 240*192
	SDK_CAPTURE_SIZE_650TVL,    ///< 926*576
	SDK_CAPTURE_SIZE_720P,      ///< 1280*720
	SDK_CAPTURE_SIZE_1_3M,      ///< 1280*960
	SDK_CAPTURE_SIZE_UXGA,     ///< 1600*1200
	SDK_CAPTURE_SIZE_1080P,     ///< 1920*1080
	SDK_CAPTURE_SIZE_WUXGA,     ///< 1920*1200
	SDK_CAPTURE_SIZE_2_5M,      ///< 1872*1408
	SDK_CAPTURE_SIZE_3M,        ///< 2048*1536
	SDK_CAPTURE_SIZE_5M,        ///< 3744*1408
	SDK_CAPTURE_SIZE_NR = 19,
	SDK_CAPTURE_SIZE_1080N = 19,///< 960*1080
	SDK_CAPTURE_SIZE_4M,        ///< 2592*1520
	SDK_CAPTURE_SIZE_6M,		///< 3072×2048
	SDK_CAPTURE_SIZE_8M,		///< 3264×2448
	SDK_CAPTURE_SIZE_12M,		///< 4000*3000
	SDK_CAPTURE_SIZE_4K,		///< 4096 * 2160通用/3840*2160海思
	SDK_CAPTURE_SIZE_EXT_V2_NR = 25,
	SDK_CAPTURE_SIZE_720N = 25,  	///< 640*720
	SDK_CAPTURE_SIZE_WSVGA,			///< 1024*576
	SDK_CAPTURE_SIZE_NHD,			///< Wifi IPC 640*360
	SDK_CAPTURE_SIZE_3M_N,			///< 1024*1536
	SDK_CAPTURE_SIZE_4M_N,			///< 1296*1520
	SDK_CAPTURE_SIZE_5M_N,			///< 1872*1408
	SDK_CAPTURE_SIZE_4K_N,			///< 2048 * 2160通用/1920*2160海思
	SDK_CAPTURE_SIZE_EXT_V3_NR,
}ESDK_CAPTURE_SIZE;

/// 捕获码流控制模式类型
typedef enum ESDK_CAPTURE_BRC
{
	SDK_CAPTURE_BRC_CBR,			///< 固定码流。
	SDK_CAPTURE_BRC_VBR,			///< 可变码流。
	SDK_CAPTURE_BRC_MBR,			///< 混合码流。
	SDK_CAPTURE_BRC_NR				///< 枚举的码流控制模式数目。
}ESDK_CAPTURE_BRC;

/// 捕获压缩格式类型
typedef enum ESDK_CAPTURE_COMP
{
	SDK_CAPTURE_COMP_DIVX_MPEG4,	///< DIVX MPEG4。
	SDK_CAPTURE_COMP_MS_MPEG4,		///< MS MPEG4。
	SDK_CAPTURE_COMP_MPEG2,			///< MPEG2。
	SDK_CAPTURE_COMP_MPEG1,			///< MPEG1。
	SDK_CAPTURE_COMP_H263,			///< H.263
	SDK_CAPTURE_COMP_MJPG,			///< MJPG
	SDK_CAPTURE_COMP_FCC_MPEG4,		///< FCC MPEG4
	SDK_CAPTURE_COMP_H264,			///< H.264
	SDK_CAPTURE_COMP_H265,			///< H.265
	SDK_CAPTURE_COMP_NR				///< 枚举的压缩标准数目。
}ESDK_CAPTURE_COMP;

typedef struct SSDK_VIDEO_FORMAT
{
	int		iCompression;			//  压缩模式(视频格式) 参照enum SDK_CAPTURE_COMP_t 	
	int		iResolution;			//  分辨率 参照枚举SDK_CAPTURE_SIZE_t
	int		iBitRateControl;		//  码流控制 参照枚举SDK_capture_brc_t
	int		iQuality;				//  码流的画质 档次1-6		
	int		nFPS;					//  帧率值，NTSC/PAL不区分,负数表示多秒一帧		
	int		nBitRate;				//  0-4096k,该列表主要由客户端保存，设备只接收实际的码流值而不是下标。
	int		iGOP;					//  描述两个I帧之间的间隔时间，2-12 
} SSDK_VIDEO_FORMAT;

typedef enum EXNetSDK_EDECODE_RESULT
{
	DECODE_RESULT_NULL = 0,		// 不回调解码结果
	DECODE_RESULT_YUV420 = 1,	// 回调视频解码结果(YUV420)
	DECODE_RESULT_PCM = 2,		// 回调音频解码结果(PCM)
	DECODE_RESULT_YUV420_PCM = 3,// 回调视频+音频解码结果(YUV420+PCM)
}EXNetSDK_EDECODE_RESULT;
typedef struct SXMediaRealPlayReq
{
	int nChannel;
	int nStreamType;
	int nRequestType;
	int nDecodeType;
	SMsgReceiver result;
	UI_HANDLE hShowWindows;
	char res[128];
}SXMediaRealPlayReq;

typedef struct SXMediaFaceImageReq
{
	int nChannel;
	int nImgTypeMsk;
	char szIntelType[64];
	int nDecodeType;
	SMsgReceiver result;
	UI_HANDLE hShowWindows;
}SXMediaFaceImageReq;

typedef struct SXMediaRecordReq
{
	int nChannel;
	int nStreamType;
	char sBeginTime[32];
	char sEndTime[32];
	char sFileName[64];
	char sIntelligentPlayBackEvent[64];
	int nIntelligentPlayBackSpeed;
	int nRequestType;
	int nDecodeType;
	SMsgReceiver result;
	UI_HANDLE hShowWindows;
}SXMediaRecordReq;

typedef struct SXMediaTalkReq
{
	int nBitRate;			///< 码流大小，kbps为单位，比如192kbps，128kbps
	int nSampleRate;		///< 采样率，Hz为单位，比如44100Hz
	int nSampleBit;			///< 采样的位深
	char nEncodeType[64];	///< 编码方式，-------G711_ALAW
	Bool bPlayAuduio;		// 是否解码播放声音(Windows & Android & IOS支持)
	int nRequestType;
	int nDecodeType;
	SMsgReceiver result;
}SXMediaTalkReq;

typedef struct SXCloudUpgradeVersion
{
	char name[128];			// 版本名
	char date[12];			//版本日期，格式:"2014-08-26"
	unsigned int length;	// 升级文件长度
}SXCloudUpgradeVersion;
#endif //_XNetSDKDefine_H_
