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

int main()
{
	//Func(6);
	cout << Factorial(5) << endl;
}