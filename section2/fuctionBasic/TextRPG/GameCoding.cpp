#include <iostream>
using namespace std;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
void WaitForNextKey();


enum PlayerType
{
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum MonsterType
{
	MT_None = 0,
	MT_Slime = 1,
	MT_Orc =2,
	MT_Skeleton = 3,
};

PlayerType playerType;
StatInfo playerStat;

MonsterType monsterType;
StatInfo monsterStat;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

int main()
{
	// random�� �ֱ����� �õ尪 ����
	srand(time(0));
	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		cout << "-------------------------------------------------" << endl;
		cout << "             �κ� �����߽��ϴ�!                " << endl;
		cout << "-------------------------------------------------" << endl;

		// �÷��̾� ���� ����
		SelectPlayer();
		
		cout << "-------------------------------------------------" << endl;
		cout << "      (1) �ʵ� ����    (2) ���� ����             " << endl;
		cout << "-------------------------------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{

	while (true)
	{
		cout << "-------------------------------------------------" << endl;
		cout << "               ������ ����ּ���!                " << endl;
		cout << "           (1) ���  (2) �ü� (3) ����           " << endl;
		cout << "-------------------------------------------------" << endl;
		cout << " > ";

		int choice;
		cin >> choice;

		if (choice == PT_Knight)
		{
			cout << "��� ������..." << endl;
			playerStat.hp = 150;
			playerStat.attack = 10;
			playerStat.defence = 5;
			playerType = PT_Knight;
			break;
		}
		else if (choice == PT_Archer)
		{
			cout << "�ü� ������..." << endl;
			playerStat.hp = 80;
			playerStat.attack = 25;
			playerStat.defence = 0;
			playerType = PT_Archer;
			break;
		}
		else if (choice == PT_Mage)
		{
			cout << "������ ������..." << endl;
			playerStat.hp = 60;
			playerStat.attack = 30;
			playerStat.defence = 5;
			playerType = PT_Archer;
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "-------------------------------------------------" << endl;
		cout << "                �ʵ忡 �����߽��ϴ�!             " << endl;
		cout << "-------------------------------------------------" << endl;

		cout << "[PLAYER} HP : " << playerStat.hp << "/ ATT : " << playerStat.attack << " / DEF : " << playerStat.defence << endl;

		// ���� ����
		CreateRandomMonster();

		cout << "-------------------------------------------------" << endl;
		cout << "           (1) ����         (2) ����             " << endl;
		cout << "-------------------------------------------------" << endl;
		cout << " > ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (playerStat.hp == 0)
			{
				WaitForNextKey();
				return;
			}
		}
		else
		{
			return;
		}
	}
	
}

void CreateRandomMonster()
{
	int randomChoice = 1 + (rand() % 3);

	switch (randomChoice)
	{
	case MT_Slime:
		cout << "������ ������...! (HP : 30 / ATT : 2 / DEF : 0)" << endl;
		monsterStat.hp = 30;
		monsterStat.attack= 2;
		monsterStat.defence = 0;
		monsterType = MT_Slime;
		break;

	case MT_Orc:
		cout << "��ũ ������...! (HP : 40 / ATT : 10 / DEF : 3)" << endl;
		monsterStat.hp = 40;
		monsterStat.attack = 10;
		monsterStat.defence = 3;
		monsterType = MT_Orc;
		break;
	case MT_Skeleton:
		cout << "���̷��� ������...! (HP : 80 / ATT : 15 / DEF : 5)" << endl;
		monsterStat.hp = 80;
		monsterStat.attack = 15;
		monsterStat.defence = 5;
		monsterType = MT_Skeleton;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerStat.attack - monsterStat.Defence;
		if (damage < 0)
			damage = 0;

		// ����
		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)
			monsterStat.hp = 0;

		cout << "���� ���� ü�� : " << monsterStat.hp << endl;

		if (monsterStat.hp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�!" << endl;
			WaitForNextKey();
			return;
		}


		// �ݰ�
		damage = monsterStat.attack - playerStat.defence;
		if (damage < 0)
			damage = 0;

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
			playerStat.hp = 0;

		cout << "�÷��̾� ���� ü�� : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << "����� ����߽��ϴ�...GameOver!" << endl;
			return;
		}
	}
}

void WaitForNextKey()
{
	cout << "����Ϸ��� 1�� �����ּ���" << endl;
	cout << "> ";

	int input;
	cin >> input;

	// �ܼ� Ŭ����
	system("cls");
}