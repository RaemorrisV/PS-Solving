#include <iostream>
#include <vector>

using namespace std;
struct year
{
    int e;
    int s;
    int m;
};
year joonkyu;
int E, S, M;
int ans = 1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    joonkyu.e = 1;
    joonkyu.s = 1;
    joonkyu.m = 1;
    cin >> E >> S >> M;
    while (1)
    {
        if (joonkyu.e == E && joonkyu.s == S && joonkyu.m == M)
        {
            cout << ans << "\n";
            break;
        }
        joonkyu.e++;
        joonkyu.s++;
        joonkyu.m++;
        if (joonkyu.e > 15)
        {
            joonkyu.e = 1;
        }
        if (joonkyu.s > 28)
        {
            joonkyu.s = 1;
        }
        if (joonkyu.m > 19)
        {
            joonkyu.m = 1;
        }
        ans++;
    }
    return 0;
}