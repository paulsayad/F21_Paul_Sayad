#include "MyGameApp.h"

MyGameApp::MyGameApp() : mHero("Assets/Textures/Protector.png", 15, 10, 10), mScore(0), mBackground("Assets/Textures/Background.png", 0, 0, 0), mFrameCounter(0)
{
	mShader.Load("Assets/Shaders/myVertexShader.glsl", "Assets/Shaders/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);

	std::string numbers[] = { "zero.png", "one.png", "two.png", "three.png", "four.png", "five.png", "six.png", "seven.png", "eight.png", "nine.png"};
	for (int i = 0; i < 20; i++)
	{
		if(i < 10) mDigits.push_back(Unit{ "Assets/Textures/" + numbers[i % 10], 415, 700, 0});
		else mDigits.push_back(Unit{ "Assets/Textures/" + numbers[i % 10], 385, 700, 0 });
	}
}

void MyGameApp::OnUpdate()
{
	// Updates Hero's Position
	mHero.UpdatePosition();

	// Update Existing Viruses
	for (auto& virus : mViruses)
	{
		virus.UpdatePosition();
	}

	// Update Existing Bullets
	for (auto& bullets : mBullets)
	{
		bullets.UpdatePosition();
	}

	// Introduce New Virus Every Second
	if (mFrameCounter % FRAMES_PER_SECOND == 0 && mViruses.size() < 10)
	{
		int newX{ rand() % 700 };		// Viruses come from the top, but different X's axises
		int speed{ 5 + rand() % 5 };	// Viruses have random speeds

		mViruses.push_back(Unit{ "Assets/Textures/Alien.png", newX, 850, speed});
		mViruses.back().SetDirection(Unit::Direction::Down);
	}

	// Checks collisions for bullets with viruses, as well as bullets and virus hitting their respective ends of the screen
	auto bulletIt = mBullets.begin();
	int bulletIndex{ 0 };

	while (bulletIt != mBullets.end())
	{
		auto virusIt = mViruses.begin();
		bool hitVirus = false;

		while (virusIt != mViruses.end())
		{
			if (mBullets[bulletIndex].CollideWith(*virusIt))
			{
				virusIt = mViruses.erase(virusIt);
				hitVirus = true;
				if(mScore < 100) mScore = mScore + 1;
			}
			else {
				virusIt++;
			}
		}

		if (mBullets[bulletIndex].GetPosY() == 700 || hitVirus == true)
		{
			bulletIt = mBullets.erase(bulletIt);
		}
		else {
			bulletIt++;
			bulletIndex++;
		}
	}

	// Deletes viruses that reached the end
	auto virusIt = mViruses.begin();
	int virusIndex{ 0 };

	while (virusIt != mViruses.end())
	{
		if (mViruses[virusIndex].GetPosY() < -50)
		{
			virusIt = mViruses.erase(virusIt);
			if (mScore > 0) mScore = mScore - 1;
		}
		else {
			virusIt++;
			virusIndex++;
		}
	}

	// Draws all the units - From Background in the foreground to Score ontop of everything
	mBackground.Draw(mShader);

	for (auto& virus : mViruses)
		virus.Draw(mShader);

	for (auto& bullet : mBullets)
		bullet.Draw(mShader);

	mHero.Draw(mShader);

	// Draws the score 
	mDigits[mScore % 10].Draw(mShader);
	mDigits[(mScore / 10.0) + 10.0].Draw(mShader);

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
		case SAYADGE_KEY_SPACE:
			mBullets.push_back(Unit{ "Assets/Textures/Bullet.png", mHero.GetPosX() + 20, mHero.GetPosY(), 10 });
			mBullets.back().SetDirection(Unit::Direction::Up);
			break;
	}
}
