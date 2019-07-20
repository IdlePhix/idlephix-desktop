#include "../include/Player.h"

IdlePhix::Player::Player(
	std::string playerName, std::string playerHomeTown, std::string playerRace,
	std::string playerGender, int playerLevel, int playerExp) :
	name(playerName), homeTown(playerHomeTown), race(playerRace),
	gender(playerGender), level(playerLevel), experience(playerExp)
{
	// Every player starts with some initial items
	inventory.addItem(1); // Add wood to inventory
	incrementValues.insert_or_assign(1, 1); // Make Wood increase by 1 each second
}

/* TODO: This is a mess */
void IdlePhix::Player::update(float deltaTime)
{
	// Loop through all items in player's inventory
	for (auto &pair : inventory.getItems())
	{
		// Look up the item in the lookup table
		auto it = itemLookupTable.find(pair.first);
		if (it != itemLookupTable.end())
		{
			// If the item exists (which it always should?!)
			// Look up the increment stat the player has for this item, if any
			auto incrementValueIterator = incrementValues.find(pair.first);
			if (incrementValueIterator != incrementValues.end())
			{
				// Add a portion of the increment value (based on the time elapsed between frames)
				// to a buffer in the item (TODO probably should move this buffer)
				it->second.amountBuffer += incrementValueIterator->second * deltaTime;
				// If the buffer reaches 1 or above, increment the item amount and then
				// reset the buffer
				if (it->second.amountBuffer >= 1)
				{
					inventory.incrementItemAmount(pair.first, 1);
					it->second.amountBuffer = 0.0;
				}
			}
		}
	}
}
