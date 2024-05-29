#include<iostream>

using namespace std;

/*

  ㅁ 업 캐스팅
  : 업 캐스팅(Up Casting)은 상위 클래스의 포인터가 하위 클래스 객체 주소를 가리키는 것이다.

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
	//pBase->DerivedFund();	// 하위 객체의 멤버를 사용할 수 없다.

	Derived* downDev = (Derived*)pBase;
	downDev->DerivedFun();

	return 0;
}
