#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int load = weight;
    int n = 0;
    int truck = 0;
    vector<int> v;
    queue<int> q;

    while (truck < truck_weights.size())
    {
        if (n < truck_weights.size() && load - truck_weights[n] >= 0)
        {
            q.push(truck_weights[n]);
            load -= q.back();
            v.push_back(1);
            n++;
        }

        if (v[truck] == bridge_length)
        {
            load += q.front();
            q.pop();
            truck++;
        }

        for (int i = 0; i < v.size(); i++)
            v[i]++;
        time++;
    }
    return time + 1;
}

int main()
{
    solution(2, 10, { 7,4,5,6 });
}