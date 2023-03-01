#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int dp[50001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j <= sqrt(i); j++)
		{
			int ex = pow(j, 2);
			dp[i] = min(dp[i], dp[i - ex] + 1);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}