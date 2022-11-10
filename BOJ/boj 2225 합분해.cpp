#include <iostream>

using namespace std;

int n, k;
int dp[201][201];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        for (int j = 2; j <= k; j++)
        {
            for (int m = 0; m <= i; m++)
            {
                dp[i][j] = (dp[i][j] + dp[i - m][j - 1]) % 1000000000;
            }
        }
    }
    cout << dp[n][k] % 1000000000 << '\n';
    return 0;
}