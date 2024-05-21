#include <iostream>
using namespace std;

// ���� �Ҵ�
// MMO ���� 1��, ���� 50��

// - ����
// - �޸�

class Monster
{
public:
	Monster() { cout << "Monster()" << endl; }
	~Monster() { cout << "~Monster()" << endl; }
public:
	int _hp = 0;
};

// �������� ������ ������ �޸𸮸� ��� ������ ������ ���� ������
// ���α׷� ���� ���� ������� �޸𸮸� ��� �Դ� ������ �߻� �մϴ�.(��û�� ��ȿ����)
//Monster monsters[100 * 10000];

class Player
{
public:
	Monster* _target;
};

Player* FindPlayer(int id)
{
	// TODO
	return nullptr;
}

int main()
{
	// stack������ �޸𸮸� �÷� ������ �ʹ� Ŀ�� ������ �߻��Ѵ�.
	//Monster monsters[100 * 10000];

	// malloc(�Ҵ�) + free(����) -> C (�����ڿ� �Ҹ��ڰ� �ڵ����� ȣ�� ���� �ʴ´�.)
	{
		//void* ptr = malloc(1000);

		//Monster* m = (Monster*)ptr;
		//m->_hp = 100;

		//free(ptr);
	}


	// new(�Ҵ�) + delete(����) -> C++(������, �Ҹ��� �ڵ� ȣ��)
	// �޸� �Ҵ��� �ְ� ������ ���� ������ �޸� ���� �߻�(memory leak)
	Monster* m1 = new Monster();
	//Monster* m2 = new Monster[5]();  // <- ������ ����
	//delete[] m2;
	m1->_hp = 100;

	Player* player = FindPlayer(0);

	// �޸� ���� ������ ���� nullptr üũ�� �� �����
	if(player != nullptr)
		player->_target = m1;

	delete m1;
	m1 = nullptr;		// User-After-Free ���� ���� �ϱ� ���� ���(nullptr)
	
	// Q. ���� �� ����ϴ� ��� �ɱ�?
	// 1) ũ���� 2) �׳� �ȴ�.
	// ũ���� �ȵǰ� �׳� �ȴ�. ����???
	// �ǽð����� ���� �Ҵ� �� ���� ���� �ʴ´�.
	// �� ������ ���߿� ����� �޸��� ũ�⸦ �Ҵ� �Ҷ� ���� ��û�� �޸��� ������ �ֱ� ����
	// �ǽð����� ���� �Ҵ��� ���� �ϴ� ������� �ü������ �ǽð����� �޸𸮸�
	// ������ ��û�ϰ� ������ �Լ����� �̿��� ���� ��Ų��.
	// User-After-Free : ������� �� ��� �ϰ� �ִ�.

	player->_target->_hp =200;
	//m1->_hp = 200;

}