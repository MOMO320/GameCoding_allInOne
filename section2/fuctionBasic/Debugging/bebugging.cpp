#include <iostream>

using namespace std;

void Test1();
void Test2();
void Test3();

void Test1()
{

	int a = 100;
	cout << a << endl;
	Test2();
}

void Test2()
{
	int b = 10;
	Test3();
}

void Test3()
{

}


int main()
{
	Test1();

	Test2();

	return 0;
}