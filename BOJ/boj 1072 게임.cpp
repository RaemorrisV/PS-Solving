#include <iostream>
#include <cmath>
using namespace std;

long long x, y;
int per;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> x >> y;
    per = (y * 100 / x);
    if (per >= 99)
    {
        cout << "-1" << '\n';
    }
    else
    {
        int s = 0;
        int e = 1000000000;
        int ans = 0;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int p = ((y + mid) * 100 / (x + mid));
            if (per >= p)
            {
                s = mid + 1;
            }
            else
            {
                ans = mid;
                e = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
