#include "ModeChanger.h"
#include "MsgChangeModeTo3D.h"
#include "MsgChangeModeToForward.h"

HOOK(void, __fastcall, CPlayerSpeedUpdate, 0xE6BF20, Sonic::Player::CPlayerSpeed* This, void* _, const Hedgehog::Universe::SUpdateInfo& updateInfo)
{
    auto* player = Sonic::Player::CPlayerSpeedContext::GetInstance()->m_pPlayer;
    if (player->m_StateMachine.GetCurrentState()->GetStateName() != "ReactionJump")
    {
        player->SendMessageSelfImm<Sonic::Message::MsgChangeModeToForward>();
    }

    originalCPlayerSpeedUpdate(This, _, updateInfo);
}

HOOK(void, __fastcall, QTEReactionPlate_MsgHitEventCollision, 0x1017020, uint32_t* This, void* Edx, void* message)
{
    auto* player = Sonic::Player::CPlayerSpeedContext::GetInstance()->m_pPlayer;
    if (player->m_StateMachine.GetCurrentState()->GetStateName() != "ReactionJump")
	{
        player->SendMessageSelfImm<Sonic::Message::MsgChangeModeToForward>();
	}

    originalQTEReactionPlate_MsgHitEventCollision(This, Edx, message);
}

void ReactionPlate2DFix::applyPatches() 
{
    INSTALL_HOOK(QTEReactionPlate_MsgHitEventCollision);
    INSTALL_HOOK(CPlayerSpeedUpdate);
}