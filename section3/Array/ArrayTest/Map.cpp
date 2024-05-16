#include "Map.h"
#include "Helper.h"
#include <iostream>

using namespace std;

int GMap1D[MAP_SIZE * MAP_SIZE] =
{
	1,1,1,1,1,
	1,0,0,0,1,
	1,0,2,0,1,
	1,0,0,0,1,
	1,1,1,1,1
};

int GMap2D[MAP_SIZE][MAP_SIZE] =
{
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,2,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
};

void PrintMap1D()
{
	SetCursorPosition(0, 0);

	GMap2D[1][1];

	// 2차원 배열
	for (int y = 0; y < MAP_SIZE; y++)
	{
		for (int x = 0; x < MAP_SIZE; x++)
		{
			switch (GMap2D[y][x])
			{
			case 0:
				cout << "□";
				break;
			case 1:
				cout << "■";
				break;

			case 2:
				cout << "♨";
				break;
			}
		}
		cout << endl;
	}

	//for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++)
	//{
	//	switch (GMap1D[i])
	//	{
	//	case 0:
	//		cout << "□";
	//		break;
	//	case 1:
	//		cout << "■";
	//		break;

	//	case 2:
	//		cout << "♨";
	//		break;
	//	}

	//	if ((i + 1) % MAP_SIZE == 0)
	//		cout << endl;
	//}
}