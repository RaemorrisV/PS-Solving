#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

double dp[10001];
double arr[10001];
int n;
double ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] * arr[i], arr[i]);
		ans = max(dp[i], ans);
	}
	cout << fixed;
	cout.precision(3);
	cout << ans << '\n';
	return 0;
}