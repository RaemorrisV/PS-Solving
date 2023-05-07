#include <iostream>
#define MOD 1000000000
using namespace std;

int n;
int dp[1000001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] += dp[i - 1];
		if (i % 2 == 0)
		{
			dp[i] += dp[i / 2];
			dp[i] %= MOD;
		}
		dp[i] %= MOD;
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << "\n";
	}
	*/
	cout << dp[n] << "\n";
	return 0;
}