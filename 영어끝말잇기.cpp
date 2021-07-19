#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    string s = words[0];
    m[s]++;
    int i = 1;
    while (i < words.size())
    {
        string t = words[i];
        m[t]++;
        if (s[s.length() - 1] != t[0] || m[t] == 2)
        {
            if ((i + 1) % n == 0)
                answer.push_back(n);
            else
                answer.push_back((i + 1) % n);
            answer.push_back(ceil(double(i + 1) / double(n)));
            break;
        }
        i++;
        s = t;
    }
    if (answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main(void)
{
    vector<int> v, w, x;
    v = solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });
    w = solution(5, { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" });
    x = solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });
    return 0;
}