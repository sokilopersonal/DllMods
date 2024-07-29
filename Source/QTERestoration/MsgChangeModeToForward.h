#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgChangeModeToForward : public Hedgehog::Universe::Message
	{
	public:
		uint32_t m_value;
		bool m_enableField;
		bool m_enableField2;
		float m_value1;
		float m_value2;
		float m_value3;

		HH_FND_MSG_MAKE_TYPE(0x167F614);
	};
}