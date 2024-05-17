#include <iostream>
using namespace std;

// 아래 코드는 좀 생각 할 필요가 있습니다.
char* StrCpy(char* dest, char* src)
{
	// 원본 위치
	char* ret = dest;

	{
		// index 이용하는 버전
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
	
	// pointer를 이용하는 버전
	{
		cout << "*src : " << *src << endl;

		// 포인터는 주소의 시작 위치를 가르키고있다.
		while (*src != 0)
		{
			*dest = *src;
			dest++;
			src++;
		}

		// 마지막칸에 0을 넣어 문자열의 종료 지점을 알려준다.
		*dest = 0;
	}

	return ret;
}

int StrLen(const char* str)
{
	// 내가 작업한 부분
	{
		int count = 0;

		for (int i = 0; i < 100; i++)
		{
			cout << str[i] << endl;
			if (str[i] == '\0')
			{
				cout << "str의 문자 길이 : " << count << endl;
				return count;
			}
			else
				count++;
		}
	}

	// 강의 코드
	{
		int count = 0;

		while (str[count] != '\0')
			count++;

		cout << "str의 문자 길이2 : " << count <<endl;
		return count;
	}

 }

char* StrCat(char* dest, char* src)
{
	char* ret = dest;
	int len = StrLen(dest);
	int i = 0;

	// 인덱스 이용 방법
	//{
	//	while (src[i] != 0)
	//	{
	//		dest[len + i] = src[i];
	//		i++;
	//	}

	//	dest[len + i] = 0;
	//}
	//

	// 포인터 이용하는 방법
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

//주소(포인터)에 의한 인수 전달 테스트 함수
void func(int* ptr)
{
	*ptr = 100;
}

int main()
{
	cout << "Hello World" << endl;

	{
		// 아스키 코드를 통해 어떤 값인지 알 수 있다.
		char ch = 'A';
		cout << ch << endl;

		// char 데이터형은 '\0' 0이라는 끝을 표시를 해줘야 정상적으로 표해 준다.
		char str[] = { 'H','e','l','l','o','\0' };
		// 문자열의 기본
		char str2[] = "Hello";
		cout << str << endl;
		cout << str2 << endl;

		// const는 고정값, const 키워드를 넣을 경우
		//  stack 데이터가 저장되는게 아니라 Data영역에 읽기전용 공간에 들어간다.
		const char* ptr = "Hello";
		cout << ptr << endl;
	}
	
	cout << "====================================================================" << endl;

	{
		const int  BUF_SIZE = 100;

		// [Hello0                    ] <-- 이런 상태
		char a[BUF_SIZE] = "Hello";
		char b[BUF_SIZE] = "World";

		// strlen()->문자열 길이 알려주는 함수
		int len = strlen(a);
		cout << len << endl;
		
		// 아래의 오류코드를 무시해주는 선언
#pragma warning(disable:4996)
		//strcpy_s()->문자열 복사해주는 함수
		char c[BUF_SIZE];
		//strcpy(c, b);

		cout << c << endl;

		//strcat -> 문자 합해주는 함수
		//strcat(a, b);
		cout << a << endl;

		StrLen(a);
		StrCat(a, b);

		cout << StrCpy(c, a) << endl;

		// 주소(포인터)에 의한 인수 전달 테스트 코드
		{
			int value = 5;
			int* ptr_value = &value;

			func(ptr_value);
			func(&value);
		}
	}
}