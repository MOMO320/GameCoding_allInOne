#include <iostream>
using namespace std;

class Monster
{
public:
	Monster() { cout << "Monster()" << endl; }
	~Monster() { cout << "~Monster()" << endl; }

public:
	int _hp = 100;
};

int main()
{
	Monster* m1 = new Monster;
	delete m1;
	m1 = nullptr;

	cout << "�޸� ���� �� hp : " << m1->_hp << endl;
	m1->_hp = 200;
	cout << "�޸� ���� �� hp : " << m1->_hp << endl;

	return 0;
}