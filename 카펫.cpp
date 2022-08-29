#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    vector<int> answer;
    int sum = brown + yellow;

    for (int i = sum - 3; i >= 3; i--)
    {
        if (sum % i)
            continue;

        int j = sum / i;

        if (brown == 2 * (i + j) - 4)
        {
            answer.push_back(i);
            answer.push_back(j);
            break;
        }
    }

    return answer;
}