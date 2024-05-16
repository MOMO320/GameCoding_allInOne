// fuctionBasic.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
    ㅁ 함수 기초

    [타입] [이름]

    void  = 반환값이 없는 함수


    ㅁ 스택 
    잠시만 사용 하는 공간

*/

#include <iostream>
using namespace std;

int AddReturn(int a, int b);
float AddReturn(float a, float b);


void TestFunction()
{
    std::cout << "Test" << endl;
}

void TestFunction(int a)
{
    cout << a << endl;
}

void TestFunction(float b)
{
    cout << b << endl;
}

void Add(int a, int b)
{
    cout << a + b << endl;
}

// 전역변수
/*
    전역변수의 단점
     - 어디서 문제가 발생 했는지 찾기가 쉽지 않다.(지양해야 한다.)

*/
int hp = 100;

int main0()
{

    TestFunction();
    TestFunction(133);

    TestFunction(3.14f);

    TestFunction(hp);

    Add(3, 5);
    hp = AddReturn(10, 100);

    return 0;
}


int AddReturn(int a, int b)
{
    cout << a + b << endl;
    // 지역 변수
    int sum = (a + b);

    return sum; // return 은 함수를 바로 빠져나가게 할 수 있다.
}

float AddReturn(float a, float b)
{
    cout << a + b << endl;

    float sum = a + b;

    return sum;
}
