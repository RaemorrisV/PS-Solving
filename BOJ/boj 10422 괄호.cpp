#include <iostream>

using namespace std;
int t, l;
long long dp[5001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= 5000; i += 2)
    {
        for (int j = 2; j <= i; j += 2)
        {
            dp[i] += (dp[j - 2] * dp[i - j]) % 1000000007;
        }
        dp[i] %= 1000000007;
    }
    for (int i = 0; i < t; i++)
    {
        cin >> l;
        cout << dp[l] << '\n';
    }
    return 0;
}