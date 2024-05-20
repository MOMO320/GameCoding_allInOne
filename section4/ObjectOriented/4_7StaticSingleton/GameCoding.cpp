#include <iostream>
using namespace std;

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// static과 싱글톤

// struct vs class 
// struct는 여러가지 데이터를 모아가지고 관리하는 용도로 사용하고
// class 는 객체 지향 용도로 활용 하면 된다.
//struct Knight1
//{
//public:
//	int hp;
//};
//
//class Knight2
//{
//private:
//	int hp;
//};


// static 
// static 키워드를 사용하면 스태틱 메모리에 들어가게 되어 전역적으로 사용하게 된다.
class Marine
{
public:
	// 특정 마린 객체 연관
	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// 특정 마린 객체와 무관
	static void SetAttack(int value)
	{
		// 객체를 생성하지 않고도 사용이 가능한 static 함수이기 때문에
		// static 변수만 사용 가능하다.
		//_hp = 40; --> 오류!!
		attack = value;
	}

public:
	// 특정 마린 객체와 연관
	int _hp = 40;

	// static 멤버 변수
	// 특정 마린 객체와 무관
	static int attack;
};

int Marine::attack = 6;

class Player
{
public:
	Player()
	{
		// id 1씩 늘릴때 static 이용함
		_id = s_idGenerator++;
		cout << _id << endl;
	}

public:
	int _id;
	static int s_idGenerator;
};

int Player::s_idGenerator = 1;

int GenerateId()
{
	// static local 변수
	// 함수 호출될때 딱한번 초기화 한 후 전역 변수처럼 이용됨
	static int s_id = 10;

	return s_id++;
}

// 자료구조&알고리즘
// 디자인 패턴
// - 싱글톤, 옵저버, 컴포넌트, ...

// 싱글톤 : 정말 딱 1개만 존재하고 어디서든 사용할 수 있는 [매니저] 클래스
class UserManager
{
public:
	static UserManager* GetInstance()
	{
		static UserManager um;
		return &um;
	}

public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount; }

private:
	int _userCount = 0;

};

#define GETR_MANAGER (UserManager::GetInstance())

int main()
{
	//Knight1 k1;
	//Knight2 k2;

	/*Marine m1;
	m1._hp = 40;

	Marine m2;
	m2._hp = 10;*/
	//따로 객체를 생성하지 않아도 함수 사용 가능
	Marine::SetAttack(10);

	Marine::attack = 7;

	Player p1;
	Player p2;
	Player p3;

	for(int i = 0; i <10 ; i++)
		UserManager::GetInstance()->AddUser();

	cout << UserManager::GetInstance()->GetUserCount() << endl;
}