#include <iostream>
#include <cmath>
using namespace std;

unsigned long long n;
long long s = 0;
long long e;
long long ans = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    e = pow(2, 32) - 1; 
    while (s <= e)
    {
        unsigned long long mid = (s + e) / 2;
        if (mid * mid >= n)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}