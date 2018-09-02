#include "../include/Player.h"

IdlePhix::Player::Player()
{
	// Set up for resource bla. Will most likely be moved.
	resourceAmount = 0;
	incrementValue = 1;
	incrementPeriod = 5;
}

void IdlePhix::Player::update(float deltaTime)
{
	resourceAmount += incrementValue * (deltaTime / incrementPeriod);
}

float IdlePhix::Player::getResourceAmount()
{
	return resourceAmount;
}
