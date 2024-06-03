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

		// �̵�
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

	// ������
	Pos dest = _board->GetExitPos();

	//for (int i = 0; i < 20; i++)
	//{
	//	pos += Pos(1, 0);
	//	_path.push_back(pos);
	//}

	_dir = 3;	// ���� �ٶ󺸴� ����
	pos = Pos(1,1);	// ���� ��ǥ

	Pos front[4] =
	{
		Pos(-1,0),	// Up
		Pos(0,-1),	// Left
		Pos(1,0),	// Down
		Pos(0,1)	// Right
	};

	// ���� �ٶ󺸴� ���� ���� �տ� �ִ� ��ǥ?
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
	
	// ������ ���� 90�� ȸ��
	//_dir = (_dir - 1) % DIR_COUNT;
	// 
	// ���� ���� 90�� ȸ��
	//_dir = (_dir + 1) % DIR_COUNT;

	// ������ ã�� ������ ã����(����!!!)
	bool isDown = false;

	while (pos != dest)
	{

		// ó������ ������ �������� ���ٰ�
		// ������ �Ʒ� �������� ����
		// �� ������ �Ǹ� �׶� ������ ������ 90�� Ʋ�� �� �� �� �ִ��� Ȯ��
		// �� �� �� ������ �Ǹ� �Ʒ� �������� �� �� �ִ��� Ȯ�� �� 
		// ������ ������ �������� Ʋ �� �ְ��ؼ� �ٽ� ��Ʈ�� ã�� ��
		{
			// ������ �������� �� �� �ִ��� üũ
			if (CanGo(pos + front[_dir]))
			{
				pos += front[_dir];
				_path.push_back(pos);
				isDown = false;
				
			}
			else
			{
				// �켱 �Ʒ� ���� üũ
				if (CanGo(pos + front[DIR_DOWN]))
				{
					pos += front[DIR_DOWN];
					_path.push_back(pos);

					if (isDown == false)
					{
						isDown = true;

						// ���� ������ �ٲ��ش�.
						if (_dir <= 0) _dir = 4;
							_dir = (_dir - 1) % 4;
					}
				}
				else
				{
					// ���� ������ �ٲ��ش�.
					if (_dir <= 0) _dir = 4;
					_dir = (_dir - 1) % 4;
				}

			}
		}

		//{
		//	// 1. ���� �ٶ󺸴� ������ ��������, ���������� �� �� �ִ��� Ȯ��
		//	if (CanGo(pos + front[3]))
		//	{
		//		// ������ �������� 90�� ȸ��

		//		// ������ �� �� ����
		//		pos += front[3];
		//		// ��ǥ ���
		//		_path.push_back(pos);
		//	}
		//	//2. ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��
		//	else if (CanGo(pos + front[2]))
		//	{
		//		//������ �� �� ����
		//		pos += front[2];
		//		// ��ǥ
		//		_path.push_back(pos);
		//	}
		//	else
		//	{
		//		pos += front[1];
		//		_path.push_back(pos);
		//		// ���� �������� 90�� ȸ��
		//	}
		//}
		
	}
}
