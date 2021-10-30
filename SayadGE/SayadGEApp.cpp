#include "pch.h"
#include "SayadGEApp.h"

namespace SayadGE
{
	// Starts the game 
	void SayadGEApp::Run()
	{
		std::cout << "SayadGE is running..." << std::endl;

		// Game Loop
		while (true)
		{
			OnUpdate();
		}
	}

	void SayadGEApp::OnUpdate()
	{

	}

	SayadGEApp::SayadGEApp()
	{

	}
}
