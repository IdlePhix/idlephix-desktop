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
		// std::string skillReward;
		int expReward; // ????
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

		double amountBuffer = 0.0; // TODO move this

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

		// void handleEvents();
		// void update(float deltaTime);
		// void draw();

		friend bool operator==(const Item& lhs, const Item& rhs)
		{
			return lhs.id == rhs.id;
		}
	};
}

#endif