#include <iostream>
#include "vector"
#include "queue"
using namespace std;

/*
	�� DFS (depth first search)
	DFS = ��� �Լ� = stack
*/

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// ���� �湮�� ���
vector<bool> visitied;

void CreateGraph()
{
	vertices.resize(6);

	// ���� ����Ʈ
	//adjacent = vector<vector<int>>(6);
	//adjacent[0] = { 1,3 };
	//adjacent[1] = { 0,2,3 };
	//adjacent[3] = { 4 };
	//adjacent[5] = { 4 };

	// ���� ���
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
	// �湮 ����
	visitied[here] = true;
	cout << "Visited : " << here << endl;

	// �ð� ���⵵ E -> �� ����

	// ������ ���� �� üũ�ؼ�
	// ���� ����Ʈ �ð� ���⵵ 0(V+E) 
	//int size = adjacent[here].size();
	//for (int i = 0; i < size; i++)
	//{
	//	int there = adjacent[here][i];

	//	if (visitied[there] == false)
	//		Dfs(there);
	//}


	//----------------  ���� ��ķ� �۾� ------------------
	// ���� ��� �ð� ���⵵ 0(V��2)
	for (int there = 0; there < 6; there++)
	{
		// ���� �ִ���
		if (adjacent[here][there] == 0)
			continue;

		// ���� �湮���� ���� ���� ���ؼ� �湮
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
