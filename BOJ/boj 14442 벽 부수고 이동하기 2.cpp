#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
char map[1000][1000];
int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };
int ans = 1000000000;
int dis[11][1000][1000];
struct moveInfo {
	int breakc;
	int c_r;
	int c_c;
};
bool valid(int r, int c)
{
	if (r >= 0 && r < n && c >= 0 && c < m)return true;
	return false;
}
void bfs(int r,int c)
{
	queue<moveInfo>q;
	q.push({ 0,0,0 });
	dis[0][r][c] = 1;
	while (!q.empty())
	{
		int cur_b = q.front().breakc;
		int cur_r = q.front().c_r;
		int cur_c = q.front().c_c;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			if (valid(nx, ny))
			{
				//벽이 있을때
				if (map[nx][ny] == '1' && cur_b < k && dis[cur_b+1][nx][ny]>dis[cur_b][cur_r][cur_c]+1)
				{
					dis[cur_b + 1][nx][ny] = dis[cur_b][cur_r][cur_c] + 1;
					q.push({ cur_b + 1,nx,ny });
				}
				//벽이 없을때
				else if(map[nx][ny] == '0' && cur_b <= k&& dis[cur_b][nx][ny]>dis[cur_b][cur_r][cur_c] + 1)
				{
					dis[cur_b][nx][ny] = dis[cur_b][cur_r][cur_c] + 1;
					q.push({ cur_b,nx,ny });
				}
			}
		}
	}
}
void init()
{
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < m; z++)
			{
				dis[i][j][z] = 1000000000;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	init();
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = input[j];
		}
	}
	bfs(0, 0);
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dis[i][n - 1][m - 1]);
	}
	if (ans == 1000000000)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}
