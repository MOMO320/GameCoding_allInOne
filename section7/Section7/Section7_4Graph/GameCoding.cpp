#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
	ㅁ 그래프의 개념

		- 정점(Vertext) : 데이터를 표현
		- 간선(Edge) : 정점들을 연결하는데 사용

	- 정점이 100개
	   - 지하철 노선도 -> 서로 드문 드문 연결
	   - 페이스북 친구 -> 서로 빽빽하게 연결

	- 방향 그래프
	 ex) 일방 통행이 포함된 도로망
	 ex) 두 사람 사이의 호감도

	- 가중치 그래프
	ex)  지하철 노선도

	 - 그래프의 표현

*/


//↓ 사용하지 않는 방법
//void CreateGraph_1()
//{
//	struct Vertex
//	{
//		vector<Vertex*> edges;
//	};
//
//	vector<int> v2(10, -1);	// 데이터 사이즈 , 데이터 초기화 값을 정해줄 수 있다.
//	vector<int> v3{ 1,2,3,4,5,6,7 };
//
//	vector<Vertex> v(6);
//
//	v.resize(6);	// size
//	v.reserve(6);	// capacity
//
//	v[0].edges.push_back(&v[1]);
//	v[0].edges.push_back(&v[3]);
//	
//	v[1].edges.push_back(&v[0]);
//	v[1].edges.push_back(&v[2]);
//	v[1].edges.push_back(&v[3]);
//
//	v[3].edges.push_back(&v[4]);
//
//	v[5].edges.push_back(&v[4]);
//
//	// Q. 0번-> 3번이 연결되어 있나요?
//	bool connected = true;
//
//	int size = v[0].edges.size();
//	for (int i = 0; i < size; i++)
//	{
//		Vertex* vertex = v[0].edges[i];
//
//		if (vertex == &v[3])
//		{
//			connected = true;
//		}
//
//	}
//}


// 인접 리스트 : 실제 연결된 애들만 넣어준다.
void CreateGraph_2()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);

	vector<vector<int>> adjacent;
	adjacent.resize(6);

	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4};
	adjacent[5] = { 4 };

	// Q) 0번->3번 연결되어 있나요?

	bool connected = false;

	int size = adjacent[0].size();

	for (int i = 0; i < size; i++)
	{
		int vertex = adjacent[0][i];
		if (vertex == 3)
		{
			connected = true;
		}
	}
}

// 인접 행렬(정점이 대부분이 연결이 되어 있을 경우 사용하기 좋은 방법 이다.)
void CreateGraph_3()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex>v(6);

	// 연결된 목록을 행렬로 관리
	//[x][0][x][0][x][x]
	//[0][x][0][0][x][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][0][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][0][x]

	// adjacent[from][to] ?
	// 행렬을 이용한 그래프 표현
	// 메모리 소모가 심하지만, 빠른 접근

	vector<vector<bool>> adjacent(6, vector<bool>(6, false));

	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// Q) 0번 -> 3번 연결되어 있나요?
	// 일일이 서칭해서 3이 들어가 있는지 체크해야 할 필요 없다.

	bool connected = adjacent[0][3];	// 바로 확인 가능

	// 연결되어있는 데이터의 가중치를 아래와 같이 표현(-1 == false)
	vector<vector<int>> adjacent2 =
	{
		{-1, 15, -1, 35, -1, -1},
		{15, -1, +5, 10, -1, -1},
		{-1, +5, -1, 35, -1, -1},
		{35, 10, -1, -1, +5, -1},
		{-1, -1, -1, +5, -1, +5},
		{-1, -1, -1, -1, +5, -1},
	};
}


int main()
{
	vector<int> v;


}