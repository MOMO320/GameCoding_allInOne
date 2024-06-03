#include "pch.h"
#include "Board.h"
#include "Player.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	CalculatePath();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		// 이동
		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);

	return tileType == TileType::EMPTY;
}

void Player::CalculatePath()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지
	Pos dest = _board->GetExitPos();

	//for (int i = 0; i < 20; i++)
	//{
	//	pos += Pos(1, 0);
	//	_path.push_back(pos);
	//}

	_dir = 3;	// 내가 바라보는 방향
	pos = Pos(1,1);	// 현재 좌표

	Pos front[4] =
	{
		Pos(-1,0),	// Up
		Pos(0,-1),	// Left
		Pos(1,0),	// Down
		Pos(0,1)	// Right
	};

	// 내가 바라보는 방향 기준 앞에 있는 좌표?
	//Pos next = pos + front[_dir];
	{
		/*switch (_dir)
	{
	case DIR_UP:
		Pos next = pos + Pos(-1, 0);
		break;

	case DIR_LEFT:
		Pos next = pos + Pos(0, -1);
		break;

	case DIR_DOWN:
		Pos next = pos + Pos(1, 0);
		break;

	case DIR_RIGHT:
		Pos next = pos + Pos(0, 1);
		break;

	default:
		break;
	}*/
	}
	
	// 오른쪽 방향 90도 회전
	//_dir = (_dir - 1) % DIR_COUNT;
	// 
	// 왼쪽 방향 90도 회전
	//_dir = (_dir + 1) % DIR_COUNT;

	// 목적지 찾을 때까지 찾으라(숙제!!!)
	bool isDown = false;

	while (pos != dest)
	{

		// 처음에는 오른쪽 방향으로 갔다가
		// 못가면 아래 방향으로 가고
		// 또 못가게 되면 그땐 방향을 오른쪽 90도 틀은 후 갈 수 있는지 확인
		// 그 후 또 못가게 되면 아래 방향으로 갈 수 있는지 확인 후 
		// 없으면 오른쪽 방향으로 틀 수 있게해서 다시 루트를 찾게 함
		{
			// 오른쪽 방향으로 갈 수 있는지 체크
			if (CanGo(pos + front[_dir]))
			{
				pos += front[_dir];
				_path.push_back(pos);
				isDown = false;
				
			}
			else
			{
				// 우선 아래 방향 체크
				if (CanGo(pos + front[DIR_DOWN]))
				{
					pos += front[DIR_DOWN];
					_path.push_back(pos);

					if (isDown == false)
					{
						isDown = true;

						// 다음 방향을 바꿔준다.
						if (_dir <= 0) _dir = 4;
							_dir = (_dir - 1) % 4;
					}
				}
				else
				{
					// 다음 방향을 바꿔준다.
					if (_dir <= 0) _dir = 4;
					_dir = (_dir - 1) % 4;
				}

			}
		}

		//{
		//	// 1. 현재 바라보는 방향을 기준으로, 오른쪽으로 갈 수 있는지 확인
		//	if (CanGo(pos + front[3]))
		//	{
		//		// 오른쪽 방향으로 90도 회전

		//		// 앞으로 한 보 전진
		//		pos += front[3];
		//		// 좌표 기록
		//		_path.push_back(pos);
		//	}
		//	//2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		//	else if (CanGo(pos + front[2]))
		//	{
		//		//앞으로 한 보 전진
		//		pos += front[2];
		//		// 좌표
		//		_path.push_back(pos);
		//	}
		//	else
		//	{
		//		pos += front[1];
		//		_path.push_back(pos);
		//		// 왼쪽 방향으로 90도 회전
		//	}
		//}
		
	}
}
