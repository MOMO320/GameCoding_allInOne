#pragma once

class Player
{// ���赵 ��ü�� �����Ѵ�.(�÷��̾�, ����, GameRoom, Lobby, PlayerManager, ...)
// Ŭ������ ��������� �޸𸮸� �������� �ʴ´�.

public:
	// Ŭ������ �Լ����� ������(�ڵ�) ������ ��� ���ϴ�.
	// ��� �Լ�
	void Attack();
	void Die();
	void HealMe(int value);

public:
	// ��� ����
	int hp;
	int attack;
	int defence;
};

