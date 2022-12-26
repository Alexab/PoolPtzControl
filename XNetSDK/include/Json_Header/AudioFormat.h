#pragma once
#include "JObject_NetSDK.h"

#define JK_AudioFormat "AudioFormat" 
class AudioFormat : public JObject
{
public:
	JIntObj		BitRate;
	JStrObj		EncodeType;
	JIntObj		SampleBit;
	JIntObj		SampleRate;

public:
	AudioFormat(JObject *pParent = NULL, const char *szName = JK_AudioFormat):
	JObject(pParent,szName),
	BitRate(this, "BitRate"),
	EncodeType(this, "EncodeType"),
	SampleBit(this, "SampleBit"),
	SampleRate(this, "SampleRate"){
		this->Parse("{ \"AudioFormat\" : { \"BitRate\" : 128, \"EncodeType\" : \"G711_ALAW\", \"SampleBit\" : 8, \"SampleRate\" : 8000 }, \"Ret\" : 100, \"SessionID\" : \"0x0000004E\" }");
	};

	~AudioFormat(void){};
};