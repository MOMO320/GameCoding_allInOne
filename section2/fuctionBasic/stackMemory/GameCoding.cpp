#include <iostream>
#include "vector"
#include <stdio.h>
#include "string"

using namespace std;

// [��ȯ Ÿ��] [�Լ��̸�]([�Է�...]) {[������]}

// �Լ� ���� ���� ���� �޸𸮿� �ö󰣴�.
// ���� �޸𸮸� �󸶳� ��� ������ ���� �Ǵ��� �Լ� ���ξ翡 ���� ���� �ȴ�.

/*
	32bit �� 64bit�� ���� : ���������� ũ�� ���� �̴�.

	���� 64bit�� ��� ���ڰ��� ������ �������Ϳ� ���� �����ؼ� ����ϱ⵵ �Ѵ�.
	(�װ� �ӵ��� �� ������ ������)

	��Q. ���� ���� �÷ο찡 �Ͼ�� ���� ���� �Ͼ���?
	  A. ���� �޸𸮴� �Լ��鳢�� ����ϴ� �޸����ε�  


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
