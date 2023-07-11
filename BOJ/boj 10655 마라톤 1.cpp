#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>>checkPoint;
int n;
int dp[100000];
int ans = 500000000;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		checkPoint.push_back({ x,y });
	}
	for (int i = 0; i < n - 1; i++)
	{
		int x1 = checkPoint[i].first;
		int y1 = checkPoint[i].second;
		int x2 = checkPoint[i + 1].first;
		int y2 = checkPoint[i + 1].second;
		dp[i + 1] += (abs(x1 - x2) + abs(y1 - y2)) + dp[i];
	}
	for (int i = 0; i < n - 2; i++)
	{
		int x1 = checkPoint[i].first;
		int y1 = checkPoint[i].second;
		int x2 = checkPoint[i + 2].first;
		int y2 = checkPoint[i + 2].second;
		ans = min((dp[n - 1] - dp[i + 2]) + abs(x1 - x2) + abs(y1 - y2) + dp[i], ans);
	}
	cout << ans << '\n';
	return 0;
}