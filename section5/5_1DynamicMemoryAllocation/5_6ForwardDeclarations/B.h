#pragma once

// 상속을 하는 경우에는 헤더를 추가 할 수 밖에 없지만
// 일반적으로 클래스를 알아야 한다면 전방선언을 하는 것이 좋다.


// 전방 선언
/*
	식별자(함수, 변수, 객체) 등을 정의하기 전에 식별자의 존재를
	컴파일러에게 알려주는 것이다.
	C++에서 헤더파일과 cpp파일을 분리한 후에 헤더파일에 먼저 선언을 해주고 cpp파일에서
	정의를 하는 것도 이러한 것이라고 볼 수 있다.
	왠만하면 헤더파일에 #include "클래스" 해주는 상황을 피하기 위해 전방 선언 하여
	클래스의 존재를 알려주게 하는 것이다.
	전방 선언 후 cpp 파일에 include 해주면 된다.
*/

/*
  습관적으로 헤더에 헤더를 추가하는 경우
  - 코드가 무거워 진다.
  - 헤더가 꼬인다.
*/
class A;

class B
{
public:
	B();
	//{
	//	// 전방선언을 한 클래스를 알려만 준거지
	//	// 사용 할 순 없다.
	//	// a->mp = 10;
	//}

public:
	int hp;
	int defence;
	int attack;
	
	A* a;
};

