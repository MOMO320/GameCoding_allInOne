#include <iostream>
#include "Item.h"
#include "Inventory.h"
using namespace std;

// ������ ���

// [�ý���] ���͸� ���� �� , �������� ������.
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
		//	// C ��Ÿ�� ĳ����(����ȯ)
		//	Weapon* weapon = (Weapon*)item;
		//	weapon->GetDamage();
		//}
		//else if (itemType == IT_Armor)
		//{
		//	// C ��Ÿ�� ĳ����(����ȯ)
		//	Armor* armor = (Armor*)item;
		//	armor->GetDefence();
		//}
		
	}


}
