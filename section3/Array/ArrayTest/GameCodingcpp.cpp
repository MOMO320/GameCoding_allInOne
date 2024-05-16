#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include  <Windows.h>

using namespace std;

int map[25];

// 2차원 배열 -> 메모리 구조적으로 다를건 없다.

int main()
{
	SetCursorOnOff(false);

	//MovePlayer(3, 2);

	while (true)
	{
		// 입력
		HandleKeyInput();

		// 로직
		HandleMove();

		// 출력
		PrintMap1D();
		
	};


	return 0;
} 