#include <iostream>
#include "vector"
#include <stdio.h>
#include "string"

using namespace std;

// [반환 타입] [함수이름]([입력...]) {[구현부]}

// 함수 인자 또한 스택 메모리에 올라간다.
// 스택 메모리를 얼마나 사용 할지에 대한 판단은 함수 내부양에 따라 결정 된다.

/*
	32bit 와 64bit의 차이 : 레지스터의 크기 차이 이다.

	요즘 64bit의 경우 인자값이 적으면 레지스터에 값을 저장해서 사용하기도 한다.
	(그게 속도가 더 빠르기 때문에)

	ㅁQ. 스택 오버 플로우가 일어나면 무슨 일이 일어날까요?
	  A. 스택 메모리는 함수들끼리 사용하는 메모장인데  


	 Stack Overflow

*/
int Test(int a, int b)
{
	int c = a + b;

	return c;
}

void OverflowTest()
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	for (int i = 0; i <= 10; i++)
		std::cout << vec[i] << endl;
}

void OverflowTest2()
{
	int i, len;
	int result = 0;

	char word[101] = { 0, };

	scanf_s("%s", word);

	len = (int)strlen(word);
	result = len;

	for (i = len - 1; i != 0; i--)
	{
		if (word[i] == '=')
		{
			if (word[i - 1] == 'c' || word[i - 1] == 's')
			{
				i -= 1;
				result -= 2;
			}
		}
	}
}

int main()
{
	//OverflowTest();
	OverflowTest2();

	return 0;
} 
