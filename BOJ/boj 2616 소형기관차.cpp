#include <iostream>
#include <algorithm>

using namespace std;

int n, len;
int arr[50001];
int sum[50001];
int dp[4][50001];
int ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum[i] += sum[i - 1] + arr[i];
	}
	cin >> len;
	//첫번째 작은 열차
	for (int i = 1; i <= n - 2 * len; i++)
	{
		dp[1][i] = max(sum[i] - sum[i - len], dp[1][i - 1]);
	}
	//두번째 작은 열차
	for (int i = 2 * len; i <= n - len; i++)
	{
		dp[2][i] = sum[i] - sum[i - len] + dp[1][i - len];
		dp[2][i] = max(dp[2][i], dp[2][i - 1]);
	}
	//세번째 여기서 정답을 찾으면 됨
	for (int i = 3 * len ; i <= n; i++)
	{
		dp[3][i] = sum[i] - sum[i - len] + dp[2][i - len];
		dp[3][i] = max(dp[3][i], dp[3][i - 1]);
	}
	cout << dp[3][n] << '\n';
	return 0;
}