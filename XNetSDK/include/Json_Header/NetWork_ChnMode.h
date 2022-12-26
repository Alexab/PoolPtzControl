#pragma once
#include "JObject_NetSDK.h"
#include "TotalChnsMode.h"

//m_nTotalChnsMode：所有的通道模式（数组大小为32）
//TotalChnsModeNum:总共支持几种模式切换
//CurChnsMode:当前的通道模式（数组从0开始）

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_ChnMode "NetWork.ChnMode" 
class NetWork_ChnMode : public JObject
{
public:
	JIntObj			CurChnsMode;
	JIntObj			TotalChnsModeNum;
	JObjArray<TotalChnsMode>		m_nTotalChnsMode;
	
public:
    NetWork_ChnMode(JObject *pParent = NULL, const char *szName = JK_NetWork_ChnMode):
    JObject(pParent,szName),
	CurChnsMode(this, "CurChnsMode"),
	TotalChnsModeNum(this, "TotalChnsModeNum"),
	m_nTotalChnsMode(this, "TotalChnsMode"){
	};

    ~NetWork_ChnMode(void){};
};

NS_NETSDK_CFG_END