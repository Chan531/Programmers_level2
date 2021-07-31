#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    if (s.length() == 1)
        return 1;
    vector<int> v;
    int count;
    for (int i = 1; i <= s.size() / 2; i++)
    {
        int length = s.length();
        count = 1;
        for (int j = 0; j < s.size() - i; j += i)
        {
            count = 1;
            while (s.substr(j, i) == s.substr(j + i, i))
            {
                count++;
                length -= i;
                j += i;
            }
            if (count >= 2)
                length++;
            if (count >= 10)
                length++;
            if (count >= 100)
                length++;
            if (count >= 1000)
                length++;
        }
        v.push_back(length);
    }
    return *min_element(v.begin(), v.end());
}