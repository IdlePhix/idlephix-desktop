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
	int resourcesToAdd = (int)(incrementValue * (deltaTime / incrementPeriod));
	resourceAmount += incrementValue * (deltaTime / incrementPeriod);
	addItemToInventory("Wood", resourcesToAdd);
}

float IdlePhix::Player::getResourceAmount()
{
	return resourceAmount;
}

void IdlePhix::Player::addItemToInventory(std::string name, int amount)
{		
	// auto it = inventory.find(name);
	std::map<std::string, int>::iterator itemIterator = inventory.find(name);
	if (itemIterator != inventory.end())
		// If the item is already in the player's inventory, increment its current amount
		itemIterator->second += amount;
	else
		inventory[name] = amount;
}

int IdlePhix::Player::getItemCount(std::string name)
{
	std::map<std::string, int>::iterator itemIterator = inventory.find(name);
	if (itemIterator != inventory.end())
		// If the item is already in the player's inventory, increment its current amount
		return itemIterator->second;
	else
		return 0;
}
