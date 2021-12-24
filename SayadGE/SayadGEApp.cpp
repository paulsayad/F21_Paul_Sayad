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
		
		mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

		// Game Loop
		while (true)
		{
			Renderer::ClearFrame();

			OnUpdate();

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

	void SayadGEApp::OnKeyPressed(KeyPressedEvent& event)
	{
		SAYADGE_LOG(event.GetKeyCode());
	}

	int SayadGEApp::GetGameWindowWidth() const
	{
		return mGameWindow.GetWindowWidth();
	}

	int SayadGEApp::GetGameWindowHeight() const
	{
		return mGameWindow.GetWindowHeight();
	}

	SayadGEApp::SayadGEApp()
	{
		mGameWindow.CreateWindow(800, 800, "Alien Invasion!");

		mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent& event) {
			OnKeyPressed(event);
			});

		Renderer::Init();
	}
}
