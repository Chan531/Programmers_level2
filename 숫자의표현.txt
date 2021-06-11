#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = n;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        num -= i;
        if (num == 0)
        {
            answer++;
            num = n;
            i = count;
            count++;
        }
        else if (num < 0)
        {
            num = n;
            i = count;
            count++;
        }
    }
    return answer;
}