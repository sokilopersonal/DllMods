#include "RememberPosition.h"
#include "Save.h"

extern "C" __declspec(dllexport) void Init(ModInfo* modInfo)
{
	RememberPosition::applyPatches();
	//Save::Initialize();
}

extern "C" __declspec(dllexport) void PostInit()
{

}

extern "C" void __declspec(dllexport) OnFrame()
{

}