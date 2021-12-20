#pragma once

#include "SayadGE.h"
#include "Unit.h"
#include <vector>

// Their Game class that inherits the game engine
class MyGameApp : public SayadGE::SayadGEApp
{
public:
	MyGameApp();
	virtual void OnUpdate() override;	 // Every run on game loop - every frame
	virtual void OnKeyPressed(SayadGE::KeyPressedEvent& event) override;

private:
	Unit mHero;
	std::vector<Unit> mViruses;
	int mFrameCounter;
	SayadGE::Shader mShader;
};