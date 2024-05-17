#include <iostream>
using namespace std;

// ��ü����(Object Oriented Programming)
// ������ + ����

// OOP 3�� ���
// - ��Ӽ� << inheritance
// - ���м� << data hiding (ĸ��ȭ encapsulation)
// - ������ << polymorphism (poly + morphism)

// �����ε�(overloading) = �Լ� �̸��� ����
// �������̵�(overriding)

// �����ε�
void Test()
{

}

void Test(int a)
{

}

// �����ε�
// virtual ���� �Լ�
// vftable (virtual function table)
// .vftable [ �ּ�1 | �ּ� 2 | �ּ�3 ]

// ���� ���� �Լ��� �߰� ������ �߻� Ŭ������ �ȴ�.
class Player
{
public:
	virtual ~Player() {}	// �Ҹ��ڿ� virtual Ű���带 �ٿ� �ڽ� ��ü�� �Ҹ�� �� �ֵ��� �ؾ� �մϴ�.
	virtual void Move() { cout << "Player Move()" << endl; }

	// ���� ���� �Լ�
	virtual void Run() = 0;	// ���� ���� �Լ�
	virtual void Run2() abstract; // ���� ���� �Լ� Ű����

public:
	int _hp;
};

class Knight : public Player
{
public:
	// override Ű���带 ����ϸ� �θ��� �Լ��� virtual Ű���带 �޾Ҵ��� Ȯ���� �� �� �ִ�.
	virtual void Move() override { cout << "Knight Move()" << endl; } 
	virtual void Run() override { cout << "Knight Run()" << endl; }
	virtual void Run2() override { cout << "Knight Run2()" << endl; }

public: 
	int _stamina;
};

// ���ε�(Binding) = ���´�.
// - ���� ���ε� (static binding = ������ ���� ����)
// - ���� ���ε� (dynamic binding = ���� ���� ����)
void MovePlayer(Player* player)
{
	player->Move();
}

int main()
{
	Knight k1;
	//k1.Move();
	MovePlayer(&k1);
}
