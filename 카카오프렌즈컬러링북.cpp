#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };  // 방향

int bfs(int y, int x, int num, vector<vector<int>>& visited, vector<vector<int>>& picture, int m, int n)
{
    int cnt = 0;
    queue<p> q;
    q.push({ y, x });
    visited[y][x] = 1;

    while (!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        cnt++;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nexty = cury + dir[i][0];
            int nextx = curx + dir[i][1];

            if (nexty >= m || nexty < 0 || nextx >= n || nextx < 0 || visited[nexty][nextx] || picture[nexty][nextx] != num)
                continue;

            visited[nexty][nextx] = 1;
            q.push({ nexty, nextx });
        }
    }

    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    vector<vector<int>> visited(m, vector<int>(n));      // 방문 여부 확인
    map<int, int> check;           // 원소 확인

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] && !visited[i][j])
            {
                answer[1] = max(answer[1], bfs(i, j, picture[i][j], visited, picture, m, n));
                answer[0]++;

                if (!check[picture[i][j]])
                    check[picture[i][j]] = 1;
            }
        }
    }

    return answer;
}