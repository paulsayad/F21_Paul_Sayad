#include "SayadGE.h" // our game engine

// Their Game class that inherits the game engine
class MyGameApp : public SayadGE::SayadGEApp
{
	// Every run on game loop - every frame
	void OnUpdate() override
	{

	}
};

START_SAYADGE_GAME(MyGameApp) // Macro for the Game Developer to start their game

