#pragma once
#include "Vector.h"


// [front/back][ ][ ][ ][ ][ ][ ][ ]
// [ ][ ][front/back][ ][ ][ ][ ][ ]
template<typename T>
class Queue
{
public:
	Queue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		// TODO : �� ã���� üũ
		if (_size == _container.size())
		{

		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1);
		_size--;
	}

	T& front()
	{
		return _container[front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	Vector<T> _container;

	int _front = 0;
	int _back = 0;
	int  = 0;
};

