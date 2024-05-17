#pragma once

class Player
{// 설계도 객체를 묘사한다.(플레이어, 몬스터, GameRoom, Lobby, PlayerManager, ...)
// 클래스만 만들었을땐 메모리를 차지하지 않는다.

public:
	// 클래스의 함수들은 데이터(코드) 영역에 들어 갑니다.
	// 멤버 함수
	void Attack();
	void Die();
	void HealMe(int value);

public:
	// 멤버 변수
	int hp;
	int attack;
	int defence;
};

