#include <iostream>
#include <string>
#include <vector>


using namespace std;

// 내가 푼 방법_1(테스트 결과 3/2, 1실패)
/*  
  - 실패 케이스
    입력값 〉	"18446744073709551615", "287346502836570928366"
    기댓값 〉	"305793246910280479981"
*/
string solution(string a, string b)
{
    int sum = 0;

    sum = atoi(a.c_str()) + atoi(b.c_str());

    string answer = to_string(sum);

    cout << answer << endl;
    return answer;
}

// 내가 푼 방법_2 잘못함

string solution2(string a, string b) {

    std::vector<char> aVec;
    std::vector<char> bVec;

    cout << "aVec Size : " << aVec.size() << endl;

    int aSize = a.size();
    cout << aSize << endl;

    aVec.resize(aSize);
    bVec.resize(b.size());

    cout << "aVec Size : " << aVec.size() << endl;

    for (int i = 0; i < a.size(); i++)
    {
    
    }

    string answer = "";
    return answer;
}

string answerSolution(string a, string b)
{
    /*
        length() 함수는 문자열의 길이를 반환하는 데에 특화되어 있으며, string 클래스에 종속적 입니다.
        일반적인 배열이나 다른 컨테이너에는 직접적으로 적용할 수 없습니다.
        따라서 문자열 객체인 string을 다루는 경우에 유용하게 사용 됩니다.
    */ 

    int alen = a.length();  
    int blen = b.length();
    int carry = 0;
    string answer = "";

    // 둘 중 더 큰값인걸 추르기 위해서 max 함수 사용
    std::cout << "max Test : " << max(alen, blen) << endl;

    for (int i = 1; i <= max(alen, blen); i++)
    {
        // - '0'을 해준 이유는 0의 아스키 코드값을 뺀 숫자이다.
        // a[alen - i]가 아스키 코드 숫자 값으로 나오기 때문에, 0을 빼므로써 정수 값이 나오게 처리
        int numa = (i > alen) ? 0 : a[alen - i] - '0'; 
        int numb = (i > blen) ? 0 : b[blen - i] - '0';
        int num = numa + numb + carry;

        if (num >= 10) carry = 1;
        else           carry = 0;

        char numc = num % 10 + '0';
        answer = numc + answer;
    }

    // for문이 다 돌고 carry의 값이 1이면 문자열 앞에 1을 붙이게 하기 위해 처리
    if (carry) answer = "1" + answer;

    cout << answer << endl;

    return answer;

}


int main()
{
	//solution("10", "30");
    //solution2("100", "3");

    answerSolution("18446744073709551615", "287346502836570928366");

  //  answerSolution("351", "482");


    char test = '0';
    int i = (int)test;

    //cout << i << endl;

	return 0;
}