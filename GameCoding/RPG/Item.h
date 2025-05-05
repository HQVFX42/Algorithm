#pragma once

// Item
// - Weapon
// - Armor
// - Consumable

enum ItemRarity
{
	IR_None,
	IR_Common,
	IR_Uncommon,
	IR_Rare,
	IR_Epic,
	IR_Legendary,
};

class Item
{
public:
	Item();
	virtual ~Item();

	virtual void PrintItemInfo();

protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _itemRarity = IR_Common;
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