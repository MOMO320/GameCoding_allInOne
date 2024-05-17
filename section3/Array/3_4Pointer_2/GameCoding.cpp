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
	// [타입]* -> 포인터
	//void* ptr = nullptr;	//없는 주소라고 표현 할때 -> nullptr;

	// 포인터 연산
	// - 주소 연산자 (&)
	// - 산술 연산자 (+-)
	// - 간접 연산자 (*)
	// - 간접 멤버 연산자 (->)

	// 기본적인 산술 연산
	int hp = 100;
	hp += 50;

	// 주소 연산자(&) , 산술 연산자(+-)
	{
		// [ ][ ][ ][ ][ ][ ][ ][ ]
		int numbers[10] = { 1,2,3,4,5,6 };

		// numbers의 첫번째 주소 값을 알기 위한 방법
		// 1. 아래와 같이 배열 첫번째 인덱스 주소값을 넘겨준다.
		int* ptr = &numbers[0];
		// 2. 배열을 넣어주면 시작 주소를 알 수 있다.
		ptr = numbers;

		//ptr += 3;	// 배열의 4번째 주소로 갈 수 있다.(데이터 단위로 3칸 넘어갔다.)

		cout << *ptr << endl;
		*(ptr + 3) = 666;	  // 4번째 인덱스에 '666'의 값이 들어간것을 확인 할 수 있다.

		// *ptr = numbers[0];
		// *(ptr+3) = numbers[3]; 

		cout << ptr[3] << endl;	// 이런식으로 포인터로 배열에 접근 가능함

		int a = 10;
		int b = 20;
		Swap(&a, &b);

		//int* ptr = &a;
		//*ptr = 20;
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}


	// 간접 연산자(*) & 간접 멤버 연산자(->)
	{
		// 일반적인 변수는 '.'으로 데이터 접근 하지만, 포인터는 '->'을 통해 데이터 접근 할 수 있다.
		StatInfo monster;
		monster.hp = 100;
		monster.attack = 10;
		monster.defence = 1;

		StatInfo* ptr = &monster;

		cout << "monster HP : " << (*ptr).hp << endl;

		// 아래 두 문법은 같다.(포인터는 둘다 가능)
		//(*ptr).hp = 100;
		//ptr->hp = 100;
	}

	return 0;
}