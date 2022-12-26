#pragma once
#include "JObject_NetSDK.h"
#include "Parameter.h"
#include "../XNetSDKDefine.h"
NS_NETSDK_CFG_BEGIN

/////////////////方向控制/////////////////
#define JPTZ_DirectionLeftUp "DirectionLeftUp"
#define JPTZ_DirectionUp "DirectionUp"
#define JPTZ_DirectionRightUp "DirectionRightUp"
#define JPTZ_DirectionLeft "DirectionLeft"
#define JPTZ_DirectionRight "DirectionRight"
#define JPTZ_DirectionLeftDown "DirectionLeftDown"
#define JPTZ_DirectionDown "DirectionDown"
#define JPTZ_DirectionRightDown "DirectionRightDown"
#define JPTZ_IrisSmall "IrisSmall"
#define JPTZ_IrisLarge "IrisLarge"
#define JPTZ_FocusNear "FocusNear"
#define JPTZ_FocusFar "FocusFar"
#define JPTZ_ZoomWide "ZoomWide"
#define JPTZ_ZoomTile "ZoomTile"
#define JPTZ_Reset    "Reset"

#define JPTZ_Sit        "Sit"
#define JPTZ_Light      "Light"
#define JPTZ_Rainbrush  "Rainbrush"
#define JPTZ_AutPan     "AutPan"
#define JPTZ_StopAutPan "StopAutPan"

#define JPTZ_OPERATION_START 65535
#define JPTZ_OPERATION_STOP  -1

/////////////////云台预置点操作/////////////////
#define JPTZ_GotoPreset     "GotoPreset"
#define JPTZ_SetPreset      "SetPreset"
#define JPTZ_ClearPreset    "ClearPreset"

/////////////////云台巡航操作/////////////////
#define JPTZ_AddTour	"AddTour"			//添加巡航点
#define JPTZ_DeleteTour	"DeleteTour"		//删除预置点	
#define JPTZ_StartTour	"StartTour"			//开始巡航
#define JPTZ_StopTour	"StopTour"			//停止巡航
#define JPTZ_ClearTour	"ClearTour"			//清除巡航路线值
#define JPTZ_SetSpeed   "SetSpeed"       //设置巡航速度
#define JPTZ_SetTime    "SetTime"  //设置巡航停留时间


#define JK_OPPTZControl "OPPTZControl" 
class OPPTZControl : public JObject
{
public:
	Parameter	mParameter;
	JStrObj		Command;

public:
	OPPTZControl(JObject* pParent = NULL, const char* szName = JK_OPPTZControl) :
		JObject(pParent, JK_OPPTZControl),
		mParameter(this, "Parameter"),
		Command(this, "Command")
	{
		this->Parse("{ \"Name\" : \"OPPTZControl\", \"OPPTZControl\" : { \"Command\" : \"DirectionLeft\", \"Parameter\" : { \"AUX\" : { \"Number\" : 0, \"Status\" : \"On\" }, \"Channel\" : 0, \"MenuOpts\" : \"Enter\", \"POINT\" : { \"bottom\" : 0, \"left\" : 0, \"right\" : 0, \"top\" : 0 }, \"Pattern\" : \"SetBegin\", \"Preset\" : 65535, \"Step\" : 5, \"Tour\" : 0 } }, \"SessionID\" : \"0x0000000000\" }");
	};

	~OPPTZControl(void) {};
};
NS_NETSDK_CFG_END
