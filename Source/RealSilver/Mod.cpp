#include "Configuration.h"
#include "ArchiveTreePatcher.h"
#include "SetdataPatcher.h"

extern "C" void __declspec(dllexport) OnFrame()
{

}

HOOK(void, __fastcall, CSonicStateAirBoostBegin, 0x1233380, hh::fnd::CStateMachineBase::CStateBase* This)
{
    originalCSonicStateAirBoostBegin(This);

    auto* context = (Sonic::Player::CPlayerSpeedContext*)This->GetContextBase();
    Eigen::Vector3f velocity = context->m_Velocity;
    velocity.y() = 0.0f;
    Common::SetPlayerVelocity(velocity);
}

void SetBoostModelVisible(bool visible)
{
    auto const& model = Sonic::Player::CPlayerSpeedContext::GetInstance()->m_pPlayer->m_spCharacterModel;
    model->m_spModel->m_NodeGroupModels[0]->m_Visible = !visible;
    model->m_spModel->m_NodeGroupModels[1]->m_Visible = visible;
}

HOOK(int, __fastcall, MsgRestartStage, 0xE76810, Sonic::Player::CPlayer* player, void* Edx, void* message)
{
    SetBoostModelVisible(false);
    return originalMsgRestartStage(player, Edx, message);
}

HOOK(void, __fastcall, CSonicStatePluginBoostBegin, 0x1117A20, hh::fnd::CStateMachineBase::CStateBase* This)
{
    originalCSonicStatePluginBoostBegin(This);
    SetBoostModelVisible(true);
}

HOOK(void, __fastcall, CSonicStatePluginBoostEnd, 0x1117900, hh::fnd::CStateMachineBase::CStateBase* This)
{
    originalCSonicStatePluginBoostEnd(This);
    SetBoostModelVisible(false);
}

extern "C" __declspec(dllexport) void Init(ModInfo * modInfo)
{
    std::string dir = modInfo->CurrentMod->Path;

    size_t pos = dir.find_last_of("\\/");
    if (pos != std::string::npos)
    {
        dir.erase(pos + 1);
    }

    if (!Configuration::load(dir))
    {
        MessageBox(NULL, L"Failed to parse Config.ini", NULL, MB_ICONERROR);
    }

    if (Configuration::m_blazeSupport)
    {
        ArchiveTreePatcher::applyPatches();
        SetdataPatcher::applyPatches();
    }

    // don't disable air action after air boost
    WRITE_NOP(0x12334D0, 3);

    // don't play boost screen effect
    WRITE_MEMORY(0x12334C1, uint8_t, 0x4);

    // infinite air boost time
    WRITE_MEMORY(0x123325E, uint8_t, 0xEB);

    // Cancel y-speed on air boost
    INSTALL_HOOK(CSonicStateAirBoostBegin);

    // Swap boost model
    INSTALL_HOOK(MsgRestartStage);
    INSTALL_HOOK(CSonicStatePluginBoostBegin);
    INSTALL_HOOK(CSonicStatePluginBoostEnd);

    // Fix fire/electric damage bone location
    WRITE_MEMORY(0x1ABD060, char*, "Needle_A_C"); // Needle_U_C
    //WRITE_MEMORY(0x1ABD064, char*, "Hand_L"); // Hand_L
    //WRITE_MEMORY(0x1ABD068, char*, "Hand_R"); // Hand_R
    //WRITE_MEMORY(0x1ABD06C, char*, "Toe_L"); // Toe_L
    //WRITE_MEMORY(0x1ABD070, char*, "Toe_R"); // Toe_R
    WRITE_MEMORY(0x1203CA3, uint32_t, 0x1ABD05C); // electic damage use fire damage offsets
    WRITE_MEMORY(0x1203D7C, uint32_t, 0x1ABD074);

    // Fix Super pfx bone location
    WRITE_MEMORY(0xDA26EA, char*, "Needle_A_C"); // Needle_U_C
    //WRITE_MEMORY(0xDA273B, char*, "Hand_L"); // Hand_L
    //WRITE_MEMORY(0xDA278C, char*, "Hand_R"); // Hand_R
    //WRITE_MEMORY(0xDA27DD, char*, "Foot_L"); // Foot_L
    //WRITE_MEMORY(0xDA285E, char*, "Foot_R"); // Foot_R

    // Changed Silver boss fight tint to red
    WRITE_MEMORY(0xE93448, uint32_t, 0x1703C08);
    WRITE_MEMORY(0xE9345C, uint32_t, 0x14A84B8);
    WRITE_MEMORY(0xE93467, uint32_t, 0x14A84B8);
}