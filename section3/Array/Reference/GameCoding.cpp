#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};


// 1) 값(복사) 전달 방식
// 값 복사의 경우 데이터가 크면 스택 메모리에 영향을 많이 준다(메모리를 많이 차지하게 된다.)
void printByCopy(StatInfo player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "---------------------------------------------" << endl;
}

// 2) 주소 전달 방식
// 주소 전달 경우 포인터를 전달 하기 때문에 8Byte 밖에 메모리를 잡아 먹지 않는다.
void PrintByPointer(StatInfo* player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player->hp << endl;
	cout << "ATT : " << player->attack << endl;
	cout << "DEF : " << player->defence << endl;
	cout << "---------------------------------------------" << endl;
}

// 3) 참조 전달 방식
// OUT -> 수정을 하려는 의도를 보여주는 키워드
#define OUT 
void PrintByRef(OUT StatInfo& player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "---------------------------------------------" << endl;

	player.hp = 10;
}

// 읽기 형식의 참조 전달 방식
void PrintByRef(const StatInfo& player)
{
	cout << "---------------------------------------------" << endl;
	cout << "HP : " << player.hp << endl;
	cout << "ATT : " << player.attack << endl;
	cout << "DEF : " << player.defence << endl;
	cout << "---------------------------------------------" << endl;

	// const 키워드로 인한 값 수정 불가
	//player.hp = 1000;
}

int main()
{
	// 요즘 많이쓰는 초기화
	StatInfo player = { 100,10,1 };
	printByCopy(player);
	PrintByPointer(&player);
	PrintByRef(player);

	// 포인터
	// 포인터를 사용 하는 큰 이유
	// - 원본을 건드리고 싶을 때(원격)
	// - 복사 비용을 아끼고 싶을때(8바이트면 된다)
	// 
	// 포인터의 장점 
	// - nullptr을 표현 할 수 있어서 좋다.(0이라는 상태를 넣어 줄 수 있다.)
	//   없다는걸 표현 할 수 있다.
	// - nullptr을 체크를 잘 해줘야 한다.
	StatInfo* ptr = &player;

	// 참조(내부적으로 구현이 되는 코드의 동작 원리는 포인터랑 가깝다)
	// 간접적으로 주소를 이용해 원본 데이터를 건든다.
	// - 참조의 경우 데이터를 비워 둘 수 없다. (초기화 필수)
	StatInfo& ref = player;
	PrintByRef(OUT player);	

	ref.hp = 10;

}