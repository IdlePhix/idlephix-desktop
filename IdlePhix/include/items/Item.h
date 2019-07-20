#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace IdlePhix
{
	enum ItemType
	{
		ITEM_RAW_MATERIAL,
		ITEM_EQUIPMENT,
		ITEM_ARMOR,
		ITEM_CONSUMABLE,
		ITEM_CURRENCY
	};

	struct ItemEnchantment
	{
		// TODO
		std::string name;
	};

	struct Gemstone
	{
		// TODO
		std::string name;
	};

	/// <summary> Struct for game items. </summary>
	struct Item
	{
		unsigned int id;
		std::string name;
		ItemType type;
		std::string description;
		// int amount; // TODO make it a double?
		// std::string skillReward;
		int expReward;
		// int cost; // buy price
		// int value; // sell price

		ItemEnchantment majorEnchantment;
		ItemEnchantment minorEnchantment;

		Gemstone gemstoneSlot1;
		Gemstone gemstoneSlot2;
		Gemstone gemstoneSlot3;
		Gemstone gemstoneSlot4;
		Gemstone gemstoneSlot5;
		Gemstone gemstoneSlot6;

		float amountBuffer = 0.0;
		float incrementPerSecond = 1; // TODO set to 0 initially

		/// <summary>
		/// Width of the item's rectangle.
		/// </summary>
		// float m_rectWidth;
		/// <summary>
		/// Height of the item's rectangle.
		/// </summary>
		// float m_rectHeight;

		/// <summary>
		/// Texture for the item.
		/// </summary>
		// sf::Texture texture;

		/// <summary>
		/// Pure virtual method to handle events of the item.
		/// </summary>
		// virtual void handleEvents() = 0;

		/// <summary>
		/// Updates the item state.
		/// </summary>
		///
		/// <param name="deltaTime">
		/// The time elapsed between frames (in seconds).
		/// </param>
		void update(float deltaTime)
		{
			/*
			amountBuffer += incrementPerSecond * deltaTime;
			if (amountBuffer >= 1)
			{
				amount += 1;
				amountBuffer = 0.0;
			}*/
			// TODO pass for now
			return;
		}

		/// <summary>
		/// Pure virtual method for drawing the item.
		/// </summary>
		// virtual void draw() = 0;

		friend bool operator==(const Item& lhs, const Item& rhs)
		{
			return lhs.id == rhs.id;
		}
	};
}

#endif