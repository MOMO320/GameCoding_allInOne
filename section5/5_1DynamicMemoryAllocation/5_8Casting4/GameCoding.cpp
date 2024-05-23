#include <iostream>

using namespace std;

// C++ ĳ���� 4�ѻ�
// static_cast <<
// dynamic_cast <<
// const_cast
// reinterpret_cast

class Player
{
public:
	Player() {}
	virtual ~Player() {}
};

class Knight : public Player
{
public:
	Knight() {}
	virtual ~Knight() {}
};

class Archer : public Player
{
public:
	Archer() {}
	virtual ~Archer() {}
};

class Dog
{
public :
	Dog() {}
	virtual ~Dog() {}
};

int main()
{
	// �� static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ������ش�.
	// 1) int <-> float 
	// 2) Player* -> Knight*

	int hp = 100;
	int maxHp = 200;

	//float ratio = (float)hp / maxHp;
	float ratio = static_cast<float>(hp) / maxHp;

	Archer* k = new Archer();
	Player* p = k;

	//Knight* k2 = (Knight*)p;
	//Knight* k2 = static_cast<Knight*>(p);

	// �� dynamic_cast : ��� ���迡���� ���� ��ȯ
	// �������� Ȱ���� ���(virtual)
	// RTTI (RunTime Type Information)
	// �����Լ� ���̺��� ���� �Ǻ�(virtual table)
	// �����Լ� �ּҰ��� ���� �� �����ϴ�.

	// �Ǵ� ��쿡�� ĳ���� �ǰ� �ƴҰ�� null�� �־��ش�.
	// C# as
	Knight* k2 = dynamic_cast<Knight*>(p);	

	if (k2 != nullptr)
	{
		// ��翴��??
	}

	// �� const_cast
	// const Ű���带 ��� �����ִ� ĳ����
	const char* name = "Rookies";
	char* name2 = const_cast<char*>(name);

	// �� reinterpret_cast
	// �����ϰ�, ������ ����
	// re-interpret : �ٽ� �����ϴ�?
	// ������ -> ���� ���� ���� �ٸ� Ÿ������ ��ȯ
	//Dog* dog = (Dog*)k;
	Dog* dog = reinterpret_cast<Dog*>(k);

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);

	__int64 address = reinterpret_cast<__int64>(k);
}