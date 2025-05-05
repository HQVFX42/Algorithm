#include <iostream>
#include "Item.h"

Item* DropItem()
{
	//std::cout << "Item dropped!\n";

	if (rand() % 2 == 0)
	{
		Weapon* weapon = new Weapon();
		return weapon;
	}
	else
	{
		Armor* armor = new Armor();
		return armor;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	for (size_t i = 0; i < 100; i++)
	{
		Item* item = DropItem();
		item->PrintItemInfo();

		ItemType itemType = item->GetItemType();
		if (itemType == IT_Weapon)
		{
			Weapon* weapon = (Weapon*)item;
			weapon->GetAttackPower();
		}
		else if (itemType == IT_Armor)
		{
			Armor* armor = (Armor*)item;
			armor->GetDefensePower();
		}
	}

	return 0;
}