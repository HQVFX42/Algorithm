#pragma once

enum
{
	MAX_SLOT = 100,
};

class Item;

class Inventory
{
public:
	bool AddItem(Item* item);
	bool RemoveItem(Item* item);

	Item* GetItemAtSlot(int slot);

	void Clear();

	static Inventory* GetInstance();

private:
	Inventory();
	~Inventory();

	int FindEmptySlot();
	int FindItemSlot(Item* item);

private:
	struct InventoryItem
	{
		int itemId;
		int itemCount;
	};
	//std::vector<InventoryItem> _items;

	Item* _items[MAX_SLOT];
	int _itemCount = 0;

	static Inventory* s_instance;
};

