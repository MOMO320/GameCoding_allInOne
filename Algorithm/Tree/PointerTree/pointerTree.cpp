#include <iostream>
#include "vector"

using namespace std;

// 왼쪽 자식 노드
// 값
// 오른쪽 자식 노드

class Node
{
public:
	Node() {};
	~Node() {};

public:
	int		_data;
	Node* _leftNode;
	Node* _rightNode;
};

class Tree
{
public:
	Tree() {};
	~Tree() {};

	void InsertNode(Node* node, int data)
	{
		_index++;

		if (_rootNode == nullptr)
		{
			_rootNode = node;
			return;
		}

		_rootNode->

		for (int i = 0; i < _index; i++)
		{
			_rootNode->_
		}
			



		
	}

public:
	Node*	_rootNode;
	int		_index;
};

/


int main()
{
	Tree tree;

	Node node(nullptr, nullptr, 4);
	tree._rootNode = 
		


}