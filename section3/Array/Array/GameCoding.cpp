#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int damage;
	int defence;
};

// [0][1][2][3][4][5][6]
int main()
{
	// �迭�� ��� ũ�⸦ ������ �� �����ϴ�.
	// ������ Ÿ���� �����͸� �����Ҷ� ���ϴ�.
	//StatInfo monster[10];

	// �ʱ�ȭ ���

	//int arr[5] = { 1,2,3,4,5 };
	
	int arr[] = { 1,2,3,4,5 };

	//arr[0] = 10;
	//arr[1] = 20;
	//arr[2] = 30;
	//arr[3] = 40;
	//arr[4] = 50;
	

	for (int i = 0; i < 5; i++)
		arr[i] = i * 10;

	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;

	return 0;
}