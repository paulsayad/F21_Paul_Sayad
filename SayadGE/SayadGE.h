#pragma once

#include "SayadGEUtils.h"
#include "SayadGEApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

// Entry Point
// The backslash symbol makes the macro a multi line - basically next line is the same line // otherwise next line would need to have the whole macro
#define START_SAYADGE_GAME(classname) \
int main()\
{\
	classname _sayadge_game;\
	_sayadge_game.Run();\
}