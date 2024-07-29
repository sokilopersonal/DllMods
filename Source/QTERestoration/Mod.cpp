#include "ArchiveTreePatcher.h"
#include "AnimationSetPatcher.h"
#include "Configuration.h"
#include "QTEJumpBoard.h"
#include "QTEReactionPlate.h"
#include "ReactionPlateScoreSupport.h"
#include "TrickJumper.h"
#include "ModeChanger.h"
#include "ModLoader.h"
#include "MsgChangeModeToForward.h"

extern "C" __declspec(dllexport) void Init(ModInfo * modInfo)
{
	Configuration::Read();

	// -------------Patches--------------
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Load extra archives
	ArchiveTreePatcher::applyPatches();

	// Load extra animations
	AnimationSetPatcher::applyPatches();

	QTEJumpBoard::applyPatches();
	QTEReactionPlate::applyPatches();
	ReactionPlateScoreSupport::applyPatches();
	//ReactionPlate2DFix::applyPatches();

	// QTE Custom Object
	TrickJumper::registerObject();
	TrickJumper::applyPatches();
}

extern "C" __declspec(dllexport) void PostInit()
{

}

extern "C" void __declspec(dllexport) OnFrame()
{
	
}