set(SOURCE_FILES 
	SayadGEApp.cpp 
	GameWindow.cpp 
	GLFWimpl/GlfwImplementation.cpp
	Renderer.cpp
	Shader.cpp
	Sprite.cpp
	OpenGLimpl/OpenGLRenderer.cpp
	OpenGLimpl/OpenGLShader.cpp
	OpenGLimpl/OpenGLSprite.cpp
)

set(HEADER_FILES 
	SayadGE.h 
	SayadGEApp.h 
	SayadGEUtils.h 
	WindowImplementation.h 
	GameWindow.h 
	GLFWimpl/GlfwImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Sprite.h
	SpriteImplementation.h
	OpenGLimpl/OpenGLRenderer.h
	OpenGLimpl/OpenGLShader.h
	OpenGLimpl/OpenGLSprite.h
)

add_library(sayadge_lib  SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(sayadge_lib PRIVATE pch.h)

add_definitions(-DSAYADGE_LIB)

target_link_libraries(sayadge_lib glfw glad stbi)

include_directories(../glfw/include)
include_directories(../SayadGE)
include_directories(../glad/include)
include_directories(../stbi)