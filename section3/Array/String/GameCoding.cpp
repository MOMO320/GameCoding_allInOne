#include <iostream>
using namespace std;

// �Ʒ� �ڵ�� �� ���� �� �ʿ䰡 �ֽ��ϴ�.
char* StrCpy(char* dest, char* src)
{
	// ���� ��ġ
	char* ret = dest;

	{
		// index �̿��ϴ� ����
	//{
	//	char* ret = dest;

	//	int i = 0;

	//	while (src[i] != 0)
	//	{
	//		dest[i] = src[i];
	//		i++;
	//	}
	//	dest[i] = 0;
	//}  

	}
	
	// pointer�� �̿��ϴ� ����
	{
		cout << "*src : " << *src << endl;

		// �����ʹ� �ּ��� ���� ��ġ�� ����Ű���ִ�.
		while (*src != 0)
		{
			*dest = *src;
			dest++;
			src++;
		}

		// ������ĭ�� 0�� �־� ���ڿ��� ���� ������ �˷��ش�.
		*dest = 0;
	}

	return ret;
}

int StrLen(const char* str)
{
	// ���� �۾��� �κ�
	{
		int count = 0;

		for (int i = 0; i < 100; i++)
		{
			cout << str[i] << endl;
			if (str[i] == '\0')
			{
				cout << "str�� ���� ���� : " << count << endl;
				return count;
			}
			else
				count++;
		}
	}

	// ���� �ڵ�
	{
		int count = 0;

		while (str[count] != '\0')
			count++;

		cout << "str�� ���� ����2 : " << count <<endl;
		return count;
	}

 }

char* StrCat(char* dest, char* src)
{
	char* ret = dest;
	int len = StrLen(dest);
	int i = 0;

	// �ε��� �̿� ���
	//{
	//	while (src[i] != 0)
	//	{
	//		dest[len + i] = src[i];
	//		i++;
	//	}

	//	dest[len + i] = 0;
	//}
	//

	// ������ �̿��ϴ� ���
	{
		while (*dest != 0)
			dest++;
		while (*src)
		{
			*dest = *src;
			dest++;
			src++;
		}
	}
	return ret;
}

//�ּ�(������)�� ���� �μ� ���� �׽�Ʈ �Լ�
void func(int* ptr)
{
	*ptr = 100;
}

int main()
{
	cout << "Hello World" << endl;

	{
		// �ƽ�Ű �ڵ带 ���� � ������ �� �� �ִ�.
		char ch = 'A';
		cout << ch << endl;

		// char ���������� '\0' 0�̶�� ���� ǥ�ø� ����� ���������� ǥ�� �ش�.
		char str[] = { 'H','e','l','l','o','\0' };
		// ���ڿ��� �⺻
		char str2[] = "Hello";
		cout << str << endl;
		cout << str2 << endl;

		// const�� ������, const Ű���带 ���� ���
		//  stack �����Ͱ� ����Ǵ°� �ƴ϶� Data������ �б����� ������ ����.
		const char* ptr = "Hello";
		cout << ptr << endl;
	}
	
	cout << "====================================================================" << endl;

	{
		const int  BUF_SIZE = 100;

		// [Hello0                    ] <-- �̷� ����
		char a[BUF_SIZE] = "Hello";
		char b[BUF_SIZE] = "World";

		// strlen()->���ڿ� ���� �˷��ִ� �Լ�
		int len = strlen(a);
		cout << len << endl;
		
		// �Ʒ��� �����ڵ带 �������ִ� ����
#pragma warning(disable:4996)
		//strcpy_s()->���ڿ� �������ִ� �Լ�
		char c[BUF_SIZE];
		//strcpy(c, b);

		cout << c << endl;

		//strcat -> ���� �����ִ� �Լ�
		//strcat(a, b);
		cout << a << endl;

		StrLen(a);
		StrCat(a, b);

		cout << StrCpy(c, a) << endl;

		// �ּ�(������)�� ���� �μ� ���� �׽�Ʈ �ڵ�
		{
			int value = 5;
			int* ptr_value = &value;

			func(ptr_value);
			func(&value);
		}
	}
}