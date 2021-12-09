#pragma once

#include "Sprite.h"
#include "Shader.h"

namespace SayadGE
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Sprite& sprite,
			int xPos, int yPos,		// bottom left corner of the sprite
			int width, int height,
			Shader& shader) = 0;
		virtual void ClearFrame() = 0;
		virtual ~RendererImplementation() {};
	};
}