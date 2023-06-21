#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>arr;
int c, n;
int dp[5000];
int MAX = 0;
int ans = 10000000000;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> c >> n;
	fill(dp + 1, dp + c + 101, 1000000000);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });//홍보비용과 얻는 고객의수
	}
	for (int i = 0; i <= c; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - arr[j].second >= 0)
			{
				dp[i] = min(dp[i], dp[i - arr[j].second] + arr[j].first);
			}
			if (i + arr[j].second >= c)
			{
				dp[i + arr[j].second] = min(dp[i+arr[j].second], dp[i] + arr[j].first);
				MAX = max(i + arr[j].second, MAX);
			}
		}
	}
	for (int i = c; i <= MAX; i++)
	{
		ans = min(ans, dp[i]);
	}
	cout << ans << "\n";
	return 0;
}