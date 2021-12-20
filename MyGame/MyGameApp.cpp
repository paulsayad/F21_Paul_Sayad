#include "MyGameApp.h"

MyGameApp::MyGameApp() : mHero("Assets/Textures/Clown.png", 0, 0, 10), mFrameCounter(0)
{
	mShader.Load("Assets/Shaders/myVertexShader.glsl", "Assets/Shaders/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);
}

void MyGameApp::OnUpdate()
{
	mHero.UpdatePosition();

	// Update Existing Viruses
	for (auto& virus : mViruses)
	{
		virus.UpdatePosition();
	}

	// Introduce New Virus Every Second
	if (mFrameCounter % FRAMES_PER_SECOND == 0 && mViruses.size() < 10)
	{
		int newX{ rand() % 700 };
		int newY{ rand() % 700 };
		
		Unit::Direction newDir;
		int dirVal{ rand() % 4 };

		if (dirVal == 0)
			newDir = Unit::Direction::Down;
		else if (dirVal == 1)
			newDir = Unit::Direction::Up;
		else if (dirVal == 2)
			newDir = Unit::Direction::Left;
		else
			newDir = Unit::Direction::Right;

		mViruses.push_back(Unit{"Assets/Textures/Virus.png", newX, newY, 10});
		mViruses.back().SetDirection(newDir);
	}

	// Check collisions
	auto it = mViruses.begin();
	while ( it != mViruses.end())
	{
		if (mHero.CollideWith(*it))
			it = mViruses.erase(it);
		else
			it++;
	}

	for (auto& virus : mViruses)
		virus.Draw(mShader);

	mHero.Draw(mShader);

	mFrameCounter++;
}

void MyGameApp::OnKeyPressed(SayadGE::KeyPressedEvent& event)
{
	switch (event.GetKeyCode())
	{
		case SAYADGE_KEY_LEFT:
			mHero.SetDirection(Unit::Direction::Left);
			break;
		case SAYADGE_KEY_RIGHT:
			mHero.SetDirection(Unit::Direction::Right);
			break;
		case SAYADGE_KEY_DOWN:
			mHero.SetDirection(Unit::Direction::Down);
			break;
		case SAYADGE_KEY_UP:
			mHero.SetDirection(Unit::Direction::Up);
			break;
	}
}
