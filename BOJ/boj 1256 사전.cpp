#include <iostream>

using namespace std;

int n, m, k;
int dp[101][101];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	//init
	for (int i = 1; i <= 100; i++)
	{
		dp[i][0] = 1;
		dp[0][i] = 1;
	}
	//dp
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] > 1000000000)dp[i][j] = 1000000000;
		}
	}
	//print
	if (k > dp[n][m])
	{
		cout << "-1" << '\n';
	}
	else
	{
		int a = n;
		int b = m;
		for (int i = 1; i <= n + m; i++)
		{
			if (a == 0)
			{
				cout << "z";
				b--;
				continue;
			}
			else if (b == 0)
			{
				cout << "a";
				a--;
				continue;
			}
			if (dp[a - 1][b] < k)
			{
				cout << "z";
				k -= dp[a-1][b];
				b--;
			}
			else
			{
				cout << "a";
				a--;
			}
		}
	}
	return 0;
}