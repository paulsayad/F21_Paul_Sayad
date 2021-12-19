#pragma once

#include "SayadGEUtils.h"
#include "GameWindow.h"

#define FRAMES_PER_SECOND 30

namespace SayadGE
{
	class SAYADGE_API SayadGEApp
	{
	public:
		void Run();						// Starts the Game
		virtual void OnUpdate();		// Happens each run of the game, creates each frame of the game 
		virtual void OnKeyPressed(KeyPressedEvent &event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;

	protected:
		SayadGEApp(); // Protected Construct - Final user cannot just create BubbleApp objects, they are expected to take our BubbleApp and inherit from it

	private:
		GameWindow mGameWindow;

		std::chrono::steady_clock::time_point mTimeOfNextFrame;
		std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
	};


}


