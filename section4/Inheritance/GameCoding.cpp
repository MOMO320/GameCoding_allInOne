#include <iostream>

using namespace std;

// ��ü���� (Object Oriented Programming)
// ������ + ����

// OOP 3�� ���
// - ��Ӽ� << inheritance  (�ڵ� ����,
// - ���м�
// - ������

enum PlayerType
{
	KNIGHT = 0,
	MAGE = 1,
	ARCHER = 2,
};

/// �Ʒ��� ��ó�� ��� ������ �̸� ������ ���°� ����.

// GameObject
// - Creature(�ֻ��� ��ü)
// --Player, Monster, Npc, Pet(���� ��ü)

// Projectile
// --Arrow, Fireball
// - Env

//Item
// - Weapon
// -- Sword, Bow, Lance

// - Armor
// --Helmet, Boots, Armor, Glove

// �θ� Ŭ����
// Is-A(~ �Դϱ�?) vs Has-A(~������ �ֽ��ϱ�?)
// Is-A �� ��� �Ѵ�.
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

// ���赵
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

	//ĳ������ ���� ���� ��ü�� �����Ϳ� ���� ����
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

	// �ּҸ� ��Ƽ� �����Ѵ�.(�÷��̾�� ���� �ϰڴ�.)
	Player* p1 = &k1;	
	Knight* kPtr = (Knight*)p1;

	Player* p2 = &m1;

	Fight(&k1, &m1);
}