#pragma once

#include "SayadGEUtils.h"
#include "GameWindow.h"

namespace SayadGE
{
	class SAYADGE_API SayadGEApp
	{
	public:
		void Run();					// Starts the Game
		virtual void OnUpdate();	// Happens each run of the game, creates each frame of the game 

	protected:
		SayadGEApp(); // Protected Construct - Final user cannot just create BubbleApp objects, they are expected to take our BubbleApp and inherit from it

	private:
		GameWindow mGameWindow;
	};


}


