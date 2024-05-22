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

	for (int i = 0; i < MAX_SLOT; i++)
	{
		Item* item = DropItem();
		item->PrintInfo();

		if (Inventory::GetInstance()->AddItem(item))
		{
			cout << "Added Item to Inven" << endl;
		}
		else
		{
			cout << "Failed to add Item" << endl;
			delete item;	// 인벤에 넣을 수 없으니 item을 delete해줘서 메모리 누수 방지 한다.
		}
	}

	cout << "Inventory Item Count : " << Inventory::GetInstance()->GetInventoryItemCount() << endl;

	//PK 당해서 랜덤으로 일부 아이템 드랍 

	for (int i = 0; i < 20; i++)
	{
		int randIndex = rand() % MAX_SLOT;
		Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);

		if (item)
		{
			if (Inventory::GetInstance()->RemoveItem(item))
					cout << "Removed Item" << endl;
		}
	}

	{

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
