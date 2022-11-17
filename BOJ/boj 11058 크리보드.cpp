#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[101];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    for (int i = 7; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 3; j < 6; j++)
        {
            dp[i] = max(dp[i], dp[i - j] * (j - 1));   //
        }
    }
    cout << dp[n] << '\n';
    return 0;
}