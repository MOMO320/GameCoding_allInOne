#include <iostream>

using namespace std;

// NULL 크래시
// 정수 오버플로우(언더플로우) (0.001%)
// 메모리 릭(0.1%)
// 메모리 오염
// - 캐스팅 <<
// - 버퍼 오버 플로우 <<
// - Use-After-Free <<

class Player
{
public:
	int hp = 0;
};

Player* FindPlayer(int id)
{
	//TODO

	return nullptr;
}

void Test(Player* p)
{
	if (p == nullptr)
		return;

	p->hp = 10;// null
}

int main()
{
	Player* p = FindPlayer(100);
	Test(p);
	p->hp = 100;	// null 크래시 발생
}