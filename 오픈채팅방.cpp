#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> id;
    vector<string> act;
    map<string, string> m;
    for (int i = 0; i < record.size(); i++)
    {
        int j = 0;
        istringstream ss(record[i]);
        string str;
        while (getline(ss, str, ' '))
        {
            if (j == 0)
                act.push_back(str);
            else if (j == 1)
            {
                id.push_back(str);
            }
            else if (j == 2)
            {
                if (m.find(id[i]) == m.end())
                {
                    m.insert(pair<string, string>(id[i], str));
                }
                else
                    m[id[i]] = str;
            }
            j++;
        }
    }

    for (int i = 0; i < act.size(); i++)
    {   
        string s = m[id[i]]; 
        if (act[i] == "Change")
        {
        }
        else if (act[i] == "Enter")
        {
            s += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(s);
        }
        else if (act[i] == "Leave")
        {
            s += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(s);
        }
    }
    return answer;
}

int main()
{
    solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
}