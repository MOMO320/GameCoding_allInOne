#include "Player.h"
#include "Map.h"
#include "Helper.h"

int GPlayerX = 2;
int GPlayerY = 2;

bool canMove = true;

void HandleMove()
{
	// 키보드 떼고 있으면, 다음 번엔 움직일 수 있다.
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	// 움직일 수 있는지?
	if (canMove == false)
		return;

	canMove = false;

	switch (GMoveDir)
	{
	case MD_LEFT:
		MovePlayer(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer(GPlayerX, GPlayerY + 1);
		break;
	}
}


void MovePlayer(int x, int y)
{
	// 범위 체크
	if (x < 0 || x > MAP_SIZE)
		return;

	if (y < 0 || y > MAP_SIZE)
		return;

	{	// 2D 
	// 벽 체크
		int index = (MAP_SIZE * y) + x;
		if (GMap2D[y][x] == 1)
			return;

		// 기존 위치 정리
		{
			GMap2D[GPlayerY][GPlayerX] = 0;
		}

		// 새 위치 이동
		{
			GPlayerX = x;
			GPlayerY = y;
			GMap2D[y][x] = 2;
		}
	}


	//{	// 1D 
	//	// 벽 체크
	//	int index = (MAP_SIZE * y) + x;
	//	if (GMap1D[index] == 1)
	//		return;

	//	// 기존 위치 정리
	//	{
	//		int index = GPlayerY * MAP_SIZE + GPlayerX;
	//		GMap1D[index] = 0;
	//	}

	//	// 새 위치 이동
	//	{
	//		GPlayerX = x;
	//		GPlayerY = y;
	//		int index = GPlayerY * MAP_SIZE + GPlayerX;
	//		GMap1D[index] = 2;
	//	}
	//}

}