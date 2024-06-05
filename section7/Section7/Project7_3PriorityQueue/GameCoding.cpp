#include <iostream>
using namespace std;
#include <vector>
#include <queue>

/*

	ㅁ 우선 순위 큐

	ㅁ 이진 트리
	: 각 노드가 최대 두 개의 자식 노드를 가지는 트리(Left Child , Right Child)

	- 이진 검색 트리 특징
	1). 왼쪽을 타고 가면 현재 값보다 작다
	2). 오른쪽을 타고 가면 현재 값보다 크다.

	- 이진 검색 트리 문제
	: 그냥 무식하게 추가하면 한쪽으로 기울어져서 균형이 깨진다.
	  트리 재배치를 통해 균형을 유지하는 것이 과제(AVL, Red-Black)

	ㅁ 힙 트리 특징
	- 힙 트리 1법칙: [부모 노드]가 가진 값은 항상[자식 노드]가 가진 값보다 크다.
	1). 마지막 레벨을 제외한 모든 레벨에 노드가 꽉 차 있다.(완전 이진 트리)
	2). 마지막 레벨에 노드가 있을 때는, 항상 왼쪽부터 순서대로 채워야 한다.

	- 힙 트리 2법칙: 노드 개수를 알면, 트리 구조는 무조건 확정할 수 있다.

	- 힙 트리 구현 : 배열을 이용해서 힙 구조를 바로 표현 할 수 있다.
	1). i번 노드의 왼쪽 자식은[(2*i)+1]번
	2). i번 노드의 오른쪽 자식은 [(2*i)+2]번
	3). i번 노드의 부모는 [(i-1)/2]번

	- 자료구조 힙??
*/

template<typename T , typename Predicate = less<T>>
class PriorityQueue
{
public:
	// O(log n): 시간 복잡도
	void push(const T& data)
	{
		// 우선 힙 구조부터 맞춰준다.
		_heap.push_back(data);

		// 도장깨기 시작
		int now = static_cast<int>(_heap.size()) - 1;

		// 루트 노드까지
		while (now > 0)
		{
			// 부모 노드와 비교해서 더 작으면 패배
			int next = (now - 1) / 2; // 부모노드의 인덱스

			//if (_heap[now] < _heap[next])
			//	break;

			if (_predicate(_heap[now], _heap[next]))
				break;

			// 데이터 교체
			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	// O(log n): 시간 복잡도
	void pop()
	{
		// 1. 최대값을 먼저 제거한다.
		// 2. 마지막에 있는 데이터를 맨 위로 올린다.[0]
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// 리프에 도달한 경우
			if (left >= (int)_heap.size())
				break;

			int next = now;

			// 왼쪽 비교
			if (_heap[next] < _heap[left])
				next = left;

			// 둘 중 승자를 오른쪽과 비교
		/*	if (right < _heap.size() && _heap[next] < _heap[right])
				next = right;*/

			if(right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// 왼쪽 , 오른쪽 둘다 현재 값보다 작으면 종료
			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	// O(1) : 시간 복잡도
	T& top()
	{
		return _heap[0];
	}
	
	// O(1) : 시간 복잡도
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