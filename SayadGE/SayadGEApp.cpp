#include "pch.h"

#include "SayadGEApp.h"

#include "GLFW/glfw3.h"

namespace SayadGE
{
	// Starts the game 
	void SayadGEApp::Run()
	{
		std::cout << "SayadGE is running..." << std::endl;
		
		mGameWindow.CreateWindow(800, 600, "Test");

		// Game Loop
		while (true)
		{
			OnUpdate();

			mGameWindow.SwapBuffers();

			mGameWindow.PollEvents();
		}
	}

	void SayadGEApp::OnUpdate()
	{

	}

	SayadGEApp::SayadGEApp()
	{

	}
}
