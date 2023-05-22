#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int graph[100000][3];
int dp[100000][3];
int n, tc;
void init()
{
	memset(graph, 0, sizeof(graph));
	memset(dp, 0, sizeof(dp));
	tc++;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1)
	{
		cin >> n;
		if (n == 0)break;
		init();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> graph[i][j];
				dp[i][j] = 1000000;
			}
		}
		//dp 초기화 부터 시작
		for (int i = 0; i < 3; i++)
		{
			dp[0][i] = graph[0][i];
		}
		dp[1][1] = graph[0][1] + graph[0][2] + graph[1][1];
		dp[1][2] = graph[0][1] + graph[0][2] + graph[1][2];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == 0 && i != 0)
				{
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + graph[i][j + 1]);
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + graph[i + 1][j]);
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + graph[i + 1][j + 1]);
				}
				else if (j == 1)
				{
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + graph[i][j + 1]);
					dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + graph[i + 1][j - 1]);
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + graph[i + 1][j]);
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + graph[i + 1][j + 1]);
				}
				else if (j == 2 && i!=0)
				{
					dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + graph[i + 1][j - 1]);
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + graph[i + 1][j]);
				}
			}
		}
		for (int j = 0; j < 2; j++)
		{
			dp[n - 1][j + 1] = min(dp[n - 1][j + 1], dp[n - 1][j] + graph[n - 1][j + 1]);
		}
		//k. n
		cout << tc << ". " << dp[n-1][1] << '\n';
	}
	return 0;
}