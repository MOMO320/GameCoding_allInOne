#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Node
{
	// typedef int T;	// (옛날 방법)별칭
	//using T = int;		// (요즘 방법)별칭
public:
	Node(T data) : _data(data), prev(nullptr), next(nullptr) { }

public:
	T		_data;
	Node*	prev;
	Node*	next;
};


template<typename T>
class List
{
public:
	List()
	{
		_head = new Node<T>(0);
		_tail = new Node<T>(0);

		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node<T>* node = _head;

		while (node != nullptr)
		{
			Node<T>* deleteNode = node;
			node = node->next;
			delete deleteNode;
		}
	}


	// [dummy]<->[1]<->[2]<->[3]<->[dummy]
	// [head]                       [tail]
	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->next;

		if (node == _tail)
			return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev)
				return nullptr;

				node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node<T>* node = _head->next;

		while (node != _tail)
		{
			std::cout << node->_data << std::endl;
			node = node->next;
		}
		std::cout << std::endl;
	}


	//       [node]
	// [dummy]<->[nextNode]<->[2]<->[3]<->[dummy]
	// [head]                         [tail]
	Node<T>* AddHead(int data)
	{
		Node<T>* node = new Node<T>(data);
	
		Node<T>* nextNode = _head->next;
			
		// 더미를 활용한 코드
		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;


		{ // 더미 노드 없을때 아래처럼
			//if (_head == nullptr)
			//{
			//	_head = node;
			//	_tail = node;
			//}
			//else
			//{
			//	Node* nextNode = _head;
			//	node->next = nextNode;
			//	nextNode->prev = node;
			//	_head = node;
			//}
		}

		return node;
	}

	//								  [node]
	// [dummy]<->[1]<->[2]<->[prevNode]<->[dummy]
	// [head]                         [tail]
	Node<T>* AddAtaTail(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}
	
	//					  [node]
	// [dummy]<->[prevNode]<->[posNode]<->[3]<->[4]<->[dummy]
	// [head]                                [tail]
	void Insert(Node<T>* posNode, int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = posNode->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

	//						// 삭제
	// [dummy]<->[prevNode]<->[node]<->[nextNode]<->[3]<->[dummy]
	// [head]                                [tail]
	void Remove(Node<T>* node)
	{
		Node<T>* prveNode = node->prev;
		Node<T>* nextNode = node->next;
		prveNode->next = nextNode;
		nextNode->prev = prveNode;

		delete node;
	}

	/* 특정 노드를 알고 있을때, 중간 삽입, 삭제가 용이 하다는 뜻 */
	
private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
	int _count = 0;
};

