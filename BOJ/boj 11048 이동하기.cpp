#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int maze[1001][1001];
int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> maze[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max({dp[i - 1][j - 1] + maze[i][j], dp[i - 1][j] + maze[i][j], dp[i][j - 1] + maze[i][j]});
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}