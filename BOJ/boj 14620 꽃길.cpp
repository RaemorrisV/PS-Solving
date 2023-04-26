#include <iostream>
#include <algorithm>

using namespace std;

int n;
bool visited[11][11];
int garden[11][11];
int dx[4] = { -1,1,0,0 };// ╩С го аб ©Л
int dy[4] = { 0,0,-1,1 };
int ans = 1000000000;
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
	return false;
}
void dfs(int count, int s)
{
	if (count == 3)
	{
		ans = min(s, ans);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int c = 0;
			int cur = garden[i][j];
			if (visited[i][j] == false)
			{
				for (int z = 0; z < 4; z++)
				{
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (valide(nx, ny) && visited[nx][ny] == false)
					{
						c++;
						cur += garden[nx][ny];
					}
				}
				if (c == 4)
				{
					for (int z = 0; z < 4; z++)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						visited[nx][ny] = true;
					}
					visited[i][j] = true;
					dfs(count+1, cur+s);
					visited[i][j] = false;
					for (int z = 0; z < 4; z++)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						visited[nx][ny] = false;
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> garden[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int c = 0;
			int cur = garden[i][j];
			if (visited[i][j] == false)
			{
				for (int z = 0; z < 4; z++)
				{
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (valide(nx, ny) && visited[nx][ny] == false)
					{
						c++;
						cur += garden[nx][ny];
					}
				}
				if (c == 4)
				{
					for (int z = 0; z < 4; z++)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						visited[nx][ny] = true;
					}
					visited[i][j] = true;
					dfs(1, cur);
					visited[i][j] = false;
					for (int z = 0; z < 4; z++)
					{
						int nx = i + dx[z];
						int ny = j + dy[z];
						visited[nx][ny] = false;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}