#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int hp[3];
int dp[61][61][61];
int dfs(int s, int c, int v)
{
    if (s == 0 && c == 0 && v == 0)
    {
        return 0;
    }
    if (dp[s][c][v] != -1)return dp[s][c][v];
    dp[s][c][v] = 1000000000;
    dp[s][c][v] = min(dp[s][c][v], dfs(max(0, s - 9), max(0, c - 3), max(0, v - 1)) + 1);
    dp[s][c][v] = min(dp[s][c][v], dfs(max(0, s - 9), max(0, c - 1), max(0, v - 3)) + 1);
    dp[s][c][v] = min(dp[s][c][v], dfs(max(0, s - 3), max(0, c - 9), max(0, v - 1)) + 1);
    dp[s][c][v] = min(dp[s][c][v], dfs(max(0, s - 3), max(0, c - 1), max(0, v - 9)) + 1);
    dp[s][c][v] = min(dp[s][c][v], dfs(max(0, s - 1), max(0, c - 9), max(0, v - 3)) + 1);
    dp[s][c][v] = min(dp[s][c][v], dfs(max(0, s - 1), max(0, c - 3), max(0, v - 9)) + 1);
    return dp[s][c][v];
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> hp[i];
    }
    cout << dfs(hp[0], hp[1], hp[2]) << '\n';
    return 0;
}
