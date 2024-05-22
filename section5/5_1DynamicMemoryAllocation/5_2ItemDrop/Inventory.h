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
	// Q. 멤버 변수의 메모리 위치
	// A1. 객체를 동적할당 할 경우 -> 힙 영역(다만, 객체의 주소를 가지고 있는 녀석은 스택 영역에)
	// A2. 객체를 정적할당 할 경우 -> 스택 영역
	// A3. 객체를 전역으로 만들었을 경우 -> 메모리 영역
	//int hp;
	//int mp;

	// 포인터를 들고 있는것은 주소값을 가지고 있다는 뜻 
	// 그렇기 때문에 메모리 관리하기 좋다.
	Item* _items[MAX_SLOT];
	int _itemCount = 0;

	static Inventory* s_instance;
};

