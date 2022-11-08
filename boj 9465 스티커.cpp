#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
int dp[2][100000];
int sticker[2][100000];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        fill(&dp[0][0], &dp[1][n], 0);
        fill(&sticker[0][0], &sticker[1][n], 0);
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> sticker[j][k];
            }
        }
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];
        for (int j = 2; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[k][j] = max({dp[(k + 1) % 2][j - 1], dp[0][j - 2], dp[1][j - 2]}) + sticker[k][j];
            }
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    return 0;
}