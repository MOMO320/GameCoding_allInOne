#include <iostream>
#include "Player.h"
using namespace std;

// ��ü���� (object-oriented programming)
// ������ + ����
// ������ ���� ��Ű�°� �Լ��� �̷������.

class Knight
{// ���赵 ��ü�� �����Ѵ�.(�÷��̾�, ����, GameRoom, Lobby, PlayerManager, ...)
// Ŭ������ ��������� �޸𸮸� �������� �ʴ´�.
// Ŭ������ �Լ����� ������(�ڵ�) ������ ��� ���ϴ�.
public:
	// �⺻ ������(constructor) - ����
	// �����ڿ��� ���� �ʱ�ȭ�� ����
	Knight()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Knight()" << endl;
	}

	// ���� ������
	Knight(const Knight& other)
	{
		this->_hp = other._hp;
		this->_attack = other._attack;
		this->_defence = other._defence;
		cout << "Knight(const Knight&)" << endl;
	}

	// ��Ÿ ������
	// ��Ÿ ������ ���� �ٸ� �����ڸ� ����� �⺻ �����ڴ� ���� ���� �ʴ´�.
	Knight(int hp, int attack, int defence)
	{
		this->_hp = hp;
		this->_attack = attack;
		this->_defence = defence;
	}
	// �Ҹ���(destructor) - ���� / �޸� ���� �Ҷ� �̿���
	~Knight()
	{
		cout << "~Knight()" << endl;
	}

	
	// ��� �Լ�
	void Attack() { cout << "Attack" << endl; }
	void Die() { cout << "Die" << endl; }
	void HealMe(int value)
	{
		_hp += value;
	}

public:
	// ��� ����
	int _hp;
	int _attack;
	int _defence;
};

int main()
{
	// ��ü(instance)
	Player p1;
	Knight k1(100, 10, 1);
	Knight k2(k1);
}