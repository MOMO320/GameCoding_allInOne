#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void Swap(int* a , int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Print(int* ptr, int count)
{

}

int main0()
{
	// [Ÿ��]* -> ������
	//void* ptr = nullptr;	//���� �ּҶ�� ǥ�� �Ҷ� -> nullptr;

	// ������ ����
	// - �ּ� ������ (&)
	// - ��� ������ (+-)
	// - ���� ������ (*)
	// - ���� ��� ������ (->)

	// �⺻���� ��� ����
	int hp = 100;
	hp += 50;

	// �ּ� ������(&) , ��� ������(+-)
	{
		// [ ][ ][ ][ ][ ][ ][ ][ ]
		int numbers[10] = { 1,2,3,4,5,6 };

		// numbers�� ù��° �ּ� ���� �˱� ���� ���
		// 1. �Ʒ��� ���� �迭 ù��° �ε��� �ּҰ��� �Ѱ��ش�.
		int* ptr = &numbers[0];
		// 2. �迭�� �־��ָ� ���� �ּҸ� �� �� �ִ�.
		ptr = numbers;

		//ptr += 3;	// �迭�� 4��° �ּҷ� �� �� �ִ�.(������ ������ 3ĭ �Ѿ��.)

		cout << *ptr << endl;
		*(ptr + 3) = 666;	  // 4��° �ε����� '666'�� ���� ������ Ȯ�� �� �� �ִ�.

		// *ptr = numbers[0];
		// *(ptr+3) = numbers[3]; 

		cout << ptr[3] << endl;	// �̷������� �����ͷ� �迭�� ���� ������

		int a = 10;
		int b = 20;
		Swap(&a, &b);

		//int* ptr = &a;
		//*ptr = 20;
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}


	// ���� ������(*) & ���� ��� ������(->)
	{
		// �Ϲ����� ������ '.'���� ������ ���� ������, �����ʹ� '->'�� ���� ������ ���� �� �� �ִ�.
		StatInfo monster;
		monster.hp = 100;
		monster.attack = 10;
		monster.defence = 1;

		StatInfo* ptr = &monster;

		cout << "monster HP : " << (*ptr).hp << endl;

		// �Ʒ� �� ������ ����.(�����ʹ� �Ѵ� ����)
		//(*ptr).hp = 100;
		//ptr->hp = 100;
	}

	return 0;
}