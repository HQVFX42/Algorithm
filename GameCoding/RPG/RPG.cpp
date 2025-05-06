#include <iostream>
#include "Item.h"
#include "Inventory.h"

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

		bool bSuccess = Inventory::GetInstance()->AddItem(item);
		if (bSuccess)
		{
			std::cout << "Added item to inventory" << std::endl;
		}
		else
		{
			std::cout << "Failed to add item to inventory" << std::endl;
			delete item;
		}

		//ItemType itemType = item->GetItemType();
		//if (itemType == IT_Weapon)
		//{
		//	Weapon* weapon = (Weapon*)item;
		//	weapon->GetAttackPower();
		//}
		//else if (itemType == IT_Armor)
		//{
		//	Armor* armor = (Armor*)item;
		//	armor->GetDefensePower();
		//}
	}

	for (int i = 0; i < 20; i++)
	{
		int randIndex = rand() % MAX_SLOT;
		Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);
		if (item and Inventory::GetInstance()->RemoveItem(item))
		{
			std::cout << "Removed item from inventory" << std::endl;
		}
	}

	return 0;
}