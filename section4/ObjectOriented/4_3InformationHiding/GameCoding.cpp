#include <iostream>
using namespace std;

// ��ü����(Object Oriented Programming)
// ������ + ����

// OOP 3�� ���
// - ��Ӽ� << inheritance
// - ���м� << data hiding (ĸ��ȭ encapsulation)
// - ������

// �ڵ���
// - �ڵ�/���/����/��/���⼱/�ֹ���
// ������ ���忡�� ��� : �ڵ�/���/��
// ���� �� : ����,���⼱,�ֹ���

// ���� ������(���� ���� ����)
// public(������) vs protected(��ȣ�޴�) vs private(������)

class Car
{
public:
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		//...
		PutFuellnEngine();
	}

// �ܺο��� ��� ���ϰ� ��
private:
	void PutFuellnEngine() {}
	void ConnectCircuit() {}

// ��� ���� �ֵ��� ��� �� �� �ִ�.
protected:
	void Disassemble() {} // ���� ���ؽ�Ų��.

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���⼱
};

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// public : ������ ���
// protected :  ��ȣ�޴� ���? �� �ڼյ����׸� ���� �ٰŴ�(public -> protected)
// private : �������� ��� �Ѵ�.(public , protected -> private)
class SuperCar : private Car
{
public :
	void Test()
	{
		Disassemble();
	}

public:

};

class UltraSuperCar : public SuperCar
{
public:
	void Test()
	{
		// Car�� public �Լ��� ��� �� �� ����.
		//MoveHandle();	
	}
};

class Knight
{
public:
	// ���ϴ� �κи� ����
	void SetHp(int hp)
	{
		_hp = hp;

		if (_hp <= 50)
		{
			// TODO
		}
	}

	int GetHp()
	{
		return _hp;
	}

private:
	// �߿��� ������ ������ �̿��� �ܺο��� ���� �� �� ���� ó�� ��
	/// ���������� �ʰ� ��� ����ϰ� �ؾ� ��
	int _hp;
};

int main()
{
	Car c;
	
	// �ܺο��� ��� �ȵ�
	//c.Disassemble();
}