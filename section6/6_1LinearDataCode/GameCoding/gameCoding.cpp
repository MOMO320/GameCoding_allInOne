#include <iostream>
using namespace std;

// enum class 
// : 범위 문제 해결, 일반적인 enum의 경우 안에 값(명칭)이 다른곳과 겹치면
// 문제가 발생 하지만, enum class를 이용하면 안에 값(명칭)이 같아도 문제가 없음

//enum ScreenColor
//{
//	SC_RED,
//	SC_GREEN
//};
//
//enum LightColor
//{
//	LC_RED,
//	LC_GREEN
//};

enum class ScreenColor
{
	RED,
	GREEN
};

enum class LightColor
{
	RED,
	GREEN
};

int main()
{
	int a = static_cast<int>(ScreenColor::RED);
}