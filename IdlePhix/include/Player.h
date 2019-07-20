#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Inventory.h"

namespace IdlePhix
{
	class Player
	{
		public:
			// TODO temp: move these to a data file or SQLite database
			//             ID  Name            Type           Description   XP Reward
			Item goldCoin{ 0,  "GC",       ITEM_CURRENCY,     "Some money", 0 };
			Item wood{     1,  "Wood",     ITEM_RAW_MATERIAL, "Some logs",  1 };
			Item ironOre{  2,  "Iron Ore", ITEM_RAW_MATERIAL, "Some ore",   1 };

			std::map<unsigned int, Item> itemLookupTable
			{
				// TODO maybe improve
				{goldCoin.id, goldCoin},
				{wood.id, wood},
				{ironOre.id, ironOre}
			};

			Player(std::string playerName, std::string playerHomeTown, std::string playerRace, std::string playerGender, int playerLevel = 1, int playerExp = 0) :
				name(playerName), homeTown(playerHomeTown), race(playerRace), gender(playerGender), level(playerLevel), experience(playerExp)
			{
				// Every player starts with some initial items
				inventory.addItem(1); // Add wood to inventory
			}

			void update(float deltaTime)
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
							// pair.second += 1;
							it->second.amountBuffer = 0.0;
						}
						it->second.update(deltaTime);
					}
				}
			}

			Inventory inventory;
		private:
			std::string name;
			std::string homeTown;
			std::string race;
			std::string gender;
			int level;
			int experience;
	};
}

#endif