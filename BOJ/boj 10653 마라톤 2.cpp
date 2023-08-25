#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, k, ans = 2000000000;
vector<pair<int, int>>checkPoint(1001);
int dp[501][501];
int manhattan(pair<int, int>a, pair<int, int>b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void init()
{
	fill(&dp[0][0], &dp[500][501], 2000000000);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	init();
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		checkPoint[i] = { x,y };
		if (i > 1)dp[0][i] = dp[0][i - 1] + manhattan(checkPoint[i], checkPoint[i - 1]);
	}
	for (int i = 1; i <= k; i++)
	{
		dp[i][i + 2] = manhattan(checkPoint[1], checkPoint[i + 2]);
		for (int j = i + 3; j <= n; j++)
		{
			for (int z = 0; z <= i; z++)
			{
				dp[i][j] = min(dp[i-z][j-z-1]+manhattan(checkPoint[j],checkPoint[j-z-1]), dp[i][j]);
			}
		}
	}
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dp[i][n]);
	}
	cout << ans << '\n';
	return 0;
}