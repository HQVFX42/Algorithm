#include "Item.h"
#include <iostream>

Item::Item()
{
	int randValue = rand() % 100;

	if (randValue < 50)
	{
		_itemRarity = IR_Common;
	}
	else if (randValue < 80)
	{
		_itemRarity = IR_Uncommon;
	}
	else if (randValue < 95)
	{
		_itemRarity = IR_Rare;
	}
	else if (randValue < 99)
	{
		_itemRarity = IR_Epic;
	}
	else
	{
		_itemRarity = IR_Legendary;
	}
}

Item::~Item()
{
}

void Item::PrintItemInfo()
{
	switch (_itemRarity)
	{
	case IR_None:
		break;
	case IR_Common:
		std::cout << "Item Rarity: Common\n";
		break;
	case IR_Uncommon:
		std::cout << "Item Rarity: Uncommon\n";
		break;
	case IR_Rare:
		std::cout << "Item Rarity: Rare\n";
		break;
	case IR_Epic:
		std::cout << "Item Rarity: Epic\n";
		break;
	case IR_Legendary:
		std::cout << "Item Rarity: Legendary\n";
		break;
	default:
		break;
	}
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

void Weapon::PrintItemInfo()
{
	std::cout << "*************************************\n";
	Item::PrintItemInfo();
	std::cout << "Weapon Attack Power: " << _attackPower << "\n";
	std::cout << "Weapon Durability: " << _durability << "\n";
	std::cout << "*************************************\n";
}

Armor::Armor()
{
}

Armor::~Armor()
{
}

void Armor::PrintItemInfo()
{
	std::cout << "*************************************\n";
	Item::PrintItemInfo();
	std::cout << "Armor Defense Power: " << _defensePower << "\n";
	std::cout << "Armor Durability: " << _durability << "\n";
	std::cout << "*************************************\n";
}
