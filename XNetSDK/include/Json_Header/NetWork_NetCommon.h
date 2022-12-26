#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetCommon "NetWork.NetCommon" 
class NetWork_NetCommon : public JObject
{
public:
	JStrObj		GateWay;			///< ����IP
	JStrObj		HostIP;				///< ����IP
	JStrObj		HostName;			///< ������
	JIntObj		HttpPort;			///< HTTP����˿�
	JStrObj		MAC;				///< MAC��ַ
	JIntObj		MaxBps;				///< �޶�����ֵ
	JStrObj		MonMode;			///< ����Э�� {"TCP","UDP","MCAST",��}
	JIntObj		SSLPort;			///< SSL�����˿�
	JStrObj		Submask;			///< ��������
	JIntObj		TCPMaxConn;			///< ���������
	JIntObj		TCPPort;			///< TCP�����˿�
	JStrObj		TransferPlan;		///< �������"AutoAdapt":����Ӧ, "Quality":��������, "Fluency":�������ȣ�"Transmission":��������
	JIntObj		UDPPort;			///< UDP�����˿�
	JBoolObj	UseHSDownLoad;		///< �Ƿ����ø���¼������

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
