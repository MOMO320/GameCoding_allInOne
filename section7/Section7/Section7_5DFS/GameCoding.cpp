#include <iostream>
#include "vector"
#include "queue"
using namespace std;

/*
	ㅁ DFS (depth first search)
	DFS = 재귀 함수 = stack
*/

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// 내가 방문한 목록
vector<bool> visitied;

void CreateGraph()
{
	vertices.resize(6);

	// 인접 리스트
	//adjacent = vector<vector<int>>(6);
	//adjacent[0] = { 1,3 };
	//adjacent[1] = { 0,2,3 };
	//adjacent[3] = { 4 };
	//adjacent[5] = { 4 };

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0,1,0,1,0,0},
		{1,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0},
		{0,0,0,0,0,0},
		{0,0,0,0,1,0}
	};
}

void Dfs(int here)
{
	// 방문 도장
	visitied[here] = true;
	cout << "Visited : " << here << endl;

	// 시간 복잡도 E -> 총 개수

	// 인접한 길을 다 체크해서
	// 인접 리스트 시간 복잡도 0(V+E) 
	//int size = adjacent[here].size();
	//for (int i = 0; i < size; i++)
	//{
	//	int there = adjacent[here][i];

	//	if (visitied[there] == false)
	//		Dfs(there);
	//}


	//----------------  인접 행렬로 작업 ------------------
	// 인접 행령 시간 복잡도 0(V∧2)
	for (int there = 0; there < 6; there++)
	{
		// 길은 있는지
		if (adjacent[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳에 한해서 방문
		if (visitied[there] == false)
			Dfs(there);
	}
}

void DfsAll()
{
	visitied = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if (visitied[i] == false)
		{
			Dfs(i);
			//cout << "HI" << endl;
		}
	}	
}

int main()
{
	CreateGraph();

	DfsAll();
	
}
