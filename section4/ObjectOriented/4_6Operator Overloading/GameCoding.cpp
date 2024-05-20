#include <iostream>

using namespace std;

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// 연산자 오버로딩
// - 멤버 연산자 함수 버전
// -- a op b 형태에서 왼쪽을 기준으로 실행
// 
// - 전연 연산자 함수 버전
// -- a op b 형태라면, a/b 모두를 연산자 함수에 피연산자로 사용

class Pos
{
public:
	Pos()
	{

	}
	// explicit 키워드를 넣어주면 은근슬쩍 비슷한 내용의 함수
	//  생성자를 호출 하는것을 막아준다.(초기화 때만 호출)
	explicit Pos(int b)	
	{
		x = b;
		y = b;
	}
	Pos operator+(const Pos& other)
	{
		Pos pos;
		pos.x = x + other.x;
		pos.y = y + other.y;

		return pos;
	}

	Pos operator+(int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;
		
		return pos;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.y;
	}

	// 대입 연산자
	//void operator=(int b)
	//{
	//	x = b;
	//	y = b;
	//}

	// 'a = b = c' 이런 연산자를 처리 하기 위한 함수(연이어 실행 하는 함수)
	Pos& operator=(int b)
	{
		x = b;
		y = b;
		return *this;
	}

	int x = 0;
	int y = 0;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

void TestPos(Pos a)
{

}

int main()
{
	//TestPos(10);

	int a = 10;
	int b = 20;
	int c = a + b;

	//선언과 동시에 =(equal)을 통해 값을 넣는것은 생성자를 통해 
	// 가지고 우리가 무엇인가를 하는 행동이다.
	Pos pos1 = 10; // Pos pos1(10) 과 같다. --> 생성자
	Pos pos2 = 20;

	Pos pos3 = pos1 + pos2;
	Pos pos4 = pos1 + 10;
	
	// 아래와 같은 케이스는 지원해 주지 않는다.(멤버 연산자 함수)
	pos4 = 10 + pos1;	// 전역 연산자 함수를 만들어 주면 된다.
	//pos3 = pos1.operator+(pos2); --> 이것과 같다

	// 대입 연산
	// 아래의 코드는 선언과 동시에 초기화 하는 코드가 아님에도 불구하고
	// 대입 연산자가 없다면 생성자 코드안에 비슷한 내용이 있다면 해당 생성자가 실행된다.
	// 대입 연산자가 있다면 정상적으로 대입 연산자 함수가 실행 된다.
	pos1 = 10;
	pos2 = 20;
}