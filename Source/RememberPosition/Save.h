#pragma once

#include "StageInfo.h"

class SelfVector 
{
public:
	float x;
	float y;
	float z;
};

class Save 
{
public:
	static StageInfo stage;

	static inline INIReader reader;

	static inline void Initialize() 
	{
		string file = Common::GetCurrentStageID() + ".ini";
		reader = INIReader(file);
		Load();
	}

	static inline void Load() 
	{
		
	}

	static inline void SaveData() 
	{
		//INIReader::INIF
	}
};