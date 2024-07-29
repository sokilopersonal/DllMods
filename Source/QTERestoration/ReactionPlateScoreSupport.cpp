#include "ReactionPlateScoreSupport.h"

int m_qteReactionPlateBaseScore = 1000;
int m_qteReactionPlateAddScore = 0;
HOOK(bool, __stdcall, QTEReactionPlate_PlayUIEffect, 0xE6F3E0, float* This, void* a2)
{
    bool result = originalQTEReactionPlate_PlayUIEffect(This, a2);
    if (result)
    {
        float inputTime = This[12];
        float maxTime = This[9];
        m_qteReactionPlateAddScore = max(0, (int)((maxTime - 0.5f) * 500.f * (maxTime - inputTime) / maxTime));
    }

    return result;
}

HOOK(int, __fastcall, QTEReactionPlate_CPlayerSpeedStateReactionLandEnd, 0x124B7D0, hh::fnd::CStateMachineBase::CStateBase* This)
{
    uint32_t context = (uint32_t)This->GetContextBase();
    uint32_t v3 = *(uint32_t*)(context + 2036);
    bool success = *(bool*)(v3 + 57);

    int score = m_qteReactionPlateBaseScore + m_qteReactionPlateAddScore;
    if (score > 0 && success)
    {
        ScoreGenerationsAPI::AddScore(score);
        UnleashedHUD_API::AddTrickScore(score);
        printf("[QTE] Added score \n");
    }
    m_qteReactionPlateBaseScore = 1000;
    m_qteReactionPlateAddScore = 0;

    return originalQTEReactionPlate_CPlayerSpeedStateReactionLandEnd(This);
}

void ReactionPlateScoreSupport::applyPatches()
{
    INSTALL_HOOK(QTEReactionPlate_PlayUIEffect);
    INSTALL_HOOK(QTEReactionPlate_CPlayerSpeedStateReactionLandEnd);
}