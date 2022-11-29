#include <iostream>
#include <algorithm>

using namespace std;

int t, w, tree;
int dp[1001][3][31];
int MAX = 0;
int loca[1001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
    {
        cin >> tree;
        loca[i] = tree;
    }
    for (int i = 1; i <= t; i++)
    {
        for (int k = 0; k <= w; k++)
        {
            if (k == 0)
            {
                if (loca[i] == 1)
                {
                    dp[i][1][0] = dp[i - 1][1][0] + 1;
                }
                else
                {
                    dp[i][1][0] = dp[i - 1][1][0];
                }
            }
            else
            {
                if (k <= i)
                {
                    if (loca[i] == 1) // 1일경우
                    {
                        dp[i][1][k] = max(dp[i - 1][1][k] + 1, dp[i - 1][(1 % 2 + 1)][k - 1] + 1);
                        dp[i][2][k] = max(dp[i - 1][2][k], dp[i - 1][1][k - 1]);
                        MAX = max(dp[i][1][k], MAX);
                        MAX = max(dp[i][2][k], MAX);
                    }
                    else if (loca[i] != 1) // 2일경우
                    {
                        dp[i][1][k] = max(dp[i - 1][1][k], dp[i - 1][(1 % 2 + 1)][k - 1]);
                        dp[i][2][k] = max(dp[i][(2 % 2 + 1)][k - 1] + 1, dp[i - 1][2][k] + 1);
                        MAX = max(dp[i][2][k], MAX);
                        MAX = max(dp[i][1][k], MAX);
                    }
                }
            }
        }
    }
    cout << MAX << '\n';
    return 0;
}