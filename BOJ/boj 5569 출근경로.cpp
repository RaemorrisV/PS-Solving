#include <iostream>
#define MOD 100000
using namespace std;

int w, h;//열 행
int dp[101][101][2][2]; //방향성과 방향전환 가능성  0 동쪽으로 이동 1 북똑으로 이동 0전환 가능 1전환 불가능
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> w >> h; //열 행
	for (int i = 2; i <= h; i++)dp[i][1][1][0] = 1;
	for (int i = 2; i <= w; i++)dp[1][i][0][0] = 1;
	for (int i = 2; i <= h; i++)
	{
		for (int j = 2; j <= w; j++)
		{
			dp[i][j][0][0] = (dp[i][j - 1][0][0] + dp[i][j - 1][0][1]) % MOD;
			dp[i][j][0][1] = dp[i][j - 1][1][0] % MOD;
			dp[i][j][1][0] = (dp[i - 1][j][1][0] + dp[i - 1][j][1][1]) % MOD;
			dp[i][j][1][1] = dp[i-1][j][0][0] % MOD;
		}
	}
	cout << (dp[h][w][0][0] + dp[h][w][0][1] + dp[h][w][1][0] + dp[h][w][1][1]) % MOD << '\n';
	return 0;
}