#include "pch.h"

#include "OpenGLRenderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace SayadGE
{
	OpenGLRenderer::OpenGLRenderer()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Glad failed to initialize" << std::endl;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRenderer::Draw(Sprite& sprite, 
		int xPos, int yPos, 
		int width, int height, 
		Shader& shader)
	{
		float vertices[] = {
				//	COORDINATES						TEXTURE COORDS
				xPos,			yPos,				0.0f, 0.0f,		// bottom left  
				xPos,			yPos + height,		0.0f, 1.0f,		// top left 
				xPos + width,	yPos,				1.0f, 0.0f,		// bottom right
				xPos + width,	yPos + height,		1.0f, 1.0f		// top right 
		};

		unsigned indices[] = {
			0, 1, 2, // first triangle
			1, 2, 3  // second triangle
		};

		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);		// Generates vertex array object
		glGenBuffers(1, &VBO);			// Generates buffers
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		sprite.Bind();
		shader.Use();
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // first # of elements from indices, second # offset
	}

	void OpenGLRenderer::ClearFrame()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}