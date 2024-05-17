#include <iostream>
#include "Player.h"
using namespace std;

// 객체지향 (object-oriented programming)
// 데이터 + 로직
// 게임을 진행 시키는게 함수로 이루어진다.

class Knight
{// 설계도 객체를 묘사한다.(플레이어, 몬스터, GameRoom, Lobby, PlayerManager, ...)
// 클래스만 만들었을땐 메모리를 차지하지 않는다.
// 클래스의 함수들은 데이터(코드) 영역에 들어 갑니다.
public:
	// 기본 생성자(constructor) - 입장
	// 생성자에서 변수 초기화를 해줌
	Knight()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Knight()" << endl;
	}

	// 복사 생성자
	Knight(const Knight& other)
	{
		this->_hp = other._hp;
		this->_attack = other._attack;
		this->_defence = other._defence;
		cout << "Knight(const Knight&)" << endl;
	}

	// 기타 생성자
	// 기타 생성자 같은 다른 생성자를 만들면 기본 생성자는 실행 되지 않는다.
	Knight(int hp, int attack, int defence)
	{
		this->_hp = hp;
		this->_attack = attack;
		this->_defence = defence;
	}
	// 소멸자(destructor) - 퇴장 / 메모리 해제 할때 이용함
	~Knight()
	{
		cout << "~Knight()" << endl;
	}

	
	// 멤버 함수
	void Attack() { cout << "Attack" << endl; }
	void Die() { cout << "Die" << endl; }
	void HealMe(int value)
	{
		_hp += value;
	}

public:
	// 멤버 변수
	int _hp;
	int _attack;
	int _defence;
};

int main()
{
	// 객체(instance)
	Player p1;
	Knight k1(100, 10, 1);
	Knight k2(k1);
}