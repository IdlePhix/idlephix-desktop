#include "../include/Player.h"


IdlePhix::Player::Player(
	std::string playerName, std::string playerHomeTown, std::string playerRace,
	std::string playerGender, int playerLevel, int playerExp) :
	name(playerName), homeTown(playerHomeTown), race(playerRace),
	gender(playerGender), level(playerLevel), experience(playerExp)
{
	// Every player starts with some initial items
	inventory.addItem(1); // Add wood to inventory
}

void IdlePhix::Player::update(float deltaTime)
{
	// Look up item and its increment value
	for (auto &pair : inventory.getItems())
	{
		auto it = itemLookupTable.find(pair.first);
		if (it != itemLookupTable.end())
		{
			it->second.amountBuffer += it->second.incrementPerSecond * deltaTime;
			if (it->second.amountBuffer >= 1)
			{
				inventory.incrementItemAmount(pair.first, 1);
				it->second.amountBuffer = 0.0;
			}
			it->second.update(deltaTime);
		}
	}
}

/*
float IdlePhix::Player::getResourceAmount()
{
	return m_resourceAmount;
}

void IdlePhix::Player::addItemToInventory(Item item, int amount) {
	if (m_inventory.hasItem(item)) {
		m_inventory.getItem(item).setAmount(amount);
	}
	else {
		m_inventory.addItem(item, amount);
	}
	// auto it = inventory.find(name)
	/*
	std::map<std::string, int>::iterator inventoryIterator = inventory.find(name);
	if (inventoryIterator != inventory.end())
	{
		// If the item is already in the player's inventory, increment its current amount
		inventoryIterator->second += amount;
	}
	else
	{
		// Add item to inventory, with specified amount
		inventory[name] = amount;
	}
	*/
// }

/*
int IdlePhix::Player::getItemAmount(Item item)
{
	if (m_inventory.hasItem(item))
		return m_inventory.getItem(item).getAmount();
	else
		return 0;
}

IdlePhix::Inventory IdlePhix::Player::getInventory()
{
	return m_inventory;
}*/
