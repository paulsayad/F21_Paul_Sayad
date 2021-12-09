#pragma once

#include "RendererImplementation.h"
#include "Sprite.h"
#include "Shader.h"

namespace SayadGE
{
	class OpenGLRenderer : public RendererImplementation
	{
	public:
		OpenGLRenderer();
		virtual void Draw(Sprite& sprite,
			int xPos, int yPos,		// bottom left corner of the sprite
			int width, int height,
			Shader& shader) override;
		virtual void ClearFrame() override;
	};
}