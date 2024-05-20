#include <iostream>
using namespace std;

//��ü����(Objectr Oriented Programming)
// ������ + ����

// ���赵!
class Object
{
	//���� ���� �Լ�
	virtual void Shout() = 0;
};

// �������̽�(�߻�Ŭ����)
class IFly
{
	virtual void Fly() = 0;
	virtual void Land() = 0;
};

// ���� ���(c++������ �������ؼ� ��� ���� �ʴ´�.) / interface�� �߰����൵ ������.
// Is-A? Has-A?
class Player : public Object, public IFly
{
public:
	Player() {}
	~Player() {}

	virtual void Shout() override {}
	virtual void Fly() override {}
	virtual void Land() override {}

	void Move();
	void SetHP(int hp) { this->_hp = hp; }
	
public:

private:
	int _hp = 10;
};

void FlyTest(IFly* fly)
{

}

void AddObject(Player* player)
{
	player->Shout();
}

void Test(Player* player)
{

}

int main()
{
	Player p;
	FlyTest(&p);
}