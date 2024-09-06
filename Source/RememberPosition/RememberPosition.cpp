#include "RememberPosition.h"

static Hedgehog::Math::CVector savedPos = { 0.0f, 0.0f, 0.0f };

FUNCTION_PTR(void, __thiscall, procMsgSetPosition, 0xE772D0, Sonic::Player::CPlayer* This, Sonic::Message::MsgSetPosition& msg);

HOOK(void*, __fastcall, UpdateApplication, 0xE7BED0, void* This, void* Edx, float elapsedTime, uint8_t a3)
{
    const Sonic::SPadState& padState = Sonic::CInputState::GetInstance()->GetPadState();
    const auto ctx = Sonic::Player::CPlayerSpeedContext::GetInstance();

    if (GetAsyncKeyState(0x42) & 1) // B
    {
        savedPos = ctx->m_spMatrixNode->m_Transform.m_Position;

        printf("SAVED POSITION \n");
    }

    if (GetAsyncKeyState(0x4E) & 1) // N
    {
        Sonic::Message::MsgSetPosition msg(savedPos);
        msg.m_Position.y() += 0.5f;

        procMsgSetPosition(ctx->m_pPlayer, msg);
    }

    void* result = originalUpdateApplication(This, Edx, elapsedTime, a3);
	return result;
}

void RememberPosition::applyPatches() 
{
    INSTALL_HOOK(UpdateApplication);
}