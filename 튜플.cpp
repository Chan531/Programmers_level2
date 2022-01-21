#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int idx = 2;
    vector<vector<int>> arr;
    vector<int> answer, num, arrnum(100001);
    string n = "";
    while (idx < s.length())
    {
        if (s[idx] == '}')
        {
            arr.push_back(num);
            num.clear();
            idx += 2;
        }
        else if (s[idx] == '{' || s[idx] == ',')
            idx++;
        else
        {
            while (isdigit(s[idx]))
                n += s[idx++];
            num.push_back(stoi(n));
            n = "";
        }
    }
    while (answer.size() != arr.size())
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (answer.size() + 1 == arr[i].size())
            {
                for (int j = 0; j < arr[i].size(); j++)
                {
                    if (!arrnum[arr[i][j]])
                    {
                        answer.push_back(arr[i][j]);
                        arrnum[arr[i][j]] = 1;
                    }
                }
            }
        }
    }
    return answer;
}