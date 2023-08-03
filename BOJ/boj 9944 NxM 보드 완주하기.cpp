#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool visited[31][31];
int n, m, emptyCount;
int ans = 1000000000;
int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };
char board[31][31];
int t = 1;
void init()
{
	ans = 1000000000;
	emptyCount = 0;
	memset(visited, 0, sizeof(visited));
}
bool valid(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
	return false;
}
void dfs(int depth, int r, int c, int stage, int forward)
{
	if (depth == emptyCount)
	{
		ans = min(ans, stage);
		return;
	}
	int nx = r + dx[forward];
	int ny = c + dy[forward];
	//멈추고 방향을 바꿔야함
	if (!valid(nx, ny) || visited[nx][ny] || board[nx][ny] == '*')
	{
		for (int i = 0; i < 4; i++)
		{
			int rx = r + dx[i];
			int ry = c + dy[i];
			if (valid(rx, ry) && visited[rx][ry] == false && board[rx][ry] == '.')
			{
				visited[rx][ry] = true;
				dfs(depth + 1, rx, ry, stage + 1, i);
				visited[rx][ry] = false;
			}
		}
	}
	//방향 안바꿔도됨
	else
	{
		visited[nx][ny] = true;
		dfs(depth + 1, nx, ny, stage, forward);
		visited[nx][ny] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> n >> m)
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			string input;
			cin >> input;
			for (int j = 1; j <= m; j++)
			{
				board[i][j] = input[j - 1];
				if (board[i][j] == '.')emptyCount++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (board[i][j] == '.')
				{
					for (int z = 0; z < 4; z++)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						if (valid(nx, ny) && board[nx][ny] == '.')
						{
							visited[i][j] = true;
							dfs(1, i, j, 1, z);
							visited[i][j] = false;
						}
					}
				}
			}
		}
		if (emptyCount == 1)ans = 0;
		if (ans == 1000000000)
		{
			ans = -1;
		}
		cout <<"Case "<< t <<": " << ans << '\n';
		t++;
	}
	return 0;
}
