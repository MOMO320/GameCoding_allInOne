#include <iostream>
using namespace std;

// 객체지향 (Object Oriented Programming)
// 데이터 + 로직
// 멤버 변수 초기화
class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	~Player()
	{
		cout << "~Player()" << endl;
	}

};

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int  a)
	{
		_a = a;
		cout << "Inventory(int)" << endl;
	}
	~Inventory() { cout << "~Inventory()" << endl; }

public:
	int _a;
};

// Is-A?  Has-A?
class Knight : public Player
{
public :
	Knight() : _hp(0) , _inventory(100), _hpRef(_hp), _hpConst(_hp)
	/*
	*  선처리 영역
	*  Player()
	* _inventory = Inventory();
	*/
	{
		cout << "Knight()" << endl; 
	}
	~Knight() { cout << "~Knight()" << endl; }
public:
	int _hp;
	int _defence = 20;
	int& _hpRef;
	const int _hpConst;
	Inventory _inventory;
};

int main()
{
	int value;

	for (int i = 0; i < 10; i++)
	{
		value = i;
		cout << "Hello World" << value << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		//이렇게 생성 할 경우 매번 객체의 생성자와 소멸자를 호출하게 된다.
		// 굉장히 비효율적이다.
		Knight k1;
		cout << i << endl;
	}

	// 한번만 생성자와 소멸자가 호출 된다.
	Knight k2;

	for (int i = 0; i < 10; i++)
	{
		cout << "k2._hp : "<< i << endl;
	}
	// C# Knight k1 = new Knight();
	// C++ Knight k1 = new Knight();

	// 초기화를 하지 않으면 쓰레기값이 들어가게 된다.
	//Knight k1;
	
}