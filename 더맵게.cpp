#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int n, m, answer = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    while (pq.size() != 1)
    {
        n = pq.top();
        pq.pop();
        m = pq.top();
        pq.pop();
        pq.push(n + m * 2);
        if (pq.top() >= K)
            break;
        answer++;
    }
    if (pq.top() < K)
        return -1;
    else
        return answer;
}