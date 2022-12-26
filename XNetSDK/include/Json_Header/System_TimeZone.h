#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

enum TimeZoneType
{
	TimeZone_UTC_N12_00=-1200,			//日界线西
	TimeZone_UTC_N11_00=-1100,			//中途岛,萨摩亚群岛	
	TimeZone_UTC_N10_00=-1000,			//夏威夷
	TimeZone_UTC_N09_00=-900,			//阿拉斯加
	TimeZone_UTC_N08_00=-800,			//太平洋时间(美国和加拿大)
	TimeZone_UTC_N07_00=-700,			//山区时间(美国和加拿大)
	TimeZone_UTC_N06_00=-600,			//中部时间(美国和加拿大)
	TimeZone_UTC_N05_00=-500,			//东部时间(美国和加拿大)
	TimeZone_UTC_N04_00=-400,			//大西洋时间(加拿大)
	TimeZone_UTC_N03_30=-330,			//纽芬兰
	TimeZone_UTC_N03_00=-300,			//巴西利亚,乔治敦
	TimeZone_UTC_N02_00=-200,			//中大西洋
	TimeZone_UTC_N01_00=-100,			//亚速群岛,佛得角群岛
	TimeZone_UTC_P00_00=0,				//都柏林,伦敦,爱丁堡
	TimeZone_UTC_P01_00=100,			//柏林,阿姆斯特丹,巴黎,罗马
	TimeZone_UTC_P02_00=200,			//雅典,耶路撒冷,伊斯坦布尔
	TimeZone_UTC_P03_00=300,			//巴格达,科威特,莫斯科
	TimeZone_UTC_P03_30=330,			//德黑兰
	TimeZone_UTC_P04_00=400,			//阿布扎比,巴库,马斯喀特
	TimeZone_UTC_P04_30=430,			//坎布尔
	TimeZone_UTC_P05_00=500,			//伊斯兰堡,卡拉奇,塔什干
	TimeZone_UTC_P05_30=530,			//孟买,马德拉斯,新德里
	TimeZone_UTC_P05_45=545,			//加德满都
	TimeZone_UTC_P06_00=600,			//阿拉木图,科伦坡,达卡
	TimeZone_UTC_P06_30=630,			//仰光
	TimeZone_UTC_P07_00=700,			//曼谷,河内,雅加达
	TimeZone_UTC_P08_00=800,			//北京,乌鲁木齐,台北,新加坡
	TimeZone_UTC_P09_00=900,			//大阪,札幌,汉城,东京
	TimeZone_UTC_P09_30=930,			//阿德莱德,达尔文
	TimeZone_UTC_P10_00=1000,			//堪培拉,墨尔本,悉尼
	TimeZone_UTC_P11_00=1100,			//马加丹,所罗门群岛
	TimeZone_UTC_P12_00=1200,			//奥克兰,惠灵顿
	TimeZone_UTC_P13_00=1300,			//努库阿洛法
	TimeZone_UTCNum,
};

#define JK_System_TimeZone "System.TimeZone"
class System_TimeZone : public JObject 
{
public:
	JBoolObj	FirstUserTimeZone;
	JIntObj		timeMin;

public:
	System_TimeZone(JObject *pParent = NULL, const char *szName = JK_System_TimeZone):
	JObject(pParent,szName),
	FirstUserTimeZone(this, "FirstUserTimeZone"),
	timeMin(this, "timeMin"){
	};

	~System_TimeZone(void){};
};

NS_NETSDK_CFG_END