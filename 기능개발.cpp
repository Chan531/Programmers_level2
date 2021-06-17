#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> day;
    vector<int> answer;

    for (int i = 0; i < speeds.size(); i++)
    {
        int period = 0;
        int k = progresses[i];
        while (k < 100)
        {
            k += speeds[i];
            period++;
        }
        day.push_back(period);
    }

    int a = day[0];
    int time = 1;

    for (int i = 1; i < day.size(); i++)
    {
        if (a < day[i])
        {
            answer.push_back(time);
            a = day[i];
            time = 1;
        }
        else
        {
            time++;
        }
        if (i == day.size() - 1)
            answer.push_back(time);
    }
    return answer;
}

int main()
{
    solution({ 93,30,55 }, { 1,30,5 });
}