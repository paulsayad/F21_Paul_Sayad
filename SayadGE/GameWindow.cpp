#include "pch.h"
#include "GameWindow.h"
#include "GLFWimpl/GlfwImplementation.h"

namespace SayadGE
{
	GameWindow::GameWindow()
	{
		#ifdef SAYADGE_WINDOWS
			mWindow = std::unique_ptr<WindowImplementation>{ new GlfwImplementation() };
		#elif SAYADGE_MAC
			mWindow = std::unique_ptr<WindowImplementation>{ new GlfwImplementation() };
		#elif SAYADGE_LINUX
			mWindow = std::unique_ptr<WindowImplementation>{ new GlfwImplementation() };
		#else
				#only_Windows_Linux_Mac_are_supported
		#endif

		mWindow->Init();
	}

	void GameWindow::CreateWindow(int width, int height, const std::string & name)
	{
		mWindow->CreateWindow(width, height, name);
	}

	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	int GameWindow::GetWindowWidth() const
	{
		return mWindow->GetWindowWidth();
	}

	int GameWindow::GetWindowHeight() const
	{
		return mWindow->GetWindowHeight();
	}

	void GameWindow::SetKeyPressedCallback(std::function<void(KeyPressedEvent&)> func)
	{
		mWindow->SetKeyPressedCallback(func);
	}
}