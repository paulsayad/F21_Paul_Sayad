#pragma once

#include "SayadGEUtils.h"

namespace SayadGE
{
	class KeyPressedEvent
	{
	public:
		KeyPressedEvent(int keyCode);
		int GetKeyCode() const;

	private:
		int mKeyCode{ -1 };
	};
}