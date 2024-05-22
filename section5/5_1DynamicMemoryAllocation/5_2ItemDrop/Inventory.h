#pragma once
#include "Item.h"

enum
{
	MAX_SLOT = 100
};

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item* item);
	bool RemoveItem(Item* item);

	Item* GetItemAtSlot(int slot);

	static Inventory* GetInstance();

private:
	int FindEmptySlot();
	int FindItemSlot(Item* item);

private:
	// Q. ��� ������ �޸� ��ġ
	// A1. ��ü�� �����Ҵ� �� ��� -> �� ����(�ٸ�, ��ü�� �ּҸ� ������ �ִ� �༮�� ���� ������)
	// A2. ��ü�� �����Ҵ� �� ��� -> ���� ����
	// A3. ��ü�� �������� ������� ��� -> �޸� ����
	//int hp;
	//int mp;

	// �����͸� ��� �ִ°��� �ּҰ��� ������ �ִٴ� �� 
	// �׷��� ������ �޸� �����ϱ� ����.
	Item* _items[MAX_SLOT];
	int _itemCount = 0;

	static Inventory* s_instance;
};

