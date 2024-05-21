#include <iostream>
using namespace std;

//Casting

class Player
{
public:

};

class Knight : public Player
{
public:
	Knight():hp(100),defence(30) { cout << "Knight()" << endl; }
	~Knight() { cout << "~Knight()" << endl; }
public:
	int hp;
	int defence;

};

class Dog
{
public:
	Dog():age(3),size(20) { cout << "Dog()" << endl; }
	~Dog() { cout << "~Dog()" << endl; }
	
public:
	int age;
	int size;
};

int main()
{
	// C ��Ÿ�� ĳ����

	{
		// �� Ÿ�� ��ȯ(�����)
		// Ư¡) �ǹ̸� �����ϱ� ���ؼ� ���� ��ü�� �ٸ� ��Ʈ�� �籸��
		{
			int a = 123456789;
			float b = (float)a;
			int c = 0;
		}

		// ���� Ÿ�� ��ȯ
		{
			int a = 123456789;
			float b = (float&)a;
			int c = 0;
		}

		// ������ ��ȯ(�ǹ̰� 100% ��ġ)
		{
			int a = 123456789;
			__int64 b = (__int64)a;
			int c = 0;
		}

		// �Ҿ����� ��ȯ
		{
			int a = 123456789;
			short b = (short)a;
			int c = 0;
		}

		// �Ͻ���(�����ϸ�)
		{
			int a = 123456789;
			float b = a;
		}
	}

	Knight* k = new Knight();

	// �Ʒ��� ���� ���� �� ��� ������ �ּҿ� �����͸� ����Ű�� �ְ� �˴ϴ�.
	Dog* dog = (Dog*)k;
	// ���� Ȯ���� ���� dog�� �ʱ�ȭ�� ���� �ƴ� Knight�� �ּҸ� �ٶ� ���� �ֱ� ������
	// age = 100 , size = 30 �ΰ��� Ȯ�� �� �� �ֽ��ϴ�.
	
	// dog->age�� 1000���� �����ϸ� ���� �ּ��� �������� Knight�� hp�� ���� 1000����
	// ���� �Ȱ��� Ȯ�� �� �� �ִ�.
	dog->age = 1000;
	cout << dog->age << endl;
}