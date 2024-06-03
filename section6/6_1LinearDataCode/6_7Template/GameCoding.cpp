#include <iostream>
using namespace std;


/*
	Template : ���ø�
	��Ÿ�� ���� �ƴ� �����Ϸ��� ���带 �ϸ鼭 ������ �߰� �� �� �ִ�.
	�ǽð����� ������ Ȯ�� �� �� ����.

	������� ������ ���ø��� �Լ��� ������ �ʴ´�. �׷��� ������ ������
	�ٷ� Ȯ�� �� �� ����.

	1. �Լ� ���ø� :  ������ ������ �Լ��� ���ش�.
	2. Ŭ���� ���ø�

	- ���ø�
	- Ư��ȭ


*/

//----------------------- �Լ� ���ø� -----------------------------------
// ��Ŀī�� 1��
template<typename T>
void Print(T a)
{
	cout << a << endl;
}

void PrintInt()
{

}

void PrintFloat(float a)
{

}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

// Ư�� ���������϶� ���� ���ϴ� �������� �ۼ� �� �� �ִ�.
template<>
void Print(int a)
{
	cout << "int : " << a << endl;
}

//------------------------- Ŭ���� ���ø� -------------------------------------

// template<typename T = int , int SIZE = 100> <- �̷������� �ʱ�ȭ�� ������
template<typename T, int SIZE>
class RandomBox
{
public:
	T GetRandomData()
	{
		int index = rand() & SIZE;
		return data[index];
	}
public:
	T data[SIZE];
};

// Ư��ȭ�� Ŭ����
//template<>
//class RandomBox<int>
//{
//public:
//	int GetRandomData()
//	{
//		int index = rand() & 100;
//		return data[index];
//	}
//};

int main()
{
	Print<int>(1);
	Print<float>(3.14f);
	Print<const char*>("Hello World!");

	Print<int, const char*>(1, "YYH");

	RandomBox<int, 100> rb1;
	RandomBox<float, 20> rb2;
}