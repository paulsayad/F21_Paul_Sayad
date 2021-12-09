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
		std::cout << "SayadGE is running..." << std::endl;
		
		mGameWindow.CreateWindow(800, 600, "Test");
			
		Renderer::Init();

		// Shaders
		SayadGE::Shader myShader;
		myShader.Load("F:/CS/school/fourth_year/cs_39541/MyGame/SayadGE/Assets/Shaders/myVertexShader.glsl", 
			"F:/CS/school/fourth_year/cs_39541/MyGame/SayadGE/Assets/Shaders/myFragmentShader.glsl");
		myShader.SetVec2IntUniform("screenSize",
			mGameWindow.GetWindowWidth(),
			mGameWindow.GetWindowHeight());

		// Textures

		SayadGE::Sprite fish;
		fish.LoadImage("Assets/Textures/test.png");

		// Game Loop
		while (true)
		{
			Renderer::ClearFrame();

			OnUpdate();

			Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

			mGameWindow.SwapBuffers();

			mGameWindow.PollEvents();
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
