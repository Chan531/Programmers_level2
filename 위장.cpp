#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map <string, int> m;
    map<string, int>::iterator it;
    vector<int> v;

    for (int i = 0; i < clothes.size(); i++)
        m[clothes[i][1]]++;

    for (it = m.begin(); it != m.end(); it++)
        v.push_back(it->second + 1);

    answer += accumulate(v.begin(), v.end(), 1, multiplies<int>());
    return --answer;
}