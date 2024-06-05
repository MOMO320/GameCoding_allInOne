#include <iostream>
#include <vector>
using namespace std;

/*
*	7_2) Tree
* 
	트리의 개념
	: 계층적 구조를 갖는 데이터를 표현하기 위한 자료구조

	왜 재귀함수를 사용하면 트리랑 잘 맞는지?
	:트리 구조를 훨씬 더 쉽게 구현하거나 아니면 탐색을 하거나 작업을 할 수 있다.

	트리와 재귀함수는 궁합이 잘 맞는다.

	동적으로 늘어난다.

	ㆍ 노드(Node) : 데이터를 표현
	ㆍ 간선(Edge) : 노드의 계층 구조를 표현하기 위해 사용
*/

class Node
{
public:
	Node(const char* data) : data(data) {}

public:
	const char* data;
	vector<Node*> children;
};

Node* CreateTree()
{
	Node* root = new Node("R1 개발실");
	{
		Node* node = new Node("디자인팀");
		root->children.push_back(node);
		{
			Node* leaf = new Node("전투");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("경제");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("스토리");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("프로그래밍");
		root->children.push_back(node);
		{
			Node* leaf = new Node("클라");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("서버");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("엔진");
			node->children.push_back(leaf);
			{
				Node* nLeaf = new Node("언리얼");
				leaf->children.push_back(nLeaf);
			}
			{
				Node* nLeaf = new Node("유니티");
				leaf->children.push_back(nLeaf);
			}
		}
	}
	{
		Node* node = new Node("아트");
		root->children.push_back(node);
		{
			Node* leaf = new Node("배경");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("캐릭터");
			node->children.push_back(leaf);
		}
	}
	
	return root;
}

// 깊이(depth) : 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 개수
void PrintTree(Node* root, int depth = 0)
{
	for (int i = 0; i < depth; i++)
		cout << "-";

	cout << root->data << endl;
	
	int size = root->children.size();

	if (size == 0)
		return;

	for (int i = 0; i < size; i++)
	{
		Node* node = root->children[i];
		PrintTree(node, depth+1);
	}
	cout << endl;
}

// 높이
int GetHeight(Node* root)
{
	int ret = 1;
	int size = root->children.size();
	for (int i = 0; i < size; i++)
	{
		Node* node = root->children[i];
		int h = GetHeight(node) + 1;

		if (ret < h)
			ret = h;
	}


	return ret;
}


int main()
{
	Node* root = CreateTree();

	PrintTree(root);

	cout << GetHeight(root) << endl;
}