#include <iostream>
using namespace std;

// ��ü���� (Object Oriented Programming)
// ������ + ����
// ��� ���� �ʱ�ȭ
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
	*  ��ó�� ����
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
		//�̷��� ���� �� ��� �Ź� ��ü�� �����ڿ� �Ҹ��ڸ� ȣ���ϰ� �ȴ�.
		// ������ ��ȿ�����̴�.
		Knight k1;
		cout << i << endl;
	}

	// �ѹ��� �����ڿ� �Ҹ��ڰ� ȣ�� �ȴ�.
	Knight k2;

	for (int i = 0; i < 10; i++)
	{
		cout << "k2._hp : "<< i << endl;
	}
	// C# Knight k1 = new Knight();
	// C++ Knight k1 = new Knight();

	// �ʱ�ȭ�� ���� ������ �����Ⱚ�� ���� �ȴ�.
	//Knight k1;
	
}