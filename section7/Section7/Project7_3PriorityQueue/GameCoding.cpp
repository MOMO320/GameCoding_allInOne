#include <iostream>
using namespace std;
#include <vector>
#include <queue>

/*

	�� �켱 ���� ť

	�� ���� Ʈ��
	: �� ��尡 �ִ� �� ���� �ڽ� ��带 ������ Ʈ��(Left Child , Right Child)

	- ���� �˻� Ʈ�� Ư¡
	1). ������ Ÿ�� ���� ���� ������ �۴�
	2). �������� Ÿ�� ���� ���� ������ ũ��.

	- ���� �˻� Ʈ�� ����
	: �׳� �����ϰ� �߰��ϸ� �������� �������� ������ ������.
	  Ʈ�� ���ġ�� ���� ������ �����ϴ� ���� ����(AVL, Red-Black)

	�� �� Ʈ�� Ư¡
	- �� Ʈ�� 1��Ģ: [�θ� ���]�� ���� ���� �׻�[�ڽ� ���]�� ���� ������ ũ��.
	1). ������ ������ ������ ��� ������ ��尡 �� �� �ִ�.(���� ���� Ʈ��)
	2). ������ ������ ��尡 ���� ����, �׻� ���ʺ��� ������� ä���� �Ѵ�.

	- �� Ʈ�� 2��Ģ: ��� ������ �˸�, Ʈ�� ������ ������ Ȯ���� �� �ִ�.

	- �� Ʈ�� ���� : �迭�� �̿��ؼ� �� ������ �ٷ� ǥ�� �� �� �ִ�.
	1). i�� ����� ���� �ڽ���[(2*i)+1]��
	2). i�� ����� ������ �ڽ��� [(2*i)+2]��
	3). i�� ����� �θ�� [(i-1)/2]��

	- �ڷᱸ�� ��??
*/

template<typename T , typename Predicate = less<T>>
class PriorityQueue
{
public:
	// O(log n): �ð� ���⵵
	void push(const T& data)
	{
		// �켱 �� �������� �����ش�.
		_heap.push_back(data);

		// ������� ����
		int now = static_cast<int>(_heap.size()) - 1;

		// ��Ʈ ������
		while (now > 0)
		{
			// �θ� ���� ���ؼ� �� ������ �й�
			int next = (now - 1) / 2; // �θ����� �ε���

			//if (_heap[now] < _heap[next])
			//	break;

			if (_predicate(_heap[now], _heap[next]))
				break;

			// ������ ��ü
			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	// O(log n): �ð� ���⵵
	void pop()
	{
		// 1. �ִ밪�� ���� �����Ѵ�.
		// 2. �������� �ִ� �����͸� �� ���� �ø���.[0]
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// ������ ������ ���
			if (left >= (int)_heap.size())
				break;

			int next = now;

			// ���� ��
			if (_heap[next] < _heap[left])
				next = left;

			// �� �� ���ڸ� �����ʰ� ��
		/*	if (right < _heap.size() && _heap[next] < _heap[right])
				next = right;*/

			if(right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// ���� , ������ �Ѵ� ���� ������ ������ ����
			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	// O(1) : �ð� ���⵵
	T& top()
	{
		return _heap[0];
	}
	
	// O(1) : �ð� ���⵵
	bool empty()
	{
		return _heap.empty();
	}

private:
	vector<T> _heap;
	Predicate _predicate;
};

int main()
{
	vector<int> v;
	priority_queue<int> pQ;

	PriorityQueue<int , greater<int>> pq;

	pq.push(10);
	pq.push(20);
	pq.push(50);
	pq.push(30);
	pq.push(100);
	pq.push(40);
	pq.push(80);

	int value = pq.top();
	cout << value << endl;
	pq.pop();

}