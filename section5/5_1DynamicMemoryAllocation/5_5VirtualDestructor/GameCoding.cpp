#include <iostream>

using namespace std;

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}
	virtual ~Player()
	{
		cout << "~Player()" << endl;
	}

};

class Pet
{

};

class Archer : public Player
{
public:
	Archer()
	{
		_pet = new Pet();
		cout << "Archer()" << endl;
	}

	virtual ~Archer() override
	{
		cout << "~Archer()" << endl;
		delete _pet;
	}

private:
	Pet* _pet;
};

int main()
{

	while (true)
	{
		// memory leak(메모리 누수) 되지 않게 잘해야 함.

		// virtual 소멸자가 없으면, Archer의 소멸자를 호출 하지 않는다.
		// Archer 소멸자에서 pet의 메모리 해제 해주는 내용이 있는데
		// 소멸자를 호출 하지 않게 되어 프로세스 메모리가 올라가는 것을 볼 수 있다. 
		Player* player = new Archer();

		delete player;
	}
}