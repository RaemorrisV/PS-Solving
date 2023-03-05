#include <iostream>

using namespace std;

int n, m, cir, r, c; // За ї­ 15
int dp[17][17];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> cir;
	if (cir == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1)dp[1][1] = 1;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	else
	{
		r = ((cir-1) / m) + 1;
		c = cir % m;
		if (c == 0)c = m;
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (i == 1 && j == 1)dp[1][1] = 1;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		for (int i = r; i <= n; i++)
		{
			for (int j = c; j <= m; j++)
			{
				if (i == r && j == c)continue;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
}