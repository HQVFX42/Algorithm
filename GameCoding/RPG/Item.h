#pragma once

#include "Enums.h"

// Item
// - Weapon
// - Armor
// - Consumable

class Item
{
protected:
	//Item();
	Item(ItemType itemType);
	virtual ~Item();

public:
	virtual void PrintItemInfo();
	ItemType GetItemType() const
	{
		return _itemType;
	}

protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _itemRarity = IR_Common;
	ItemType _itemType = IT_None;
};

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void PrintItemInfo() override;

	void SetAttackPower(int attackPower)
	{
		_attackPower = attackPower;
	}
	int GetAttackPower() const
	{
		return _attackPower;
	}

private:
	int _attackPower = 0;
	int _durability = 0;
};

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

	virtual void PrintItemInfo() override;

	void SetDefensePower(int defensePower)
	{
		_defensePower = defensePower;
	}
	int GetDefensePower() const
	{
		return _defensePower;
	}

private:
	int _defensePower = 0;
	int _durability = 0;
};