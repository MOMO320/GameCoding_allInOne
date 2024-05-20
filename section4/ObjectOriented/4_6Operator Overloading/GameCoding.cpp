#include <iostream>

using namespace std;

// ��ü����(Object Oriented Programming)
// ������ + ����

// ������ �����ε�
// - ��� ������ �Լ� ����
// -- a op b ���¿��� ������ �������� ����
// 
// - ���� ������ �Լ� ����
// -- a op b ���¶��, a/b ��θ� ������ �Լ��� �ǿ����ڷ� ���

class Pos
{
public:
	Pos()
	{

	}
	// explicit Ű���带 �־��ָ� ���ٽ�½ ����� ������ �Լ�
	//  �����ڸ� ȣ�� �ϴ°��� �����ش�.(�ʱ�ȭ ���� ȣ��)
	explicit Pos(int b)	
	{
		x = b;
		y = b;
	}
	Pos operator+(const Pos& other)
	{
		Pos pos;
		pos.x = x + other.x;
		pos.y = y + other.y;

		return pos;
	}

	Pos operator+(int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;
		
		return pos;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.y;
	}

	// ���� ������
	//void operator=(int b)
	//{
	//	x = b;
	//	y = b;
	//}

	// 'a = b = c' �̷� �����ڸ� ó�� �ϱ� ���� �Լ�(���̾� ���� �ϴ� �Լ�)
	Pos& operator=(int b)
	{
		x = b;
		y = b;
		return *this;
	}

	int x = 0;
	int y = 0;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

void TestPos(Pos a)
{

}

int main()
{
	//TestPos(10);

	int a = 10;
	int b = 20;
	int c = a + b;

	//����� ���ÿ� =(equal)�� ���� ���� �ִ°��� �����ڸ� ���� 
	// ������ �츮�� �����ΰ��� �ϴ� �ൿ�̴�.
	Pos pos1 = 10; // Pos pos1(10) �� ����. --> ������
	Pos pos2 = 20;

	Pos pos3 = pos1 + pos2;
	Pos pos4 = pos1 + 10;
	
	// �Ʒ��� ���� ���̽��� ������ ���� �ʴ´�.(��� ������ �Լ�)
	pos4 = 10 + pos1;	// ���� ������ �Լ��� ����� �ָ� �ȴ�.
	//pos3 = pos1.operator+(pos2); --> �̰Ͱ� ����

	// ���� ����
	// �Ʒ��� �ڵ�� ����� ���ÿ� �ʱ�ȭ �ϴ� �ڵ尡 �ƴԿ��� �ұ��ϰ�
	// ���� �����ڰ� ���ٸ� ������ �ڵ�ȿ� ����� ������ �ִٸ� �ش� �����ڰ� ����ȴ�.
	// ���� �����ڰ� �ִٸ� ���������� ���� ������ �Լ��� ���� �ȴ�.
	pos1 = 10;
	pos2 = 20;
}