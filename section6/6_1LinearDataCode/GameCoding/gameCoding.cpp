#include <iostream>
using namespace std;

// enum class 
// : ���� ���� �ذ�, �Ϲ����� enum�� ��� �ȿ� ��(��Ī)�� �ٸ����� ��ġ��
// ������ �߻� ������, enum class�� �̿��ϸ� �ȿ� ��(��Ī)�� ���Ƶ� ������ ����

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