#include <iostream>
using namespace std;

/*
	Vector/List-> Tree -> Graph -> BFS -> Dijikstra -> A*
	
	7_1). ����Լ�

	���� : 

*/

void Func(int a)
{
	// ����Լ��� ��� ������ ������ �����ؾ� �Ѵ�.
	if (a == 0)
		return;

	cout << a << endl;
		
	// ���� �޸𸮰� �� �Ǽ� ������ �߻��Ѵ�.(���� �����÷ο�)
	Func(a - 1);	
}

// ���丮��
// 5! = 5*4*3*2*1 = 120
// n! = n*(n-1)!

int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

int main()
{
	//Func(6);
	cout << Factorial(5) << endl;
}