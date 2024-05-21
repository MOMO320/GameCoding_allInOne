#include <iostream>
using namespace std;

//Casting

class Player
{
public:

};

class Knight : public Player
{
public:
	Knight():hp(100),defence(30) { cout << "Knight()" << endl; }
	~Knight() { cout << "~Knight()" << endl; }
public:
	int hp;
	int defence;

};

class Dog
{
public:
	Dog():age(3),size(20) { cout << "Dog()" << endl; }
	~Dog() { cout << "~Dog()" << endl; }
	
public:
	int age;
	int size;
};

int main()
{
	// C 스타일 캐스팅

	{
		// 값 타입 변환(명시적)
		// 특징) 의미를 유지하기 위해서 원본 객체와 다른 비트열 재구성
		{
			int a = 123456789;
			float b = (float)a;
			int c = 0;
		}

		// 참조 타입 변환
		{
			int a = 123456789;
			float b = (float&)a;
			int c = 0;
		}

		// 안전한 변환(의미가 100% 일치)
		{
			int a = 123456789;
			__int64 b = (__int64)a;
			int c = 0;
		}

		// 불안전한 변환
		{
			int a = 123456789;
			short b = (short)a;
			int c = 0;
		}

		// 암시적(생략하면)
		{
			int a = 123456789;
			float b = a;
		}
	}

	Knight* k = new Knight();

	// 아래와 같이 대입 할 경우 엉뚱한 주소에 데이터를 가르키고 있게 됩니다.
	Dog* dog = (Dog*)k;
	// 값을 확인해 보면 dog의 초기화한 값이 아닌 Knight의 주소를 바라 보고 있기 때문에
	// age = 100 , size = 30 인것을 확인 할 수 있습니다.
	
	// dog->age를 1000으로 변경하면 원래 주소의 데이터인 Knight의 hp의 값이 1000으로
	// 변경 된것을 확인 할 수 있다.
	dog->age = 1000;
	cout << dog->age << endl;
}