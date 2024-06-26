#include <iostream>
#include "vector"
using namespace std;

// 선형 자료구조

/*
	ㅁ 선형 구조는 자료를 순차적으로 나열한 형태
	- 배열
	  ㆍ 사용할 방 개수를 고정해서 계약하고(절대 변경 불가)
	  ㆍ 연속된 방으로 배정 받아 사용

	  장점)
	  ㆍ연속된 방
	  단점)
	  ㆍ방을 추가/ 축소 불가
-----------------------------------------------------------------
	- 동적 배열(vector 등)
	  ㆍ사용할 방 개수를 유동적으로 계약
	  ㆍ연속된 방으로 배정 받아 사용

	 문제점)
	  ㆍ이사 비용이 크다.

	 동적 배열 할당 정책) 
	  ㆍ실제로 사용할 방보다 많이, 여유분을 두고(대략 1.5~2배) 예약
	  ㆍ이사 횟수를 최소화

	 장점)
	  ㆍ유동적인 계약(방 여유분 추가 예약으로 이사 횟수 최소화)
	 단점)
	  ㆍ중간 삽입 / 삭제
-----------------------------------------------------------------
	- 연결 리스트
	 ㆍ연속되지 않은 방을 사용

	 장점)
	  ㆍ중간 삽입 / 삭제 이점
	 단점)
	  ㆍ N번째 방을 바로 찾을 수가 없음(임의 접근 Random Access 불가)

	  ※ 임의 접근?
	   ㆍN번째 방이 몇 번 방인지 바로 찾을 수 있는지

-----------------------------------------------------------------
	- 스택 / 큐

	ㅁ 비선형 구조는 하나의 자료 뒤에 다수의 자료가 올 수 있는 형태
	- 트리
	- 그래프


*/

// 설명창

int main()
{
	std::vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.pop_back();


}