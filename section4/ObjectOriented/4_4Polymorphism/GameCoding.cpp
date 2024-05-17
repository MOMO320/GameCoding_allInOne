#include <iostream>
using namespace std;

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// OOP 3대 요소
// - 상속성 << inheritance
// - 은닉성 << data hiding (캡슐화 encapsulation)
// - 다형성 << polymorphism (poly + morphism)

// 오버로딩(overloading) = 함수 이름의 재사용
// 오버라이딩(overriding)

// 오버로딩
void Test()
{

}

void Test(int a)
{

}

// 오버로딩
// virtual 가상 함수
// vftable (virtual function table)
// .vftable [ 주소1 | 주소 2 | 주소3 ]

// 순수 가상 함수를 추가 했을땐 추상 클래스가 된다.
class Player
{
public:
	virtual ~Player() {}	// 소멸자에 virtual 키워드를 붙여 자식 객체가 소멸될 수 있도록 해야 합니다.
	virtual void Move() { cout << "Player Move()" << endl; }

	// 순수 가상 함수
	virtual void Run() = 0;	// 순수 가상 함수
	virtual void Run2() abstract; // 순수 가상 함수 키워드

public:
	int _hp;
};

class Knight : public Player
{
public:
	// override 키워드를 사용하면 부모의 함수가 virtual 키워드를 달았는지 확인해 볼 수 있다.
	virtual void Move() override { cout << "Knight Move()" << endl; } 
	virtual void Run() override { cout << "Knight Run()" << endl; }
	virtual void Run2() override { cout << "Knight Run2()" << endl; }

public: 
	int _stamina;
};

// 바인딩(Binding) = 묶는다.
// - 정적 바인딩 (static binding = 컴파일 시점 결정)
// - 동적 바인딩 (dynamic binding = 실행 시점 결정)
void MovePlayer(Player* player)
{
	player->Move();
}

int main()
{
	Knight k1;
	//k1.Move();
	MovePlayer(&k1);
}
