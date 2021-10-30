#include "pch.h"
#include "SayadGEApp.h"

#include "GLFW/glfw3.h"

namespace SayadGE
{
	// Starts the game 
	void SayadGEApp::Run()
	{
		std::cout << "SayadGE is running..." << std::endl;
		
		GLFWwindow* window;

		glfwInit();

		window = glfwCreateWindow(800, 600, "Test", NULL, NULL);

		// Game Loop
		while (true)
		{
			OnUpdate();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	void SayadGEApp::OnUpdate()
	{

	}

	SayadGEApp::SayadGEApp()
	{

	}
}
