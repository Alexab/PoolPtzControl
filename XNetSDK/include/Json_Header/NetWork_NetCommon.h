#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetCommon "NetWork.NetCommon" 
class NetWork_NetCommon : public JObject
{
public:
	JStrObj		GateWay;			///< 网关IP
	JStrObj		HostIP;				///< 主机IP
	JStrObj		HostName;			///< 主机名
	JIntObj		HttpPort;			///< HTTP服务端口
	JStrObj		MAC;				///< MAC地址
	JIntObj		MaxBps;				///< 限定码流值
	JStrObj		MonMode;			///< 监视协议 {"TCP","UDP","MCAST",…}
	JIntObj		SSLPort;			///< SSL侦听端口
	JStrObj		Submask;			///< 子网掩码
	JIntObj		TCPMaxConn;			///< 最大连接数
	JIntObj		TCPPort;			///< TCP侦听端口
	JStrObj		TransferPlan;		///< 传输策略"AutoAdapt":自适应, "Quality":质量优先, "Fluency":流量优先，"Transmission":网传优先
	JIntObj		UDPPort;			///< UDP侦听端口
	JBoolObj	UseHSDownLoad;		///< 是否启用高速录像下载

public:
	NetWork_NetCommon(JObject *pParent = NULL, const char *szName = JK_NetWork_NetCommon):
	JObject(pParent,szName),
	GateWay(this, "GateWay"),
	HostIP(this, "HostIP"),
	HostName(this, "HostName"),
	HttpPort(this, "HttpPort"),
	MAC(this, "MAC"),
	MaxBps(this, "MaxBps"),
	MonMode(this, "MonMode"),
	SSLPort(this, "SSLPort"),
	Submask(this, "Submask"),
	TCPMaxConn(this, "TCPMaxConn"),
	TCPPort(this, "TCPPort"),
	TransferPlan(this, "TransferPlan"),
	UDPPort(this, "UDPPort"),
	UseHSDownLoad(this, "UseHSDownLoad"){
        this->Parse("{ \"Name\" : \"NetWork.NetCommon\", \"NetWork.NetCommon\" : { \"GateWay\" : \"0xFE580A0A\", \"HostIP\" : \"0x24580A0A\", \"HostName\" : \"robot_7865\", \"HttpPort\" : 80, \"MAC\" : \"22:64:11:12:13:14\", \"MaxBps\" : 0, \"MonMode\" : \"IPV6\", \"SSLPort\" : 8443, \"Submask\" : \"0x00FFFFFF\", \"TCPMaxConn\" : 10, \"TCPPort\" : 34567, \"TransferPlan\" : \"Transmission\", \"UDPPort\" : 34568, \"UseHSDownLoad\" : false }, \"SessionID\" : \"0x670\" }");
	};

	~NetWork_NetCommon(void){};
};

NS_NETSDK_CFG_END
