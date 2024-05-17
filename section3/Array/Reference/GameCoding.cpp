#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};


// 1) ��(����) ���� ���
// �� ������ ��� �����Ͱ� ũ�� ���� �޸𸮿� ������ ���� �ش�(�޸𸮸� ���� �����ϰ� �ȴ�.)
void printByCopy(StatInfo player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "---------------------------------------------" << endl;
}

// 2) �ּ� ���� ���
// �ּ� ���� ��� �����͸� ���� �ϱ� ������ 8Byte �ۿ� �޸𸮸� ��� ���� �ʴ´�.
void PrintByPointer(StatInfo* player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player->hp << endl;
	cout << "ATT : " << player->attack << endl;
	cout << "DEF : " << player->defence << endl;
	cout << "---------------------------------------------" << endl;
}

// 3) ���� ���� ���
// OUT -> ������ �Ϸ��� �ǵ��� �����ִ� Ű����
#define OUT 
void PrintByRef(OUT StatInfo& player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "---------------------------------------------" << endl;

	player.hp = 10;
}

// �б� ������ ���� ���� ���
void PrintByRef(const StatInfo& player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "---------------------------------------------" << endl;

	// const Ű����� ���� �� ���� �Ұ�
	//player.hp = 1000;
}

int main()
{
	// ���� ���̾��� �ʱ�ȭ
	StatInfo player = { 100,10,1 };
	printByCopy(player);
	PrintByPointer(&player);
	PrintByRef(player);

	// ������
	// �����͸� ��� �ϴ� ū ����
	// - ������ �ǵ帮�� ���� ��(����)
	// - ���� ����� �Ƴ��� ������(8����Ʈ�� �ȴ�)
	// 
	// �������� ���� 
	// - nullptr�� ǥ�� �� �� �־ ����.(0�̶�� ���¸� �־� �� �� �ִ�.)
	//   ���ٴ°� ǥ�� �� �� �ִ�.
	// - nullptr�� üũ�� �� ����� �Ѵ�.
	StatInfo* ptr = &player;

	// ����(���������� ������ �Ǵ� �ڵ��� ���� ������ �����Ͷ� ������)
	// ���������� �ּҸ� �̿��� ���� �����͸� �ǵ��.
	// - ������ ��� �����͸� ��� �� �� ����. (�ʱ�ȭ �ʼ�)
	StatInfo& ref = player;
	PrintByRef(OUT player);	

	ref.hp = 10;

}