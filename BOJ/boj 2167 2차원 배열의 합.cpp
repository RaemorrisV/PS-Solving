#include <iostream>

using namespace std;

int dp[301][301];
int arr[301][301];
int n, m, k;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int s, e, s1, e1;
        cin >> s >> e >> s1 >> e1;
        cout << dp[s1][e1] - dp[s - 1][e1] - dp[s1][e - 1] + dp[s - 1][e - 1] << '\n';
    }
    return 0;
}