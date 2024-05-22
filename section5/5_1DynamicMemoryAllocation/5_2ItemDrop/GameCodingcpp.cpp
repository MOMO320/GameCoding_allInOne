#include <iostream>
#include "Item.h"
#include "Inventory.h"
using namespace std;

// 아이템 드랍

// [시스템] 몬스터를 잡을 때 , 아이템을 떨군다.
Item* DropItem()
{
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
	srand((unsigned)time(0));

	for (int i = 0; i < 10; i++)
	{
		Item* item = DropItem();
		item->PrintInfo();

		if(Inventory::GetInstance()->AddItem(item)

		//ItemType itemType = item->GetItemType();
		//if (itemType == IT_Weapon)
		//{
		//	// C 스타일 캐스팅(형변환)
		//	Weapon* weapon = (Weapon*)item;
		//	weapon->GetDamage();
		//}
		//else if (itemType == IT_Armor)
		//{
		//	// C 스타일 캐스팅(형변환)
		//	Armor* armor = (Armor*)item;
		//	armor->GetDefence();
		//}
		
	}


}
