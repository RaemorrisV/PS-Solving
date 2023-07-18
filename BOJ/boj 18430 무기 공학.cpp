#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int strength[5][5];
bool visited[5][5];
int n, m;//За ї­
int ans;
int dx[4][2] = { {0,1},{-1,0},{-1,0},{0,1} };
int dy[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
bool valid(int r, int c)
{
	if (r >= 0 && r < n && c >= 0 && c < m)return true;
	return false;
}
void dfs(int r, int c, int total)
{
	ans = max(ans, total);
	if (c == m)
	{
		r++;
		c = 0;
	}
	if (r == n)return;
	if (visited[r][c] == false)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = 0;
			int ny = 0;
			int nx2 = 0;
			int ny2 = 0;
			nx = r + dx[i][0];
			ny = c + dy[i][0];
			nx2 = r + dx[i][1];
			ny2 = c + dy[i][1];
			if (valid(nx, ny) && valid(nx2, ny2) && visited[nx][ny] == false && visited[nx2][ny2] == false)
			{
				int temp = 0;
				for (int j = 0; j < 2; j++)
				{
					nx = r + dx[i][j];
					ny = c + dy[i][j];
					temp += strength[nx][ny];
					visited[nx][ny] = true;
				}
				visited[r][c] = true;
				dfs(r, c + 1, temp + total + 2 * strength[r][c]);
				visited[r][c] = false;
				for (int j = 0; j < 2; j++)
				{
					nx = r + dx[i][j];
					ny = c + dy[i][j];
					visited[nx][ny] = false;
				}
			}
		}
	}
	dfs(r, c + 1, total);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> strength[i][j];
		}
	}
	dfs(0, 0, 0);
	cout << ans << "\n";
	return 0;
}