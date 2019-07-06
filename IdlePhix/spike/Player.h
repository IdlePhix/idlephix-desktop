#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

namespace IdlePhix
{
	class Player
	{
		public:
			Player();

			~Player() { }

			void update(float deltaTime);
			float getResourceAmount();
			void addItemToInventory(std::string name, int amount);
			int getItemCount(std::string name);
		private:
			std::map<std::string, int> inventory;

			// Resource bla, will most likely be moved soon
			/// <summary>
			/// Amount of resources the player has.
			/// </summary>
			float resourceAmount;
			/// <summary>
			/// Increment resource by this value every
			/// <see cref="incrementPeriod">incrementPeriod.</see>
			/// </summary>
			int incrementValue;
			/// <summary>
			/// Increment resources at this interval (in seconds).
			/// </summary>
			float incrementPeriod;
	};
}

#endif