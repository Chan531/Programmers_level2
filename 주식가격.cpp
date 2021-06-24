#include <iostream>
#include <vector>
#include <deque>    

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> time(prices.size());
    deque<int> s;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (s.size() == 0)
        {
            s.push_back(i);
        }
        else if (prices[s.back()] > prices[i])
        {
            while (!s.empty())
            {
                s.pop_back();
                if (prices[s.back()] <= prices[i])
                    break;
            }
            s.push_back(i);
        }
        else if (prices[s.back()] <= prices[i])
        {
            s.push_back(i);
        }
        s.push_back(-1);
        while (1)
        {
            if (s.front() == -1)
            {
                s.pop_front();
                break;
            }
            time[s.front()]++;
            s.push_back(s.front());
            s.pop_front();
        }
    }
    return time;
}

int main()
{
    vector<int> a = solution({ 1,2,3,2,3,1 });
    for (auto i : a)
        cout << i;
}