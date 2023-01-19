#include <iostream>
#include <algorithm>

using namespace std;
//누적합 까지 해주면 좋을듯
int n, m;
int dp[1001][1001];
int arr[1001][1001];
int dp2[1001][1001]; //누적합

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string in;
		cin >> in;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = in[j - 1] - '0';
		}
	}
	//누적합 구하는 dp
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp2[i][j] = (arr[i][j] + dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1]);
		}
	}
	//본격 답구하는 dp
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 0) //0 일 경우에
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else //1일 경우에
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				for (int k = 1; k <= min(i, j); k++)
				{
					int size = dp2[i][j] - dp2[i - k][j] - dp2[i][j - k]+dp2[i-k][j-k];
					if (size == k * k)
					{
						dp[i][j] = max(dp[i][j], size);
					}
				}
			}
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
}