#include <iostream>
using namespace std;

/*
	Vector/List-> Tree -> Graph -> BFS -> Dijikstra -> A*
	
	7_1). 재귀함수

	장점 : 

*/

void Func(int a)
{
	// 재귀함수의 경우 끝나는 조건을 생각해야 한다.
	if (a == 0)
		return;

	cout << a << endl;
		
	// 스택 메모리가 고갈 되서 오류가 발생한다.(스택 오버플로우)
	Func(a - 1);	
}

// 팩토리얼
// 5! = 5*4*3*2*1 = 120
// n! = n*(n-1)!

int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

// 유클리드 알고리즘
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