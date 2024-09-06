#include "RememberPosition.h"

extern "C" __declspec(dllexport) void Init(ModInfo* modInfo)
{
	RememberPosition::applyPatches();
}

extern "C" __declspec(dllexport) void PostInit()
{

}

extern "C" void __declspec(dllexport) OnFrame()
{

}