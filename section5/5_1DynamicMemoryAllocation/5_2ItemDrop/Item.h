#pragma once 
#include "Enums.h"

// ********************** 
//         Item 
// ********************** 
class Item
{
protected:
//	Item();	// 기본 생성자
	Item(ItemType itemType);
	// 부모 객체라고 하면 소멸자 함수에 virtual을 필수적으로 붙이자
	// 부모 객체에 virtual을 붙이지 않으면음 상속을 받은 객체의 소멸자가 불러지지 않는다.
	// 그러면 메모리 누수가 일어난다.
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