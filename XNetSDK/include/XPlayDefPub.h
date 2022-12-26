#pragma once
#ifndef XPlayDefPub_H
#define XPlayDefPub_H

#ifdef OS_WINDOWS
#else
typedef void* HDC;
#endif // OS_WINDOWS

typedef struct _XPlayRECT
{
	int left;
	int top;
	int right;
	int bottom;
}XPlayRECT;

typedef enum EUIDOWNLOAD_STEP
{
	EUIDOWNLOAD_STEP_NONE = 0,	//< 未开始
	EUIDOWNLOAD_STEP_DOWN = 1,	//< 正在下载
	EUIDOWNLOAD_STEP_TRAN = 2,	//< 正在转换文件格式
	EUIDOWNLOAD_STEP_COMPELTE = 10,	//< 下载完成
}EUIDOWNLOAD_STEP;
typedef enum EUIMSG
{
	EUIMSG_PLAY_START = 30000,		///< 开始播放
	EUIMSG_PLAY_PAUSE,				///< 暂停播放
	EUIMSG_PLAY_STOP,				///< 播放结束(数据异常停止返回或文件播放结束返回)
	EUIMSG_START_BUFFER_DATA,		///< 正在缓存数据
	EUIMSG_END_BUFFER_DATA,			///< 缓存结束,开始播放
	EUIMSG_PLAY_MEDIA_FRAME_LOSS,	///< 超过4S没有收到数据
	EUIMSG_PLAY_INFO,				///< 播放信息
	EUIMSG_PLAY_SAVE_IMAGE_FILE,	///< 本地保存图片
	EUIMSG_PLAY_CATCH_PIC_BUFFER,	///< 获取图片数据
	EUIMSG_AUDIO_DATA,				///< 采集到的音频数据
	EUIMSG_YUV_DATA,				///< YUV数据
	EUIMSG_RECORD_START,			///< 开始录像
	EUIMSG_RECORD_STOP,				///< 录像结束
	/// <summary>
	/// 文件下载进度
	/// param1: 详见EUIDOWNLOAD_STEP
	///			<0:遇到错误结束下载
	/// param2:进度(0~100)或错误码
	/// param3:当前下载的时间戳
	/// </summary>
	EUIMSG_ON_FILE_DOWNLOAD,		///< 文件下载 
	EUIMSG_PLAY_SOUND,				///< 播放音频
	EUIMSG_DECODE_PCM,				///< PCM数据
}EUIMSG;

typedef enum EXPLAY_ERROR
{
	EXPLAY_ERROR_OK = 0,							///< 成功

	//网络相关错误码
	EXPLAY_ERROR_NET = -1000,						///< 网络错误
	EXPLAY_ERROR_SENDBUF_FULL = -1001,				///< 发送缓冲满了
	EXPLAY_ERROR_SEND = -1002,						///< 发送异常
	EXPLAY_ERROR_RECV = -1003,						///< 接收异常
	EXPLAY_ERROR_NET_ACTIVE_TEST = -1004,			///< 超时没有活动就断线了
	EXPLAY_ERROR_NET_NO_OBJECT = -1005,
	EXPLAY_ERROR_NET_CREATE = -1006,
	EXPLAY_ERROR_NET_CONNECT = -1007,				///< 连接异常
	EXPLAY_ERROR_NET_TIMEOUT = -1008,				///< 网络超时
	EXPLAY_ERROR_NET_NOCONNECT = -1009,				///< 没有连接
	EXPLAY_ERROR_NET_SOCKET = -1010,				///< socket异常
	EXPLAY_ERROR_NET_SOCKET_CLOSE = -1011,			///< socket关闭失败
	EXPLAY_ERROR_NET_NEW_BUFFER = -1012,			///< New地址失败
	EXPLAY_ERRORE_NET_BUS = -1013,					///< 网络繁忙
	EXPLAY_ERROR_NET_LISTEN = -1014,				///< 监听异常
	EXPLAY_ERROR_NET_ACCEPT = -1015,				///< 接收异常
	EXPLAY_ERROR_NET_NOBUFS = -1016,				///< 没有内存
	EXPLAY_ERROR_NET_OR_DNS = -1017,				///< 网络错误或DNS配置错误
	EXPLAY_ERROR_NO_RIGHT = -1018,					///< 无权限

	///常见错误码
	EXPLAY_ERROR_OBJ_NOT_EXIST = -1239510,			///< 句柄无效
	EXPLAY_ERROR_VALUE_NOT_EXIST = -1239511,
	EXPLAY_ERROR_ERROR = -100000,
	EXPLAY_ERROR_PARAM_ERROR = -99999,
	EXPLAY_ERROR_CREATE_FILE = -99998,				///< 创建文件失败
	EXPLAY_ERROR_OPEN_FILE = -99997,				///< 打开文件失败
	EXPLAY_ERROR_WRITE_FILE = -99996,				///< 写文件失败
	EXPLAY_ERROR_READ_FILE = -99995,				///< 读文件失败
	EXPLAY_ERROR_NO_SUPPORTED = -99994,				///< 不支持
	EXPLAY_ERROR_OBJ_EXIST = -99992,				///< 对象不存在
	EXPLAY_ERROR_TIMEOUT = -99991,					///< 超时
	EXPLAY_ERROR_NOT_FOUND = -99990,				///< 没找到
	EXPLAY_ERROR_NEW_BUFFER = -99989,				///< new地址失败
	EXPLAY_ERROR_OBJECT_BUSY = -99986,				///< 对象繁忙
	EXPLAY_ERROR_SERVER_INTERNAL_ERROR = -99985,	///< 服务器内部错误
	EXPLAY_ERROR_SERVER_BIND_PORT = -99984,			///< 监听端口bind失败（端口被占用）
	EXPLAY_ERROR_SERVER_LISTEN = -99983,			///< 监听服务器启动失败
	EXPLAY_ERROR_NET_SEND_BUF_FULL = -99982,		///< 发送缓冲区满了
	EXPLAY_ERROR_NO_BUFFER = -99981,				///< 缓冲区大小不够或缓冲区满
	EXPLAY_ERROR_PARSER_PTL = -99980,				///< 协议解析错误
	EXPLAY_ERROR_USER_OR_PWD_ERROR = -99979,		///< 用户名或密码错误
	EXPLAY_ERROR_USER_HAS_LOGIN = -99978,			///< 用户已被其他地方登陆
	EXPLAY_ERROR_USER_LOCKED = -99977,				///< 用户被锁定
	EXPLAY_ERROR_USER_IN_BLACKLIST = -99976,		///< 用户列为黑名单
	EXPLAY_ERROR_OFF_LINE = -99975,					///< 离线状态
	EXPLAY_ERROR_USER_CANCEL = -90000,				///< 用户取消失败
	EXPLAY_ERROR_FILE_IS_ILLEGAL = -90001,			///< 文件非法

	EXPLAY_ERROR_YUVDATA_ERROR = -79999,			///< YUV数据异常
	EXPLAY_ERROR_PLAY_SOUND = -79998,				///< 打开音频失败（设备不支持音频播放）
}EXPLAY_ERROR;

typedef enum EDECODE_TYPE
{
	EDECODE_REAL_TIME_STREAM0,      // 最实时--适用于IP\AP模式等网络状态很好的情况
	EDECODE_REAL_TIME_STREAM1,      //
	EDECODE_REAL_TIME_STREAM2,      //
	EDECODE_REAL_TIME_STREAM3,      // 中等
	EDECODE_REAL_TIME_STREAM4,      //
	EDECODE_REAL_TIME_STREAM5,      //
	EDECODE_REAL_TIME_STREAM6,      // 最流畅--适用于网络不好,网络波动大的情况
	EDECODE_FILE_STREAM = 100,      // 文件流
} EDECODE_TYPE;
#define    EDECODE_REAL_TIME_DEFALUT EDECODE_REAL_TIME_STREAM3

// 对象属性
typedef enum EMSGOBJ_ATTR
{
	EMSGOBJ_ATTR_VOLUME = 60000,			///< 音量大小
	EMSGOBJ_ATTR_DISPLAY_BCSG,				///< 画面背景信息
	EMSGOBJ_ATTR_DECODETYPE,				///< EDecodeObjectType
	EMSGOBJ_ATTR_IS_SPPORT_HARD_DEC,		///< EDecodeObjectType
}EMSGOBJ_ATTR;

typedef enum EDecodeObjectType
{
	EDT_FFMPEG_HARD = 0,
	EDT_FFMPEG_SOFT,
	EDT_HISI,
	EDT_IOS_HARD,
	EDT_ANDROID_HARD,
	EDT_DECODE_TYPE_SIZE,
}EDecodeObjectType;

// 
typedef void (CALLBACK* PXSDK_DrawCallBack)(XSDK_HANDLE hObject, HDC hDc, void* pUserData);

#endif //XPlayDefPub_H