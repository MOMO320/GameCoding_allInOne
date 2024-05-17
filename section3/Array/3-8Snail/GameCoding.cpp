#include <iostream>
#include <iomanip>
using namespace std;

//달팽이 문제

const int MAX = 100;
int board[MAX][MAX];
int n;

void PrintBoard()
{

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{

			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
	

		cout << endl;
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT= 2,
	UP = 3,
};

bool CanGo(int y, int x)
{
	if (y < 0 || y >= n)
		return false;
	if (x < 0 || x >= n)
		return false;
	if (board[y][x] != 0)
		return false;

	return true;
}

void SetBoard2()
{
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;

	// 방향에 따른 값 변경
	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };

	while (true)
	{
		board[y][x] = num;

		// 빠져나가는 조건부 
		if (num == n * n)
			break;

		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		
		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}
}

void SetBoard()
{
	int dir = RIGHT;
	int num = 1;
	int y = 0; 
	int x = 0;

	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };

	while (true)
	{
		board[y][x] = num;

		// 빠져나가는 조건부 
		if (num == n * n)
			break;

		int nextY;
		int nextX;

		switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;

		case DOWN:
			nextY = y + 1;
			nextX = x;
			break;

		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;

		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		}

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		} 
		else
		{
			switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;

			case DOWN :
				dir = LEFT;
				break;

			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}
		}
	}
}

//[ ][ ][ ][ ][ ]
//[ ][ ][ ][ ][ ]
//[ ][ ][ ][ ][ ]
//[ ][ ][ ][ ][ ]
//[ ][ ][ ][ ][ ]

int main()
{
	cin >> n;
	//SetBoard();
	SetBoard2();
	PrintBoard();
}