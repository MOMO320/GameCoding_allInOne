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
	// 배열의 경우 크기를 변경할 수 없습니다.
	// 동일한 타입의 데이터를 관리할때 편리하다.
	//StatInfo monster[10];

	// 초기화 방법

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