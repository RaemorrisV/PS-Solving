#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long S;
long long s = 1;
long long e = 1000000;
bool simulation(long long num)
{
    long long a = num * (num + 1) / 2;
    if (a <= S)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> S;
    while (s + 1 < e)
    {
        long long mid = (s + e) / 2;
        if (simulation(mid))
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    cout << s << '\n';
    return 0;
}