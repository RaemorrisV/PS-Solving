#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000
using namespace std;

int input;
vector<int>arr;
int dp[100001][5][5];
int ans = INF;
int cal(int from, int to)
{
	//0에서 이동할 경우 적어 주면 됨
	if (from == 0)return 2;
	if (from == to)return 1;
	if ((from + 2) % 4 == to % 4)return 4;
	if ((from + 1) % 4 == to % 4 || (from - 1) % 4 == to % 4)return 3;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1)
	{
		cin >> input;
		if (input == 0)break;
		arr.push_back(input);
	}
	for (int j = 0; j < 5; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			dp[0][j][k] = INF;
		}
	}
	dp[0][0][arr[0]] = 2;
	dp[0][arr[0]][0] = 2;
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				dp[i][j][k] = INF;
			}
		}
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (dp[i - 1][j][k] != INF)
				{
					//왼발
					if (arr[i] != k)dp[i][arr[i]][k] = min(dp[i - 1][j][k] + cal(j, arr[i]), dp[i][arr[i]][k]);
					//오른발
					if (arr[i] != j)dp[i][j][arr[i]] = min(dp[i - 1][j][k] + cal(k, arr[i]), dp[i][j][arr[i]]);
				}
			}
		}
	}
	for (int j = 0; j < 5; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			ans = min(dp[arr.size() - 1][j][k], ans);
		}
	}
	cout << ans << '\n';
	return 0;
}