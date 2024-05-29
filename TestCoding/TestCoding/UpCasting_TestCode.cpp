#include<iostream>

using namespace std;

/*

  �� �� ĳ����
  : �� ĳ����(Up Casting)�� ���� Ŭ������ �����Ͱ� ���� Ŭ���� ��ü �ּҸ� ����Ű�� ���̴�.

  */

class Base {
public:
	Base() {}
	virtual ~Base() {}

	void BaseFun() {}
	virtual void Print()
	{
		cout << "Base" << endl;
	}
};

class Derived : public Base
{
public:
	Derived() {}
	
	void DerivedFun() {}
	virtual void Print() override
	{
		cout << "Derived" << endl;
	}
};

int main1()
{
	Derived derived;
	Derived* pDerived = &derived;

	Base* pBase = pDerived;
	pBase->Print();
	//pBase->DerivedFund();	// ���� ��ü�� ����� ����� �� ����.

	Derived* downDev = (Derived*)pBase;
	downDev->DerivedFun();

	return 0;
}
