#include <iostream>
#include <cstring>

using namespace std;

int n;
long long dp[31][31]; //hw
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n;
		if (n == 0)break;
		for (int i = 1; i <= n; i++)
		{
			dp[0][i] = 1;
		}
		for (int i = 1; i <= n; i++) //h
		{
			for (int j = 0; j <= n; j++) //w
			{
				if (j >= i)dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[n][n] << '\n';
	}
	return 0;
}