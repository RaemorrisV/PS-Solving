#include <iostream>
#include <algorithm>

using namespace std;

int n, m;//행 열
char board[51][51];
int dp[51][51];
bool visited[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 1;
bool circul = false;
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
	return false;
}
//순환고리가 생성되면 무한번 움직일 수 있음 >> dfs
void dfs(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = r + dx[i] * (board[r][c] - '0');
		int ny = c + dy[i] * (board[r][c] - '0');
		if (circul)return;
		if (valide(nx, ny) && visited[nx][ny])
		{
			circul = true;
			return;
		}
		else
		{
			if (valide(nx, ny) && visited[nx][ny] == false && board[nx][ny] != 'H')
			{
				if (dp[nx][ny] >= dp[r][c] + 1)continue;
				visited[nx][ny] = true;
				dp[nx][ny] = dp[r][c] + 1;
				dfs(nx, ny);
				visited[nx][ny] = false;
			}
			else if (valide(nx, ny) == false || board[nx][ny] == 'H')
			{
				ans = max(ans, dp[r][c] + 1);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++)
		{
			board[i][j] = input[j - 1];
		}
	}
	visited[1][1] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = 1 + dx[i] * (board[1][1] - '0');
		int ny = 1 + dy[i] * (board[1][1] - '0');
		if (circul)break;
		if (valide(nx, ny) && visited[nx][ny] == false && board[nx][ny] != 'H')
		{
			if (dp[nx][ny] >= dp[1][1] + 1)continue;
			visited[nx][ny] = true;
			dp[nx][ny] = max(dp[nx][ny], dp[1][1] + 1);
			dfs(nx, ny);
			visited[nx][ny] = false;
		}
		else if (valide(nx, ny) == false || board[nx][ny] == 'H')
		{
			ans = max(ans, dp[1][1] + 1);
		}
	}
	if (circul)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << ans << '\n';
	}
	return 0;
}