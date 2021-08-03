#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string s = "";
    int count;
    while (n > 0)
    {
        count = 0;
        if (n % 3 == 0)
        {
            s += '4';
            count++;
            n /= 3;
            n--;
        }
        else
        {
            s += to_string(n % 3);
            n /= 3;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}