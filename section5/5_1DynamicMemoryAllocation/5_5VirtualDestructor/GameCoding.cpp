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
		// memory leak(�޸� ����) ���� �ʰ� ���ؾ� ��.

		// virtual �Ҹ��ڰ� ������, Archer�� �Ҹ��ڸ� ȣ�� ���� �ʴ´�.
		// Archer �Ҹ��ڿ��� pet�� �޸� ���� ���ִ� ������ �ִµ�
		// �Ҹ��ڸ� ȣ�� ���� �ʰ� �Ǿ� ���μ��� �޸𸮰� �ö󰡴� ���� �� �� �ִ�. 
		Player* player = new Archer();

		delete player;
	}
}