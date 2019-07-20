#include <algorithm>
#include "../include/Inventory.h"

IdlePhix::Inventory::Inventory(int capacity) :
	m_capacity(capacity)
{
}

IdlePhix::Inventory::Inventory(std::map<unsigned int, int> items, int capacity) :
	Inventory(capacity)
{
	m_items = items;
}

void IdlePhix::Inventory::addItem(unsigned int id, int amount)
{
	// m_items.insert(std::pair<unsigned int, int>(id, amount));
	m_items.insert_or_assign(id, amount);
	// Update capacity values
	// TODO: take into account `amount`s of items, not just number of entries in map
	m_usedCapacity = getUsedCapacity();
	m_availableCapacity = getAvailableCapacity();
}

void IdlePhix::Inventory::removeItem(unsigned int id)
{
	// TODO
}

bool IdlePhix::Inventory::hasItem(unsigned int id)
{
	// TODO: check if better/more optimized way to do this
	auto inventoryIterator = m_items.find(id);

	if (inventoryIterator != m_items.end())
	{
		logger.log("DEBUG", "hasItem: Found item in player inventory.");
		return true;
	}
	else {
		logger.log("DEBUG", "hasItem: Did not find item in player inventory.");
		return false;
	}
}

/*
IdlePhix::Item IdlePhix::Inventory::getItem(Item item)
{
	auto inventoryIterator = m_items.find(id)
	if (inventoryIterator != m_items.end())
	{
		logger.log("DEBUG", "getItem: Found item in player inventory.");
		return *inventoryIterator;
	}
	else {
		logger.log("DEBUG", "getItem: Did not find item in player inventory.");
	}
}*/

int IdlePhix::Inventory::getItemAmount(unsigned int id)
{
	// TODO
	auto inventoryIterator = m_items.find(id);

	if (inventoryIterator != m_items.end())
	{
		// logger.log("DEBUG", "getItemAmount: Found item in player inventory.");
		return inventoryIterator->second;
	}
	else {
		logger.log("DEBUG", "getItemAmount: Did not find item in player inventory.");
		return 0;
	}
}

/* void IdlePhix::Inventory::setItemAmount(unsigned int id, int amount)
{
	// TODO
	auto inventoryIterator = m_items.find(id);

	if (inventoryIterator != m_items.end())
	{
		int index = std::distance(m_items.begin(), inventoryIterator);
		m_items.at(index) = amount;
		// logger.log("DEBUG", "setItemAmount: Found item in player inventory.");
		// inventoryIterator->second;
	}
	else {
		logger.log("DEBUG", "setItemAmount: Did not find item in player inventory.");
	}
} */

void IdlePhix::Inventory::incrementItemAmount(unsigned int id, int amount)
{
	// TODO
	auto inventoryIterator = m_items.find(id);

	if (inventoryIterator != m_items.end())
	{
		int index = std::distance(m_items.begin(), inventoryIterator);
		m_items[index] = m_items[index] + amount;
		// logger.log("DEBUG", "setItemAmount: Found item in player inventory.");
		// inventoryIterator->second;
	}
	else {
		logger.log("DEBUG", "setItemAmount: Did not find item in player inventory.");
	}
}

std::map<unsigned int, int>& IdlePhix::Inventory::getItems()
{
	return m_items;
}

int IdlePhix::Inventory::getCapacity()
{
	return m_capacity;
}

int IdlePhix::Inventory::getAvailableCapacity()
{
	return getCapacity() - getUsedCapacity();
}

int IdlePhix::Inventory::getUsedCapacity()
{
	return m_items.size();
}
