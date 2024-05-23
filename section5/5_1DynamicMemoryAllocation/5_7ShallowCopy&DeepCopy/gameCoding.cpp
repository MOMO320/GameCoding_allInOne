#include <iostream>

using namespace std;

// ���� ���� vs ���� ����

class Pet
{
public:
	Pet() { cout << "Pet()" << endl; }
	~Pet() { cout << "~Pet()" << endl; }

	Pet(const Pet& pet) { cout << "Pet(const Pet&)" << endl; }
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	~Knight()
	{
		delete _pet;
	}
	Knight(const Knight& k)	// ���� ������
	{
		_hp = k._hp;

		// ���� ���� : ������, ���۷����� ��� �׳� ���� �����ʰ�
		// ���ο� �ּ� ������� ��ü�� ������༭ �����Ѵ�.
		_pet = new Pet();	
	}

	//void operator=(const Knight& k)
	//{
	//	_hp = k._hp;
	//}
public:
	int _hp = 10;
	Pet* _pet;
};

int main()
{
	Knight k1;
	k1._hp = 200;

	//Knight k2 = k1;	// ���� ������

	/*
		��� : k1�� k2�� _pet �ּ� ���� ����.

		�� ���� ���� : �׳� ���� ���� �Ѵ�.
		�׷��� ���� �Ϲ����� ������ ��������� ������ ���� �ּ� ���� ������ �ִ� ���� ������ ���
		���� �ּҰ��� �����ϰ� �Ǿ� �ϳ��� ������ �ص� ���� ������ �ǰ�,
		�ϳ��� �����ص� �ּҰ��� ����Ű�� ��ü�� ���� �Ǿ� ������ �߻��ϰ� �ȴ�.
	*/
	Knight k2(k1);		// ���� ������ 

	//Knight k3;			// �⺻ ������
	//k3 = k1;			// ���� ������
}