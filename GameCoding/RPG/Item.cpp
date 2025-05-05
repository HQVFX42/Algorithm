#include "Item.h"
#include <iostream>

Item::Item(ItemType itemType)
	:_itemType(itemType)
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

Weapon::Weapon() : Item(IT_Weapon)
{
	switch (_itemRarity)
	{
	case IR_None:
		break;
	case IR_Common:
		_attackPower = rand() % 5 + 1;
		break;
	case IR_Uncommon:
		_attackPower = rand() % 10 + 5;
		break;
	case IR_Rare:
		_attackPower = rand() % 15 + 10;
		break;
	case IR_Epic:
		_attackPower = rand() % 20 + 25;
		break;
	case IR_Legendary:
		_attackPower = rand() % 30 + 50;
		break;
	default:
		break;
	}
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

Armor::Armor() : Item(IT_Armor)
{
	switch (_itemRarity)
	{
	case IR_None:
		break;
	case IR_Common:
		_defensePower = rand() % 5 + 1;
		break;
	case IR_Uncommon:
		_defensePower = rand() % 10 + 5;
		break;
	case IR_Rare:
		_defensePower = rand() % 15 + 10;
		break;
	case IR_Epic:
		_defensePower = rand() % 20 + 25;
		break;
	case IR_Legendary:
		_defensePower = rand() % 30 + 50;
		break;
	default:
		break;
	}
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
