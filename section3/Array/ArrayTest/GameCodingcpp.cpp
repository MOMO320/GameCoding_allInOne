#include <iostream>
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include  <Windows.h>

using namespace std;

int map[25];

// 2���� �迭 -> �޸� ���������� �ٸ��� ����.

int main()
{
	SetCursorOnOff(false);

	//MovePlayer(3, 2);

	while (true)
	{
		// �Է�
		HandleKeyInput();

		// ����
		HandleMove();

		// ���
		PrintMap1D();
		
	};


	return 0;
} 