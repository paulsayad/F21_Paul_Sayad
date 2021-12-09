#pragma once

#include "pch.h"
#include "SayadGEUtils.h"
#include "SpriteImplementation.h"

namespace SayadGE
{
	class SAYADGE_API Sprite
	{
	public:
		Sprite();

		void LoadImage(const std::string& pictureFile);
		int GetWidth() const;
		int GetHeight() const;
		void Bind();

	private:
		std::unique_ptr<SpriteImplementation> mSpriteImplementation;
	};
}


