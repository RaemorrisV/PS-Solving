#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][1001];
int dp[1001][1001];
int temp[1001][2];
int n, m;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}
	dp[1][1] = map[1][1];
	for (int i = 2; i <= m; i++)
	{
		dp[1][i] = dp[1][i - 1] + map[1][i];
	}
	for (int i = 2; i <= n; i++)
	{
		temp[1][0] = dp[i - 1][1] + map[i][1];
		temp[m][1] = dp[i - 1][m] + map[i][m];
		for (int j = 2; j <= m; j++)
		{
			temp[j][0] = max(temp[j - 1][0] + map[i][j], dp[i - 1][j] + map[i][j]);
		}
		for (int j = m - 1; j >= 1; j--)
		{
			temp[j][1] = max(dp[i - 1][j] + map[i][j], temp[j + 1][1] + map[i][j]);
		}
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(temp[j][1], temp[j][0]);
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}