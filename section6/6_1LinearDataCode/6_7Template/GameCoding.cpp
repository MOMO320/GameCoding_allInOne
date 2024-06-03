#include <iostream>
using namespace std;


/*
	Template : 템플릿
	런타임 중이 아닌 컴파일러가 빌드를 하면서 문제를 발견 할 수 있다.
	실시간으로 문제를 확인 할 수 없다.

	사용하지 않으면 템플릿의 함수를 만들지 않는다. 그렇기 때문에 문제를
	바로 확인 할 수 없다.

	1. 함수 템플릿 :  실제로 별도의 함수를 파준다.
	2. 클래스 템플릿

	- 템플릿
	- 특수화


*/

//----------------------- 함수 템플릿 -----------------------------------
// 조커카드 1개
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

// 특정 데이터형일때 내가 원하는 방향으로 작성 할 수 있다.
template<>
void Print(int a)
{
	cout << "int : " << a << endl;
}

//------------------------- 클래스 템플릿 -------------------------------------

// template<typename T = int , int SIZE = 100> <- 이런식으로 초기화도 가능함
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

// 특수화된 클래스
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