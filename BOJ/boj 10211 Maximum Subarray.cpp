#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n;
int dp[1001];
int arr[1001];
int ans;
void init()
{
	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));
	ans = -1000000000;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		init();
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			dp[i] = max(arr[i], dp[i - 1] + arr[i]);
			ans = max(dp[i], ans);
		}
		cout << ans << '\n';
	}
	return 0;
}