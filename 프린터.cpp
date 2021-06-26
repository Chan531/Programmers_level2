#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push(pair<int, int>(priorities[i], i));
    }
    sort(priorities.begin(), priorities.end(), greater<>());
    int i = 0;
    int count = 1;
    while (1)
    {
        int a = priorities[i];
        while (q.front().first != a)
        {
            pair<int, int> p = make_pair(q.front().first, q.front().second);
            q.push(p);
            q.pop();
        }
        if (q.front().second == location)
            return count;
        else
        {
            q.pop();
            i++;
            count++;
        }
    }
}