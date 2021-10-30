#pragma once

#include "SayadGEUtils.h"
#include "WindowImplementation.h"
#include "pch.h"

namespace SayadGE
{
	class SAYADGE_API GameWindow
	{
	public:
		GameWindow();
		void CreateWindow(int width, int height, const std::string & name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;

	private:
		std::unique_ptr<WindowImplementation> mWindow;
	};
}


