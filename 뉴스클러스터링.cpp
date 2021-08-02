#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    vector<string> o, t, in, un;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    for (int i = 0; i < str1.size() - 1; i++)
    {
        string s = "";
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            s += str1[i];
            s += str1[i + 1];
            o.push_back(s);
        }
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        string s = "";
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            s += str2[i];
            s += str2[i + 1];
            t.push_back(s);
        }
    }
    if (o.size() == 0 && t.size() == 0)
        return 65536;
    sort(o.begin(), o.end());
    sort(t.begin(), t.end());
    set_union(o.begin(), o.end(), t.begin(), t.end(), back_inserter(un));
    set_intersection(o.begin(), o.end(), t.begin(), t.end(), back_inserter(in));
    double j = double(in.size()) / double(un.size());
    return floor(j * 65536);
}

int main(void)
{
    solution("handshake", "shake hands");
}