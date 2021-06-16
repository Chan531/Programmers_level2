#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<char> a;
	for (auto i : s)
	{
		if (i == '(')
			a.push(i);
		else
		{
			if (a.size() != 0)
			{
				a.pop();
			}
			else
				return false;
		}
	}
	if (a.size() != 0)
		return false;
	else
		return true;
}

void main()
{
	solution("()()");
}