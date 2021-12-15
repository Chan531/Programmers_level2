#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) 
{
    int answer = 0, dis, pos, ndis, npos, start, end;
    vector<int> minroad(N + 1, 500001);
    vector<vector<int>> roadlength(N + 1, vector<int>(N + 1, 10001)), roads(N + 1), check(N + 1, vector<int>(N + 1));
    priority_queue<pair<int, int>> pq;
    minroad[1] = 0;
    for (int i = 0; i < road.size(); i++)
    {
        start = road[i][0];
        end = road[i][1];
        dis = road[i][2];
        roadlength[start][end] = min(roadlength[start][end], dis);
        roadlength[end][start] = min(roadlength[end][start], dis);
        if (!check[start][end])
        {
            roads[start].push_back(end);
            roads[end].push_back(start);
            check[start][end] = 1;
            check[end][start] = 1;
        }
    }
    for (int i = 0; i < roads[1].size(); i++)
    {
        pos = roads[1][i];
        dis = roadlength[1][pos];
        pq.push(make_pair(dis, pos));
    }

    while (!pq.empty()) 
    {
        dis = pq.top().first;
        pos = pq.top().second;
        pq.pop();

        if (dis > K || dis > minroad[pos])
            continue;

        minroad[pos] = dis;

        for (int i = 0; i < roads[pos].size(); i++)
        {
            npos = roads[pos][i];
            ndis = dis + roadlength[pos][npos];
            if (ndis <= K && ndis < minroad[npos])
                pq.push(make_pair(ndis, npos));
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (minroad[i] <= K)
            answer++;
    }
    return answer;
}