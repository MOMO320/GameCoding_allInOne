#include <iostream>
using namespace std;

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// OOP 3대 요소
// - 상속성 << inheritance
// - 은닉성 << data hiding (캡슐화 encapsulation)
// - 다형성

// 자동차
// - 핸들/페달/엔진/문/전기선/휘발유
// 구매자 입장에서 사용 : 핸들/페달/문
// 몰라 됨 : 엔진,전기선,휘발유

// 접근 지정자(보안 레벨 설정)
// public(공개적) vs protected(보호받는) vs private(개인적)

class Car
{
public:
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		//...
		PutFuellnEngine();
	}

// 외부에서 사용 못하게 함
private:
	void PutFuellnEngine() {}
	void ConnectCircuit() {}

// 상속 받은 애들은 사용 할 수 있다.
protected:
	void Disassemble() {} // 차를 분해시킨다.

public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 전기선
};

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// public : 공개적 상속
// protected :  보호받는 상속? 내 자손들한테만 물려 줄거다(public -> protected)
// private : 나까지만 상속 한다.(public , protected -> private)
class SuperCar : private Car
{
public :
	void Test()
	{
		Disassemble();
	}

public:

};

class UltraSuperCar : public SuperCar
{
public:
	void Test()
	{
		// Car의 public 함수를 사용 할 수 없다.
		//MoveHandle();	
	}
};

class Knight
{
public:
	// 원하는 부분만 노출
	void SetHp(int hp)
	{
		_hp = hp;

		if (_hp <= 50)
		{
			// TODO
		}
	}

	int GetHp()
	{
		return _hp;
	}

private:
	// 중요한 정보를 변수를 이용해 외부에서 변경 할 수 없게 처리 함
	/// 독단적이지 않고 묶어서 사용하게 해야 함
	int _hp;
};

int main()
{
	Car c;
	
	// 외부에서 사용 안됨
	//c.Disassemble();
}