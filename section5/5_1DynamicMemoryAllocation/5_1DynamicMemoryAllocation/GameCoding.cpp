#include <iostream>
using namespace std;

// 동적 할당
// MMO 동접 1만, 몬스터 50만

// - 스택
// - 메모리

class Monster
{
public:
	Monster() { cout << "Monster()" << endl; }
	~Monster() { cout << "~Monster()" << endl; }
public:
	int _hp = 0;
};

// 전역으로 데이터 영역에 메모리를 잡아 놓으면 문제는 되지 않지만
// 프로그램 실행 부터 종료까지 메모리를 잡아 먹는 문제가 발생 합니다.(엄청난 비효율적)
//Monster monsters[100 * 10000];

class Player
{
public:
	Monster* _target;
};

Player* FindPlayer(int id)
{
	// TODO
	return nullptr;
}

int main()
{
	// stack영역에 메모리를 올려 놓으면 너무 커서 문제가 발생한다.
	//Monster monsters[100 * 10000];

	// malloc(할당) + free(해제) -> C (생성자와 소멸자가 자동으로 호출 되지 않는다.)
	{
		//void* ptr = malloc(1000);

		//Monster* m = (Monster*)ptr;
		//m->_hp = 100;

		//free(ptr);
	}


	// new(할당) + delete(해제) -> C++(생성자, 소멸자 자동 호출)
	// 메모리 할당해 주고 해제해 주지 않으면 메모리 누수 발생(memory leak)
	Monster* m1 = new Monster();
	//Monster* m2 = new Monster[5]();  // <- 여러개 생성
	//delete[] m2;
	m1->_hp = 100;

	Player* player = FindPlayer(0);

	// 메모리 오염 방지를 위해 nullptr 체크를 꼭 해줘라
	if(player != nullptr)
		player->_target = m1;

	delete m1;
	m1 = nullptr;		// User-After-Free 문제 예방 하기 위한 방법(nullptr)
	
	// Q. 삭제 후 사용하는 어떻게 될까?
	// 1) 크래시 2) 그냥 된다.
	// 크래시 안되고 그냥 된다. 왜지???
	// 실시간으로 동적 할당 과 해제 하지 않는다.
	// 그 이유는 나중에 비슷한 메모리의 크기를 할당 할때 해제 요청한 메모리의 공간을 주기 위함
	// 실시간으로 동적 할당을 해제 하는 방법으로 운영체제한테 실시간으로 메모리를
	// 실제로 요청하고 날리는 함수들을 이용해 해제 시킨다.
	// User-After-Free : 사용해지 후 사용 하고 있다.

	player->_target->_hp =200;
	//m1->_hp = 200;

}