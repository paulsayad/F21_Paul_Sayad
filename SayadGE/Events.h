#pragma once

#include "SayadGEUtils.h"

namespace SayadGE
{
	class SAYADGE_API KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;

	private:
		int mKeyCode{ -1 };
	};
}