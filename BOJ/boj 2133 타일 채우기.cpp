#include <iostream>

using namespace std;

int n;
int dp[31];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] += 3 * dp[i - 2];
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += 2 * dp[i - j];
        }
    }
    cout << dp[n] << '\n';
    return 0;
}