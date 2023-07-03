#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<int, int>isRoad[15000];
bool visited[101][101];
bool already[101][101];
int farm[101][101];
int n, k, r, ans;
int dx[4] = { -1,1,0,0 };//╩С го аб ©Л
int dy[4] = { 0,0,-1,1 };
bool valid(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
	return false;
}
void bfs(int r, int c)
{
	queue<pair<int, int>>q;
	q.push({ r,c });
	visited[r][c] = true;
	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			if (valid(nx, ny) && isRoad[(cur_r - 1) * n + cur_c].find((nx - 1) * n + ny) != isRoad[(cur_r - 1) * n + cur_c].end())continue;
			if (valid(nx, ny) && visited[nx][ny] == false)
			{
				q.push({ nx,ny });
				visited[nx][ny] = true;
				if (farm[nx][ny] && already[nx][ny] == false)
				{
					ans++;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k >> r;
	for (int i = 0; i < r; i++)
	{
		int r, c, r1, c1;
		cin >> r >> c >> r1 >> c1;
		isRoad[(r - 1) * n + c].insert({ (r1 - 1) * n + c1, 1 });
		isRoad[(r1 - 1) * n + c1].insert({ (r - 1) * n + c,1 });

	}
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		farm[r][c] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (farm[i][j])
			{
				bfs(i, j);
				already[i][j] = true;
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	cout << (k-1) * (k) / 2 - ans << "\n";
	return 0;
}