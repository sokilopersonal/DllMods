#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message 
{
	class MsgChangeModeTo3D : public Hedgehog::Universe::Message
	{
	public:
		bool m_field;
		HH_FND_MSG_MAKE_TYPE(0x167F5EC);
	};
}