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

// ��Ŭ���� �˰���
// a > b
// GCD(1071, 1029)
// = GCD(1029, 1071%1029 = 42)
// = GCD(42, 1029%42 = 21)
// = GCD(21, 0 ) = 21

int Gcd(int a, int b)
{
	if (b == 0)
		return a;

	return (Gcd, b, a % b);
}

int main()
{
	//Func(6);
	cout << Factorial(5) << endl;
}