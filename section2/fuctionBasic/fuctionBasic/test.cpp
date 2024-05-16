#include <iostream>
#include <string>
#include <vector>


using namespace std;

// ���� Ǭ ���_1(�׽�Ʈ ��� 3/2, 1����)
/*  
  - ���� ���̽�
    �Է°� ��	"18446744073709551615", "287346502836570928366"
    ��� ��	"305793246910280479981"
*/
string solution(string a, string b)
{
    int sum = 0;

    sum = atoi(a.c_str()) + atoi(b.c_str());

    string answer = to_string(sum);

    cout << answer << endl;
    return answer;
}

// ���� Ǭ ���_2 �߸���

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
        length() �Լ��� ���ڿ��� ���̸� ��ȯ�ϴ� ���� Ưȭ�Ǿ� ������, string Ŭ������ ������ �Դϴ�.
        �Ϲ����� �迭�̳� �ٸ� �����̳ʿ��� ���������� ������ �� �����ϴ�.
        ���� ���ڿ� ��ü�� string�� �ٷ�� ��쿡 �����ϰ� ��� �˴ϴ�.
    */ 

    int alen = a.length();  
    int blen = b.length();
    int carry = 0;
    string answer = "";

    // �� �� �� ū���ΰ� �߸��� ���ؼ� max �Լ� ���
    std::cout << "max Test : " << max(alen, blen) << endl;

    for (int i = 1; i <= max(alen, blen); i++)
    {
        // - '0'�� ���� ������ 0�� �ƽ�Ű �ڵ尪�� �� �����̴�.
        // a[alen - i]�� �ƽ�Ű �ڵ� ���� ������ ������ ������, 0�� ���Ƿν� ���� ���� ������ ó��
        int numa = (i > alen) ? 0 : a[alen - i] - '0'; 
        int numb = (i > blen) ? 0 : b[blen - i] - '0';
        int num = numa + numb + carry;

        if (num >= 10) carry = 1;
        else           carry = 0;

        char numc = num % 10 + '0';
        answer = numc + answer;
    }

    // for���� �� ���� carry�� ���� 1�̸� ���ڿ� �տ� 1�� ���̰� �ϱ� ���� ó��
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