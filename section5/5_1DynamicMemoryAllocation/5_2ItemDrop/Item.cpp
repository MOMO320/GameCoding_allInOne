#include "Item.h"
#include <iostream>
using namespace std;
// ********************** 
//         Item 
// ********************** 
//Item::Item()
//{
//	int randValue = rand() % 100;
//
//	if (randValue < 50)
//	{
//		_rarity = IR_Normal;
//	}
//	else if (randValue < 80)
//	{
//		_rarity = IR_Rare;
//	}
//	else
//	{
//		_rarity = IR_Unique;
//	}
//}

Item::Item(ItemType itemType) : _itemType(itemType)
{
	int randValue = rand() % 100;

	if (randValue < 50)
	{
		_rarity = IR_Normal;
	}
	else if (randValue < 80)
	{
		_rarity = IR_Rare;
	}
	else
	{
		_rarity = IR_Unique;
	}
}

Item::~Item()
{

}

void Item::PrintInfo()
{
	switch (_rarity)
	{
	case IR_Normal:
		cout << "[희귀도] 일반" << endl;
		break;
	case IR_Rare:
		cout << "[희귀도] 레어" << endl;
		break;
	case IR_Unique:
		cout << "[희귀도] 유니크" << endl;
		break;
	default:
		break;
	}
}
// ********************** 
//         Weapon
// ********************** 
Weapon::Weapon() : Item(IT_Weapon) // 기본생성자가 없기 때문에 기타 생성자를 불러오도록 처리
{
	switch (_rarity)
	{
	case IR_Normal:
		_damage = 1 + rand() % 5;
		break;
	case IR_Rare:
		_damage = 10 + rand() % 20;
		break;
	case IR_Unique:
		_damage = 50 + rand() % 40;
		break;
	}
}

Weapon::~Weapon()
{
}
void Weapon::PrintInfo()
{
	// 부모의 함수도 호출 하고 싶으면 부모 함수를 부르면 된다.
	
	cout << "************************************" << endl;
	cout << "[아이템 타입] : 무기 " << endl;
	cout << "[공격력] : " << _damage << endl;
	Item::PrintInfo();
	cout << "************************************" << endl;
}
// ********************** 
//         Armor 
// ********************** 
Armor::Armor() : Item(IT_Armor)	// 기본생성자가 없기 때문에 기타 생성자를 불러오도록 처리
{
	switch (_rarity)
	{
	case IR_Normal:
		_defence = 1 + rand() % 3;
		break;
	case IR_Rare:
		_defence = 2 + rand() % 4;
		break;
	case IR_Unique:
		_defence = 3 + rand() % 5;
		break;
	}
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{
	cout << "************************************" << endl;
	cout << "[아이템 타입] : 방어구 " << endl;
	cout << "[방어력] : " << _defence << endl;
	Item::PrintInfo();
	cout << "************************************" << endl;
}
