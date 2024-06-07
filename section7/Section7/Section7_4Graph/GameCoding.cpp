#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
	�� �׷����� ����

		- ����(Vertext) : �����͸� ǥ��
		- ����(Edge) : �������� �����ϴµ� ���

	- ������ 100��
	   - ����ö �뼱�� -> ���� �幮 �幮 ����
	   - ���̽��� ģ�� -> ���� �����ϰ� ����

	- ���� �׷���
	 ex) �Ϲ� ������ ���Ե� ���θ�
	 ex) �� ��� ������ ȣ����

	- ����ġ �׷���
	ex)  ����ö �뼱��

	 - �׷����� ǥ��

*/


//�� ������� �ʴ� ���
//void CreateGraph_1()
//{
//	struct Vertex
//	{
//		vector<Vertex*> edges;
//	};
//
//	vector<int> v2(10, -1);	// ������ ������ , ������ �ʱ�ȭ ���� ������ �� �ִ�.
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
//	// Q. 0��-> 3���� ����Ǿ� �ֳ���?
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


// ���� ����Ʈ : ���� ����� �ֵ鸸 �־��ش�.
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

	// Q) 0��->3�� ����Ǿ� �ֳ���?

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

// ���� ���(������ ��κ��� ������ �Ǿ� ���� ��� ����ϱ� ���� ��� �̴�.)
void CreateGraph_3()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex>v(6);

	// ����� ����� ��ķ� ����
	//[x][0][x][0][x][x]
	//[0][x][0][0][x][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][0][x]
	//[x][x][x][x][x][x]
	//[x][x][x][x][0][x]

	// adjacent[from][to] ?
	// ����� �̿��� �׷��� ǥ��
	// �޸� �Ҹ� ��������, ���� ����

	vector<vector<bool>> adjacent(6, vector<bool>(6, false));

	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// Q) 0�� -> 3�� ����Ǿ� �ֳ���?
	// ������ ��Ī�ؼ� 3�� �� �ִ��� üũ�ؾ� �� �ʿ� ����.

	bool connected = adjacent[0][3];	// �ٷ� Ȯ�� ����

	// ����Ǿ��ִ� �������� ����ġ�� �Ʒ��� ���� ǥ��(-1 == false)
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