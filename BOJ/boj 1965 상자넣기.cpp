#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 1;
int box_size[1001];
int dp[1001]; //i번째 박스에 들어 갈 수있는 최대
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> box_size[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++)
		{
			if (box_size[j] < box_size[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}