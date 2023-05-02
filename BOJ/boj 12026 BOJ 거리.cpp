#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001];
string block;
int n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> block;
	fill(dp, dp + 1001, 2000000000);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (block[i] == 'B')
		{
			for (int j = 0; j < i; j++)
			{
				if (block[j] == 'J')dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
		}
		else if (block[i] == 'O')
		{
			for (int j = 0; j < i; j++)
			{
				if (block[j] == 'B')dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
		}
		else if (block[i] == 'J')
		{
			for (int j = 0; j < i; j++)
			{
				if (block[j] == 'O')dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
		}
	}
	if (dp[n - 1] == 2000000000)
	{
		cout << -1 << '\n';
	}
	else cout << dp[n - 1] << '\n';
	return 0;
}