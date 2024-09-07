#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

class MsgChange3DMode : public Hedgehog::Universe::Message
{
public:
    HH_FND_MSG_MAKE_TYPE(0x167F5EC);

    bool m_field;
};