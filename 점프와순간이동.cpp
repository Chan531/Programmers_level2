using namespace std;

int solution(int n)
{
    int battery = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
        {
            n--;
            battery++;
        }
    }
    return ++battery;
}