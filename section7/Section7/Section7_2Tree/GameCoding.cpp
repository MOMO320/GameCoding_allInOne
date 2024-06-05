#include <iostream>
#include <vector>
using namespace std;

/*
*	7_2) Tree
* 
	Ʈ���� ����
	: ������ ������ ���� �����͸� ǥ���ϱ� ���� �ڷᱸ��

	�� ����Լ��� ����ϸ� Ʈ���� �� �´���?
	:Ʈ�� ������ �ξ� �� ���� �����ϰų� �ƴϸ� Ž���� �ϰų� �۾��� �� �� �ִ�.

	Ʈ���� ����Լ��� ������ �� �´´�.

	�������� �þ��.

	�� ���(Node) : �����͸� ǥ��
	�� ����(Edge) : ����� ���� ������ ǥ���ϱ� ���� ���
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
	Node* root = new Node("R1 ���߽�");
	{
		Node* node = new Node("��������");
		root->children.push_back(node);
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("���丮");
			node->children.push_back(leaf);
		}
	}
	{
		Node* node = new Node("���α׷���");
		root->children.push_back(node);
		{
			Node* leaf = new Node("Ŭ��");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("����");
			node->children.push_back(leaf);
			{
				Node* nLeaf = new Node("�𸮾�");
				leaf->children.push_back(nLeaf);
			}
			{
				Node* nLeaf = new Node("����Ƽ");
				leaf->children.push_back(nLeaf);
			}
		}
	}
	{
		Node* node = new Node("��Ʈ");
		root->children.push_back(node);
		{
			Node* leaf = new Node("���");
			node->children.push_back(leaf);
		}
		{
			Node* leaf = new Node("ĳ����");
			node->children.push_back(leaf);
		}
	}
	
	return root;
}

// ����(depth) : ��Ʈ���� � ��忡 �����ϱ� ���� ���ľ� �ϴ� ������ ����
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

// ����
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