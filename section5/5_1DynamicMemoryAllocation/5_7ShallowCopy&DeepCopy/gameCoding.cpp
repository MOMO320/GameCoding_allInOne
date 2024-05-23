#include <iostream>

using namespace std;

// 얕은 복사 vs 깊은 복사

class Pet
{
public:
	Pet() { cout << "Pet()" << endl; }
	~Pet() { cout << "~Pet()" << endl; }

	Pet(const Pet& pet) { cout << "Pet(const Pet&)" << endl; }
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	~Knight()
	{
		delete _pet;
	}
	Knight(const Knight& k)	// 복사 생성자
	{
		_hp = k._hp;

		// 깊은 복사 : 포인터, 레퍼런스의 경우 그냥 복사 하지않고
		// 새로운 주소 대상자인 객체를 만들어줘서 복사한다.
		_pet = new Pet();	
	}

	//void operator=(const Knight& k)
	//{
	//	_hp = k._hp;
	//}
public:
	int _hp = 10;
	Pet* _pet;
};

int main()
{
	Knight k1;
	k1._hp = 200;

	//Knight k2 = k1;	// 복사 생성자

	/*
		결과 : k1과 k2의 _pet 주소 값이 같다.

		ㅁ 얕은 복사 : 그냥 값을 복사 한다.
		그렇다 보니 일반적인 값들은 상관없지만 포인터 같이 주소 값을 가지고 있는 변수 복사의 경우
		같은 주소값을 공유하게 되어 하나만 수정을 해도 같이 수정이 되고,
		하나만 삭제해도 주소값을 가르키던 객체가 삭제 되어 문제가 발생하게 된다.
	*/
	Knight k2(k1);		// 복사 생성자 

	//Knight k3;			// 기본 생성자
	//k3 = k1;			// 복사 연산자
}