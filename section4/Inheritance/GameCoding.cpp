#include <iostream>

using namespace std;

// 객체지향 (Object Oriented Programming)
// 데이터 + 로직

// OOP 3대 요소
// - 상속성 << inheritance  (코드 재사용,
// - 은닉성
// - 다형성

enum PlayerType
{
	KNIGHT = 0,
	MAGE = 1,
	ARCHER = 2,
};

/// 아래의 예처럼 상속 구조를 미리 생각해 놓는게 좋다.

// GameObject
// - Creature(최상위 객체)
// --Player, Monster, Npc, Pet(상위 객체)

// Projectile
// --Arrow, Fireball
// - Env

//Item
// - Weapon
// -- Sword, Bow, Lance

// - Armor
// --Helmet, Boots, Armor, Glove

// 부모 클래스
// Is-A(~ 입니까?) vs Has-A(~가지고 있습니까?)
// Is-A 는 상속 한다.
class Player
{
public:
	void Move() {}
	void Attack() {}
	void Die() {}

public:
	int _type;
	int _hp;
	int _attack;
	int _defence;
};

// 설계도
class Knight : public Player
{
public:

public:
	
};

class Archer : public Player
{
public:

public:
	int _arrowCount;
};


class Mage : public Player
{
public:

public:
	int _mp;
};

void Fight(Player* p1, Player* p2)
{
	p1->_hp -= p2->_attack;

	//캐스팅을 통해 하위 객체의 데이터에 접근 가능
	Knight* kPtr = (Knight*)p1;
	Mage* mPtr = (Mage*)p2;

	int mp = mPtr->_mp;	
}

int main()
{
	Knight k1;
	k1._hp;

	Mage m1;
	m1._mp;

	// 주소를 담아서 관리한다.(플레이어로 간주 하겠다.)
	Player* p1 = &k1;	
	Knight* kPtr = (Knight*)p1;

	Player* p2 = &m1;

	Fight(&k1, &m1);
}