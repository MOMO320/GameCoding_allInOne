#include <iostream>
#include "List.h"
#include "Array.h"
#include "Vector.h"
using namespace std;


int main()
{
	List<int> Li;

	Li.AddAtaTail(1);

	Node<int>* node = Li.AddAtaTail(2);
	Li.AddAtaTail(3);
	Li.AddAtaTail(4);
	Li.AddAtaTail(5);

	Li.Print();

	// 특정 위치 알고 있을때 빠르다.
	Li.Remove(node);

	Li.Print();


	Array arr(100);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	arr[1] = 2;

//	int b = arr[10000];


	Vector v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.pop_back();

	int a = v[1];
}
