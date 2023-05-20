#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;//행 열 쓰레기 개수
int road[101][101];
int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };
bool visited[101][101];
int ans;
bool valide(int a, int b)
{
	if (a >= 1 && a <= n && b >= 1 && b <= m)return true;
	return false;
}
int bfs(int a, int b)
{
	int c = 1;
	queue<pair<int, int>>q;
	q.push({ a,b });
	visited[a][b] = true;
	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			if (valide(nx, ny) && visited[nx][ny] == false && road[nx][ny] == 1)
			{
				c++;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return c;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		road[a][b] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (visited[i][j] == false && road[i][j] == 1)
			{
				ans = max(bfs(i, j), ans);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}