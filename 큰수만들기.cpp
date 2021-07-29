#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string s = "";
    int size = number.size() - k;
    string max;
    int index;
    while (s.size() != size)
    {
        max = *max_element(number.begin(), number.begin() + k + 1);
        index = max_element(number.begin(), number.begin() + k + 1) - number.begin();
        s += max;
        number.erase(0, index + 1);
        k -= index;
    }
    return s;
}

int main(void)
{
    cout << solution("1231234", 3);
}