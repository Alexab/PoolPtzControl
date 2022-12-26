#pragma once
#include "JObject_NetSDK.h"

NS_NETSDK_CFG_BEGIN

#define JK_TotalChnsMode "TotalChnsMode" 
class TotalChnsMode : public JObject
{
public:
	JIntObj		AnalogCap1080N;
	JIntObj		AnalogCap1080P;
	JIntObj		AnalogCap3MChn;
	JIntObj		AnalogCap3M_N;
	JIntObj		AnalogCap4K;
	JIntObj		AnalogCap4K_N;
	JIntObj		AnalogCap4M;
	JIntObj		AnalogCap4M_N;
	JIntObj		AnalogCap5MChn;
	JIntObj		AnalogCap5M_N;
	JIntObj		AnalogCap720N;
	JIntObj		AnalogCap720P;
	JIntObj		AnalogCap960H;
	JIntObj		AnalogCap960PChn;
	JIntObj		AnalogCapCIF;
	JIntObj		AnalogCapD1;
	JIntObj		AnalogCapDigiTal;
	JIntObj		AnalogCapHD1;
	JIntObj		AnalogCapPlay;
	JIntObj		AnalogCapWSVGA;
	JIntObj		AnalogCapWUXGAChn;
	JIntObj		DigitalCap1080N;
	JIntObj		DigitalCap1080P;
	JIntObj		DigitalCap3MChn;
	JIntObj		DigitalCap3M_N;
	JIntObj		DigitalCap4K;
	JIntObj		DigitalCap4K_N;
	JIntObj		DigitalCap4M;
	JIntObj		DigitalCap4M_N;
	JIntObj		DigitalCap5MChn;
	JIntObj		DigitalCap5M_N;
	JIntObj		DigitalCap720N;
	JIntObj		DigitalCap720P;
	JIntObj		DigitalCap960H;
	JIntObj		DigitalCap960PChn;
	JIntObj		DigitalCapCIF;
	JIntObj		DigitalCapD1;
	JIntObj		DigitalCapDigiTal;
	JIntObj		DigitalCapHD1;
	JIntObj		DigitalCapPlay;
	JIntObj		DigitalCapWSVGA;
	JIntObj		DigitalCapWUXGAChn;
			
	
public:
    TotalChnsMode(JObject *pParent = NULL, const char *szName = JK_TotalChnsMode):
    JObject(pParent,szName),
	AnalogCap1080N(this, "AnalogCap1080N"),
	AnalogCap1080P(this, "AnalogCap1080P"),
	AnalogCap3MChn(this, "AnalogCap3MChn"),
	AnalogCap3M_N(this, "AnalogCap3M_N"),
	AnalogCap4K(this, "AnalogCap4K"),
	AnalogCap4K_N(this, "AnalogCap4K_N"),
	AnalogCap4M(this, "AnalogCap4M"),
	AnalogCap4M_N(this, "AnalogCap4M_N"),
	AnalogCap5MChn(this, "AnalogCap5MChn"),
	AnalogCap5M_N(this, "AnalogCap5M_N"),
	AnalogCap720N(this, "AnalogCap720N"),
	AnalogCap720P(this, "AnalogCap720P"),
	AnalogCap960H(this, "AnalogCap960H"),
	AnalogCap960PChn(this, "AnalogCap960PChn"),
	AnalogCapCIF(this, "AnalogCapCIF"),
	AnalogCapD1(this, "AnalogCapD1"),
	AnalogCapDigiTal(this, "AnalogCapDigiTal"),
	AnalogCapHD1(this, "AnalogCapHD1"),
	AnalogCapPlay(this, "AnalogCapPlay"),
	AnalogCapWSVGA(this, "AnalogCapWSVGA"),
	AnalogCapWUXGAChn(this, "AnalogCapWUXGAChn"),
	DigitalCap1080N(this, "DigitalCap1080N"),
	DigitalCap1080P(this, "DigitalCap1080P"),
	DigitalCap3MChn(this, "DigitalCap3MChn"),
	DigitalCap3M_N(this, "DigitalCap3M_N"),
	DigitalCap4K(this, "DigitalCap4K"),
	DigitalCap4K_N(this, "DigitalCap4K_N"),
	DigitalCap4M(this, "DigitalCap4M"),
	DigitalCap4M_N(this, "DigitalCap4M_N"),
	DigitalCap5MChn(this, "DigitalCap5MChn"),
	DigitalCap5M_N(this, "DigitalCap5M_N"),
	DigitalCap720N(this, "DigitalCap720N"),
	DigitalCap720P(this, "DigitalCap720P"),
	DigitalCap960H(this, "DigitalCap960H"),
	DigitalCap960PChn(this, "DigitalCap960PChn"),
	DigitalCapCIF(this, "DigitalCapCIF"),
	DigitalCapD1(this, "DigitalCapD1"),
	DigitalCapDigiTal(this, "DigitalCapDigiTal"),
	DigitalCapHD1(this, "DigitalCapHD1"),
	DigitalCapPlay(this, "DigitalCapPlay"),
	DigitalCapWSVGA(this, "DigitalCapWSVGA"),
	DigitalCapWUXGAChn(this, "DigitalCapWUXGAChn"){
	};

    ~TotalChnsMode(void){};
};

NS_NETSDK_CFG_END