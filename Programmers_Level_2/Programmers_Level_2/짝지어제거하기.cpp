#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*int solution(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = -1;
        }
    }
    if (s.length() == 0)
        return 1;
    else
        return 0;
}*/

int solution(string s) 
{
    stack<char> a;
    for (int i = 0; i < s.length(); i++)
    {
        if (a.size() != 0 && a.top() == s[i])
        {
            a.pop();
            s.erase(i - 1, 2);
            i -= 2;
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