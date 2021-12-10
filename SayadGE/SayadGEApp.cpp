#include "pch.h"

#include "SayadGEApp.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace SayadGE
{
	// Starts the game 
	void SayadGEApp::Run()
	{
		SAYADGE_LOG("SayadGE is running...");
		
		mGameWindow.CreateWindow(800, 600, "Test");
			
		Renderer::Init();

		// Shaders
		SayadGE::Shader myShader;
		myShader.Load("Assets/Shaders/myVertexShader.glsl", 
			"Assets/Shaders/myFragmentShader.glsl");
		myShader.SetVec2IntUniform("screenSize",
			mGameWindow.GetWindowWidth(),
			mGameWindow.GetWindowHeight());

		// Textures
		SayadGE::Sprite fish;
		fish.LoadImage("Assets/Textures/test.png");

		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

		// Game Loop
		while (true)
		{
			Renderer::ClearFrame();

			OnUpdate();

			Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

			std::this_thread::sleep_until(mTimeOfNextFrame);

			mGameWindow.SwapBuffers();

			mGameWindow.PollEvents();

			mTimeOfNextFrame += mFrameDuration;
		}

		Renderer::ShutDown();
	}

	void SayadGEApp::OnUpdate()
	{

	}

	SayadGEApp::SayadGEApp()
	{

	}
}
