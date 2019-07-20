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

			// TODO: Constructor is a bit verbose?
			Player(
				std::string playerName,
				std::string playerHomeTown,
				std::string playerRace,
				std::string playerGender,
				int playerLevel = 1,
				int playerExp = 0
			);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Player() { }

			void update(float deltaTime);

			// TODO: temporarily public for Game's update() method
			Inventory inventory;
		private:
			std::string name;
			std::string homeTown;
			std::string race;
			std::string gender;
			int level;
			int experience;

			// Map of item ID to a double that specifies how many of the item the player earns per second
			std::map<unsigned int, double> incrementValues;
	};
}

#endif