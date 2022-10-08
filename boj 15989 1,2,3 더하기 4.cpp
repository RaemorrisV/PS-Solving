#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[4][10001];
int t;
int n;
int ans = 0;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		dp[1][1] = 1;
		dp[1][2] = 2;
		dp[1][3] = 3;
		dp[2][2] = 1;
		dp[3][3] = 1;
		for (int k = 4; k <= n; k++)
		{
			dp[2][k] = dp[2][k - 2] + dp[3][k - 2]; //1
			dp[3][k] = dp[3][k - 3];//0
			dp[1][k] = dp[1][k - 1] + dp[2][k] + dp[3][k];
		}

		cout << dp[1][n] << endl;
		fill(&dp[0][0], &dp[3][n + 1], 0);
	}
	return 0;
}