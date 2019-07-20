// #include "../include/Player.h"

/*
IdlePhix::Player::Player()
{
	// Set up for resource bla. Will most likely be moved.
	m_resourceAmount = 0;
	incrementValue = 1;
	incrementPeriod = 5;

	m_wood = Wood();
	addItemToInventory(m_wood);
}

void IdlePhix::Player::update(float deltaTime)
{
	int resourcesToAdd = (int)(incrementValue * (deltaTime / incrementPeriod));
	m_resourceAmount += incrementValue * (deltaTime / incrementPeriod);
	m_inventory.getItem(m_wood).incrementAmount();
}

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

//}

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
