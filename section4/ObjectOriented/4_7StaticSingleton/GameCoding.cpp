#include <iostream>
using namespace std;

// ��ü����(Object Oriented Programming)
// ������ + ����

// static�� �̱���

// struct vs class 
// struct�� �������� �����͸� ��ư����� �����ϴ� �뵵�� ����ϰ�
// class �� ��ü ���� �뵵�� Ȱ�� �ϸ� �ȴ�.
//struct Knight1
//{
//public:
//	int hp;
//};
//
//class Knight2
//{
//private:
//	int hp;
//};


// static 
// static Ű���带 ����ϸ� ����ƽ �޸𸮿� ���� �Ǿ� ���������� ����ϰ� �ȴ�.
class Marine
{
public:
	// Ư�� ���� ��ü ����
	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// Ư�� ���� ��ü�� ����
	static void SetAttack(int value)
	{
		// ��ü�� �������� �ʰ� ����� ������ static �Լ��̱� ������
		// static ������ ��� �����ϴ�.
		//_hp = 40; --> ����!!
		attack = value;
	}

public:
	// Ư�� ���� ��ü�� ����
	int _hp = 40;

	// static ��� ����
	// Ư�� ���� ��ü�� ����
	static int attack;
};

int Marine::attack = 6;

class Player
{
public:
	Player()
	{
		// id 1�� �ø��� static �̿���
		_id = s_idGenerator++;
		cout << _id << endl;
	}

public:
	int _id;
	static int s_idGenerator;
};

int Player::s_idGenerator = 1;

int GenerateId()
{
	// static local ����
	// �Լ� ȣ��ɶ� ���ѹ� �ʱ�ȭ �� �� ���� ����ó�� �̿��
	static int s_id = 10;

	return s_id++;
}

// �ڷᱸ��&�˰���
// ������ ����
// - �̱���, ������, ������Ʈ, ...

// �̱��� : ���� �� 1���� �����ϰ� ��𼭵� ����� �� �ִ� [�Ŵ���] Ŭ����
class UserManager
{
public:
	static UserManager* GetInstance()
	{
		static UserManager um;
		return &um;
	}

public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount; }

private:
	int _userCount = 0;

};

#define GETR_MANAGER (UserManager::GetInstance())

int main()
{
	//Knight1 k1;
	//Knight2 k2;

	/*Marine m1;
	m1._hp = 40;

	Marine m2;
	m2._hp = 10;*/
	//���� ��ü�� �������� �ʾƵ� �Լ� ��� ����
	Marine::SetAttack(10);

	Marine::attack = 7;

	Player p1;
	Player p2;
	Player p3;

	for(int i = 0; i <10 ; i++)
		UserManager::GetInstance()->AddUser();

	cout << UserManager::GetInstance()->GetUserCount() << endl;
}