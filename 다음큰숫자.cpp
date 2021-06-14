#include <string>
#include <vector>
#include <iostream>

using namespace std;

int number(int n)
{
    int answer = 0;
    for (int i = 1; n > 0; i *= 10)
    {
        int a = n % 2;
        if (a == 1)
            answer++;
        n /= 2;
    }
    return answer;
}

int solution(int n) {
    int num = number(n);
    while (1)
    {
        n++;
        int count = number(n);
        if (num == count)
            break;
    }
    return n;
}

void main()
{
    cout<<solution(78);
    cout<<solution(15);
}