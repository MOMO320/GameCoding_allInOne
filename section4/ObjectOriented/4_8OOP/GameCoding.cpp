#include <iostream>
using namespace std;

//객체지향(Objectr Oriented Programming)
// 데이터 + 로직

// 설계도!
class Object
{
	//순수 가상 함수
	virtual void Shout() = 0;
};

// 인터페이스(추상클래스)
class IFly
{
	virtual void Fly() = 0;
	virtual void Land() = 0;
};

// 다중 상속(c++에서는 어지간해서 사용 하지 않는다.) / interface는 추가해줘도 괜찮다.
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