#include <iostream>
#include "vector"

using namespace std;

class Tree
{
public:
	Tree(int size , int data): _size(size)
	{
		_datas.resize(size);
		_datas[1] = data;	// index 1번 부터 시작
	}
	~Tree() {}

	void SetLeftNode(int parentIndex, int data)
	{
		int value = (parentIndex * 2);

		if (value > _size) return;

		_datas[value] = data;
	}

	void SetRightNode(int parentIndex, int data)
	{
		int value = (parentIndex * 2) + 1;

		if (value > _size) return;

		_datas[value] = data;
	}

	void PrintTreeData()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << "Index [" << i <<"] : " << _datas[i] << endl;
		}
	}

public:
	vector<int> _datas;
	int _size = 0;
};

int main()
{
	Tree tree(15 , 1);

	tree.SetLeftNode(1, 4);
	tree.SetRightNode(1, 8);

	tree.SetLeftNode(2, 3);
	tree.SetRightNode(2, 5);

	tree.SetLeftNode(4, 2);

	tree.SetRightNode(3, 7);
	tree.SetLeftNode(7, 6);

	tree.PrintTreeData();

}