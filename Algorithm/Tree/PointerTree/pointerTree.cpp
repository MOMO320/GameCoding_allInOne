#include <iostream>
#include "vector"

using namespace std;

// ���� �ڽ� ���
// ��
// ������ �ڽ� ���

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