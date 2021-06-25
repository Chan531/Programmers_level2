#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int size = citations.size();
    int h = 0;
    sort(citations.begin(), citations.end());
    while (1)
    {
        int count = 0;
        for (auto i : citations)
        {
            if (i >= h)
            {
                count++;
            }
        }
        if (count >= h && size - count <= h)
            h++;
        else
            return h--;
    }
}