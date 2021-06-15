#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 1;
    int pre = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp = sum;
        sum = (sum % 1234567 + pre % 1234567) % 1234567;
        pre = tmp;
    }
    return sum;
}