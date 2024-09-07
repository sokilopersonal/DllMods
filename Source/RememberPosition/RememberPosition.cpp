#include "RememberPosition.h"
#include "MsgChangeModeTo3D.h"

static Hedgehog::Math::CVector savedPos = { 0.0f, 0.0f, 0.0f };
static Hedgehog::Math::CQuaternion savedRot = { 0.0f, 0.0f, 0.0f, 0.0f };
static Hedgehog::Base::CSharedString savedState = "";

HOOK(void, __fastcall, CPlayerSpeedUpdate, 0xE6BF20, Sonic::Player::CPlayerSpeed* This, void* _, const hh::fnd::SUpdateInfo& updateInfo)
{
    const Sonic::SPadState& padState = Sonic::CInputState::GetInstance()->GetPadState();
    const auto ctx = Sonic::Player::CPlayerSpeedContext::GetInstance();
    const auto state = This->m_StateMachine.GetCurrentState()->GetStateName();
    bool allowSaveState = This->m_StateMachine.GetCurrentState()->GetStateName() != "TrickJump" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "Goal" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "GoalAir" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "Grind" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "GrindSquat" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "GrindLandJumpShort" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "GrindSwitch" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "GrindDamageMiddle" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "GrindToWallWalk" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "GrindJumpSide" &&
        This->m_StateMachine.GetCurrentState()->GetStateName() != "SpecialJump";

    //printf("%s\n", ctx->m_pPlayer->m_StateMachine.GetCurrentState()->GetStateName());
    //printf("%d\n", allowSaveState);

    if (GetAsyncKeyState(0x42) & 1) // B
    {
        savedPos = ctx->m_spMatrixNode->m_Transform.m_Position;
        savedRot = ctx->m_spMatrixNode->m_Transform.m_Rotation;
        if (allowSaveState) savedState = ctx->m_pPlayer->m_StateMachine.GetCurrentState()->GetStateName();
    }

    if (GetAsyncKeyState(0x4E) & 1) // N
    {
        ctx->m_pPlayer->SendMessageSelfImm<MsgChange3DMode>();
        ctx->ChangeState(savedState);

        Sonic::Message::MsgSetPosition msg(savedPos);
        msg.m_Position.y() += 0.5f;
        Sonic::Message::MsgSetRotation msgRot(savedRot);

        ctx->m_pPlayer->SendMessageImm(ctx->m_pPlayer->m_ActorID, msg);
        ctx->m_pPlayer->SendMessageImm(ctx->m_pPlayer->m_ActorID, msgRot);
    }

	originalCPlayerSpeedUpdate(This, _, updateInfo);
}

void RememberPosition::applyPatches() 
{
    INSTALL_HOOK(CPlayerSpeedUpdate);
}