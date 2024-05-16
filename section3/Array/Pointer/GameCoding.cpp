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

	// [타입]* [이름];
	// - * = 포인터 (8바이트)
	// - 포인터는 주소값을 담 는 바구니
	// - 주소값을 타고 가면 -> 무엇이 있느냐?
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