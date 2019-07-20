#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include "items/Item.h"
#include "Logger.h"

namespace IdlePhix
{
	class Inventory
	{
		public:
			/// <summary>
			/// Default constructor.
			/// </summary>
			Inventory(int capacity = 50);

			Inventory(std::map<unsigned int, int> items, int capacity = 50);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Inventory() { };

			void addItem(unsigned int id, int amount = 1);
			void removeItem(unsigned int id);
			bool hasItem(unsigned int id);
			// bool hasItem(std::string name);
			// Item getItem(Item item);
			Item getItemById(unsigned int id);
			// Item getItemByName(std::string name);
			int getItemAmount(unsigned int id);
			void setItemAmount(unsigned int id, int amount);
			void incrementItemAmount(unsigned int id, int amount = 1);
			std::map<unsigned int, int> getItems();
			int getCapacity();
			int getAvailableCapacity();
			int getUsedCapacity();
		private:
			int m_capacity; // TODO: rename to totalCapacity?
			int m_availableCapacity;
			int m_usedCapacity;
			// ID, quantity (TODO: make quantity a double instead of int?)
			std::map<unsigned int, int> m_items;

			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger logger;			
	};
}

#endif