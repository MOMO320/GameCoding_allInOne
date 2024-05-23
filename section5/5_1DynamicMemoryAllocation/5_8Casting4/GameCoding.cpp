#include <iostream>

using namespace std;

// C++ 캐스팅 4총사
// static_cast <<
// dynamic_cast <<
// const_cast
// reinterpret_cast

class Player
{
public:
	Player() {}
	virtual ~Player() {}
};

class Knight : public Player
{
public:
	Knight() {}
	virtual ~Knight() {}
};

class Archer : public Player
{
public:
	Archer() {}
	virtual ~Archer() {}
};

class Dog
{
public :
	Dog() {}
	virtual ~Dog() {}
};

int main()
{
	// ㅁ static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해준다.
	// 1) int <-> float 
	// 2) Player* -> Knight*

	int hp = 100;
	int maxHp = 200;

	//float ratio = (float)hp / maxHp;
	float ratio = static_cast<float>(hp) / maxHp;

	Archer* k = new Archer();
	Player* p = k;

	//Knight* k2 = (Knight*)p;
	//Knight* k2 = static_cast<Knight*>(p);

	// ㅁ dynamic_cast : 상속 관계에서의 안전 변환
	// 다형성을 활용한 방식(virtual)
	// RTTI (RunTime Type Information)
	// 가상함수 테이블을 통해 판별(virtual table)
	// 가상함수 주소값을 보면 다 동일하다.

	// 되는 경우에만 캐스팅 되고 아닐경우 null을 넣어준다.
	// C# as
	Knight* k2 = dynamic_cast<Knight*>(p);	

	if (k2 != nullptr)
	{
		// 기사였네??
	}

	// ㅁ const_cast
	// const 키워드를 잠시 없애주는 캐스팅
	const char* name = "Rookies";
	char* name2 = const_cast<char*>(name);

	// ㅁ reinterpret_cast
	// 위험하고, 강력한 형태
	// re-interpret : 다시 생각하다?
	// 포인터 -> 전혀 관계 없는 다른 타입으로 변환
	//Dog* dog = (Dog*)k;
	Dog* dog = reinterpret_cast<Dog*>(k);

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);

	__int64 address = reinterpret_cast<__int64>(k);
}