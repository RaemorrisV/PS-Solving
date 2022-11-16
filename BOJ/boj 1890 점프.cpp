#include <iostream>

using namespace std;

int n;
int board[101][101];
long long dp[101][101];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] != 0 && board[i][j] != 0)
            {
                if (i + board[i][j] <= n) //아래 방향으로 가는 것
                {
                    dp[i + board[i][j]][j] += dp[i][j];
                }
                if (j + board[i][j] <= n) //오른쪽 방향으로 가는 것
                {
                    dp[i][j + board[i][j]] += dp[i][j];
                }
            }
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}