#include <iostream>
#include <string>
using namespace std;

string step;
string evil;
string angel;
int n;
int dp[2][21][101];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> step >> evil >> angel;
	n = evil.length();
	for (int i = 1; i <= n; i++)
	{
		if (step[0] == evil[i - 1])dp[0][1][i] = dp[0][1][i - 1] + 1;
		else dp[0][1][i] = dp[0][1][i - 1];
		if (step[0] == angel[i - 1])dp[1][1][i] = dp[1][1][i - 1] + 1;
		else dp[1][1][i] = dp[1][1][i - 1];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 2; j <= step.length(); j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (i == 0) //악마의 돌다리 부터 시작
				{
					if (j % 2 == 1 && evil[k - 1] == step[j - 1])dp[i][j][k] = dp[i][j - 1][k - 1] + dp[i][j][k - 1];
					else if (j % 2 == 0 && angel[k - 1] == step[j - 1])dp[i][j][k] = dp[i][j - 1][k - 1] + dp[i][j][k - 1];
					else dp[i][j][k] = dp[i][j][k - 1];
				}
				else if (i == 1)//천사의 돌다리
				{
					if (j % 2 == 0 && evil[k - 1] == step[j - 1])dp[i][j][k] = dp[i][j - 1][k - 1] + dp[i][j][k - 1];
					else if (j % 2 == 1 && angel[k - 1] == step[j - 1])dp[i][j][k] = dp[i][j - 1][k - 1] + dp[i][j][k - 1];
					else dp[i][j][k] = dp[i][j][k - 1];
				}
			}
		}
	}
	cout << dp[0][step.length()][n] + dp[1][step.length()][n] << '\n';
	return 0;
}