#include <iostream>

using namespace std;

// NULL ũ����
// ���� �����÷ο�(����÷ο�) (0.001%)
// �޸� ��(0.1%)
// �޸� ����
// - ĳ���� <<
// - ���� ���� �÷ο� <<
// - Use-After-Free <<

class Player
{
public:
	int hp = 0;
};

Player* FindPlayer(int id)
{
	//TODO

	return nullptr;
}

void Test(Player* p)
{
	if (p == nullptr)
		return;

	p->hp = 10;// null
}

int main()
{
	Player* p = FindPlayer(100);
	Test(p);
	p->hp = 100;	// null ũ���� �߻�
}