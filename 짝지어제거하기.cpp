#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> a;
    a.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (a.size() != 0 && a.top() == s[i])
        {
            a.pop();
        }
        else
        {
            a.push(s[i]);
        }        
    }
    if (a.size() == 0)
        return 1;
    else
        return 0;
}

void main()
{
    cout << solution("baabaa");
    cout << solution("cdcd");
}