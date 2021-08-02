#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size() - 1;
    int weight, boat = 0;
    while (start < end)
    {
        weight = people[start] + people[end];
        if (limit >= weight)
        {
            boat++;
            start++;
            end--;
            if (start == end)
                boat++;
        }
        else
        {
            boat++;
            end--;
            if (start == end)
                boat++;
        }
    }
    return boat;
}

int main(void)
{
    solution({ 70,80,50,50 }, 100);
}