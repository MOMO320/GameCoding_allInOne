#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 아래의 함수는 복사를 하기 때문에
// 문제가 없다.
StatInfo CreatePlayer()
{
	StatInfo info;

	cout << "플레이어 생성" << endl;

	info.hp = 100;
	info.attack = 10;
	info.defence = 2;

	return info;
};

// 문제 있는 함수(스택 메모리 안에 있는 변수를 넘겨주기 때문에
// 함수를 반환하게 되면 info의 정보는 없어진다. (주의 해야 한다.)
StatInfo* CreatePlayer2()
{
	StatInfo info;

	cout << "플레이어 생성" << endl;

	info.hp = 100;
	info.attack = 10;
	info.defence = 2;

	return &info;
}// 잘못된 코드

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
};

void Battle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;

		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;
		
		if (monster->hp == 0)
			return;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "플레이어 HP : " << player->hp << endl;

		if (player->hp == 0)
			return;

	}
}


int main()
{
	StatInfo player;
	player = CreatePlayer();

	StatInfo monster;
	CreateMonster(&monster);

	//StatInfo* player2;
	//player2 = CreatePlayer2();	// 문제가 있음

	Battle(&player, &monster);
}