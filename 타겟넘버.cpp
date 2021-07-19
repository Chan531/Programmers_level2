#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int num = 0;
    deque<pair<int, int>> q;
    pair<int, int> p;
    q.push_back(make_pair(numbers[0], 0));
    q.push_back(make_pair(numbers[0] * -1, 0));
    while (!q.empty())
    {
        p = q.front();
        q.pop_front();
        int n = p.second + 1;
        if (n == numbers.size())
        {
            if (p.first == target)
                num++;
        }
        else
        {
            q.push_back(make_pair(p.first + numbers[n], n));
            q.push_back(make_pair(p.first - numbers[n], n));
        }
    }
    return num;
}

int main(void)
{
    int a = solution({ 2,3,5,7,9 }, 26);
    cout << a;
}