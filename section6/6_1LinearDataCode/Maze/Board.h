#pragma once
#include "ConsoleHelper.h"
// 스크린에 그려주는 맵을 만들어줄 클래스

enum
{	// 상수
	BOARD_MAX_SIZE = 100
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL
};

class Board
{
public:
	Board();
	~Board();

	void			Init(int32 size);
	void			Render();

	void			GenerateMap();
	TileType		GetTileType(Pos pos);
	ConsoleColor	GetTileColor(Pos pos);

	Pos				GetEnterPos() { return Pos(1, 1); }
	Pos				GetExitPos() { return Pos(_size, _size); }

private:
	TileType		_tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
	int32			_size = 0;
};

