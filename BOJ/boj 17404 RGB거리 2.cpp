#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int cost[1001][4];
int dp[1001][4];
int MIN = 10000000;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> cost[i][j];
        }
    }
    dp[1][1] = cost[1][1];
    dp[2][2] = dp[1][1] + cost[2][2];
    dp[2][3] = dp[1][1] + cost[2][3];
    for (int i = 3; i <= n; i++)
    {
        if (i == 3)
        {
            dp[i][3] = dp[i - 1][2] + cost[i][3];
            dp[i][2] = dp[i - 1][3] + cost[i][2];
            dp[i][1] = min(dp[i - 1][2] + cost[i][1], dp[i - 1][3] + cost[i][1]);
        }
        else if (i != n)
        {
            dp[i][3] = min(dp[i - 1][2] + cost[i][3], dp[i - 1][1] + cost[i][3]);
            dp[i][2] = min(dp[i - 1][3] + cost[i][2], dp[i - 1][1] + cost[i][2]);
            dp[i][1] = min(dp[i - 1][2] + cost[i][1], dp[i - 1][3] + cost[i][1]);
        }
        else if (i == n)
        {
            dp[i][3] = min(dp[i - 1][2] + cost[i][3], dp[i - 1][1] + cost[i][3]);
            dp[i][2] = min(dp[i - 1][3] + cost[i][2], dp[i - 1][1] + cost[i][2]);
        }
    }
    MIN = min({MIN, dp[n][2], dp[n][3]});
    memset(dp, 0, sizeof(dp));
    dp[1][2] = cost[1][2];
    dp[2][1] = dp[1][2] + cost[2][1];
    dp[2][3] = dp[1][2] + cost[2][3];
    for (int i = 3; i <= n; i++)
    {
        if (i == 3)
        {
            dp[i][3] = dp[i - 1][1] + cost[i][3];
            dp[i][2] = min(dp[i - 1][3] + cost[i][2], dp[i - 1][1] + cost[i][2]);
            dp[i][1] = dp[i - 1][3] + cost[i][1];
        }
        else if (i != n)
        {
            dp[i][3] = min(dp[i - 1][2] + cost[i][3], dp[i - 1][1] + cost[i][3]);
            dp[i][2] = min(dp[i - 1][3] + cost[i][2], dp[i - 1][1] + cost[i][2]);
            dp[i][1] = min(dp[i - 1][2] + cost[i][1], dp[i - 1][3] + cost[i][1]);
        }
        else
        {
            dp[i][3] = min(dp[i - 1][2] + cost[i][3], dp[i - 1][1] + cost[i][3]);
            dp[i][1] = min(dp[i - 1][2] + cost[i][1], dp[i - 1][3] + cost[i][1]);
        }
    }
    MIN = min({MIN, dp[n][1], dp[n][3]});
    memset(dp, 0, sizeof(dp));
    dp[1][3] = cost[1][3];
    dp[2][1] = dp[1][3] + cost[2][1];
    dp[2][2] = dp[1][3] + cost[2][2];
    for (int i = 3; i <= n; i++)
    {
        if (i == 3)
        {
            dp[i][3] = min(dp[i - 1][2] + cost[i][3], dp[i - 1][1] + cost[i][3]);
            dp[i][2] = dp[i - 1][1] + cost[i][2];
            dp[i][1] = dp[i - 1][2] + cost[i][1];
        }
        else if (i != n)
        {
            dp[i][3] = min(dp[i - 1][2] + cost[i][3], dp[i - 1][1] + cost[i][3]);
            dp[i][2] = min(dp[i - 1][3] + cost[i][2], dp[i - 1][1] + cost[i][2]);
            dp[i][1] = min(dp[i - 1][2] + cost[i][1], dp[i - 1][3] + cost[i][1]);
        }
        else
        {
            dp[i][2] = min(dp[i - 1][3] + cost[i][2], dp[i - 1][1] + cost[i][2]);
            dp[i][1] = min(dp[i - 1][2] + cost[i][1], dp[i - 1][3] + cost[i][1]);
        }
    }
    MIN = min({MIN, dp[n][1], dp[n][2]});
    cout << MIN << '\n';
    return 0;
}