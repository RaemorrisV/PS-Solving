#include <iostream>

using namespace std;

int h, w, n;
int dp[1002][1002];
int dp2[1002][1002];
void simulation()
{
	int r = 1;
	int c = 1;
	while (r <= h && c <= w)
	{
		if (dp[r][c] == 1)//오른쪽
		{
			c += 1;
		}
		else //아래
		{
			r += 1;
		}
	}
	cout << r << " " << c << '\n';
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w >> n;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> dp[i][j];
		}
	}
	dp2[1][1] = n - 1;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (dp2[i][j] % 2 == 0)//짝수 라면
			{
				//오른쪽
				dp2[i][j + 1] += dp2[i][j] / 2;
				//아래
				dp2[i + 1][j] += dp2[i][j] / 2;
			}
			else // 홀수라면
			{
				if (dp[i][j] == 1)//오른쪽
				{
					dp2[i][j + 1] += (dp2[i][j] - 1) / 2 + 1;
					dp2[i + 1][j] += (dp2[i][j] - 1) / 2;
				}
				else //아래
				{
					dp2[i][j + 1] += (dp2[i][j] - 1) / 2;
					dp2[i + 1][j] += (dp2[i][j] - 1) / 2 + 1;
				}
			}
		}
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (dp2[i][j] % 2 == 1)//홀수일 경우에만 생각을 해보자
			{
				if (dp[i][j] == 1)//오른쪽
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = 1;
				}
			}
		}
	}
	simulation();
	return 0;
}