#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
bool check[8];

void backtrack(int cnt, int dsize, int k, vector<vector<int>>& dungeons)
{
    for (int i = 0; i < dsize; i++)
    {
        if (check[i])
            continue;

        if (k < dungeons[i][0] || k < dungeons[i][1])
            continue;

        check[i] = 1;
        backtrack(cnt + 1, dsize, k - dungeons[i][1], dungeons);
        check[i] = 0;
    }

    ans = max(ans, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    int dsize = dungeons.size();

    for (int i = 0; i < dsize; i++)
    {
        if (k >= dungeons[i][0] && k >= dungeons[i][1])
        {
            check[i] = 1;
            backtrack(1, dsize, k - dungeons[i][1], dungeons);
            check[i] = 0;
        }
    }

    return ans;
}