#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	vector<int> v;
	string num = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 45)
		{
			i++;
			while (i != s.length() && s[i] != 32)
			{
				num += s[i];
				i++;
			}
			v.push_back((stoi(num)) * -1);
			num = "";
		}
		else
		{
			while (i != s.length() && s[i] != 32)
			{
				num += s[i];
				i++;
			}
			v.push_back(stoi(num));
			num = "";
		}
	}
	sort(v.begin(), v.end());
	num += to_string(v[0]);
	num += " ";
	num += to_string(v[v.size() - 1]);
	return num;
}

void main()
{
	solution("-7 45 23 -32 58 149 -9561 785153");
}