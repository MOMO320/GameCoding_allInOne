#pragma once 
#include "Enums.h"

// ********************** 
//         Item 
// ********************** 
class Item
{
protected:
//	Item();	// �⺻ ������
	Item(ItemType itemType);
	// �θ� ��ü��� �ϸ� �Ҹ��� �Լ��� virtual�� �ʼ������� ������
	// �θ� ��ü�� virtual�� ������ �������� ����� ���� ��ü�� �Ҹ��ڰ� �ҷ����� �ʴ´�.
	// �׷��� �޸� ������ �Ͼ��.
public:
	virtual ~Item(); 
public:
	virtual void PrintInfo();
	ItemType GetItemType() { return _itemType; }
protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _rarity = IR_Normal;
	ItemType _itemType = IT_None;
};

// ********************** 
//         Weapon
// ********************** 
class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon() override;

	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; }

	virtual void PrintInfo() override;

private:
	int _damage = 0;
};

// ********************** 
//         Armor 
// ********************** 
class Armor : public Item
{
public:
	Armor();
	virtual ~Armor() override;

	void SetDefence(int defence) { _defence = defence; }
	int GetDefence() { return _defence; }

	virtual void PrintInfo() override;

private:
	int _defence = 0;
};