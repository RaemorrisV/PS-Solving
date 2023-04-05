#include <iostream>
#define MOD 1000000003 
using namespace std;

int n, k, ans;
int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = i;
        if (i >= 4)
        {
            for (int j = 2; j <= k; j++)
            {
                dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}