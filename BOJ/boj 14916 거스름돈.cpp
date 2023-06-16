#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
int n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	fill(dp + 1, dp + n + 1, 100001);
	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;
	for (int i = 6; i <= n; i++)
	{
		if (dp[i - 2] != 0)
		{
			dp[i] = min(dp[i - 2] + 1, dp[i]);
		}
		if (dp[i - 5] != 0)
		{
			dp[i] = min(dp[i], dp[i - 5] + 1);
		}
	}
	if (dp[n] == 100001)
	{
		cout << -1 << '\n';
	}
	else cout << dp[n] << "\n";
	return 0;
}