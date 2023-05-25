#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, t;
int ans = 500000000;
int castle[101][101];
int dis[101][101];
bool visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; //상 하 좌 우
pair<int, int>gram;
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
	return false;
}
void bfs(int r, int c, int check)
{
	queue<pair<int, int>>q;
	visited[r][c] = true;
	q.push({ r,c });
	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			if (check == 0)
			{
				if (valide(nx, ny) && visited[nx][ny] == false && castle[nx][ny] != 1)
				{
					visited[nx][ny] = true;
					q.push({ nx,ny });
					dis[nx][ny] = dis[cur_r][cur_c] + 1;
				}
			}
			else
			{
				if (valide(nx, ny) && visited[nx][ny] == false)
				{
					visited[nx][ny] = true;
					q.push({ nx,ny });
					dis[nx][ny] = dis[cur_r][cur_c] + 1;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> castle[i][j];
			if (castle[i][j] == 2)
			{
				gram.first = i;
				gram.second = j;
			}
		}
	}
	//먼저 그람이 없을때 최단의 거리를 구해본다!
	bfs(1, 1, 0);
	if (dis[n][m] != 0)ans = min(ans, dis[n][m]);
	int g = dis[gram.first][gram.second];
	memset(dis, 0, sizeof(dis));
	memset(visited, 0, sizeof(visited));
	if(g!=0)bfs(gram.first, gram.second, 1);
	if (dis[n][m] != 0)ans = min(ans, g + dis[n][m]);
	if (ans == 500000000)cout << "Fail" << '\n';
	else if (ans > t)cout << "Fail" << '\n';
	else cout << ans << '\n';
	return 0;
}