#include <iostream>

using namespace std;

void Test()
{

}

void AddHp(int* hp, int value)
{
	*hp += value;
}

int main()
{
	int hp = 100;

	// [Ÿ��]* [�̸�];
	// - * = ������ (8����Ʈ)
	// - �����ʹ� �ּҰ��� �� �� �ٱ���
	// - �ּҰ��� Ÿ�� ���� -> ������ �ִ���?
	int* ptr = &hp;
	
	int** pptr = &ptr;

	cout << "&hp : " << &hp << endl;
	cout << "ptr : "<<ptr << endl;
	cout << "&ptr : " << &ptr << endl;
	cout << "*ptr : " << *ptr << endl;
	cout << "---------------------------------" << endl;
	cout << "pptr : " << pptr << endl;
	cout << "&pptr : " << &pptr << endl;
	cout << "*pptr : " << *pptr << endl;
	cout << "**ptr : " << **pptr << endl;

	cout << hp << endl;
}