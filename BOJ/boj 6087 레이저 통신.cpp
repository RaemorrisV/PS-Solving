#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 10002
using namespace std;

int w, h;
char map[101][101];
int dis[101][101][4];
int dx[4] = { -1,0,1,0 }; // 상 우 하 좌
int dy[4] = { 0,1,0,-1 };
//dir 0 상 1 우 2 하 3 좌
int ans = INF;
vector<pair<int, int>>c_idx;
bool valide(int r, int c)
{
	if (r >= 1 && r <= h && c >= 1 && c <= w)return true;
	return false;
}
struct info {
	int x;
	int y;
	int dir;
	int val;
};
struct compare {
	bool operator()(info a, info b)
	{
		return a.val > b.val;
	}
};
void dijkstra(int r, int c)
{
	priority_queue<info, vector<info>, compare>pq;
	for (int i = 0; i < 4; i++)
	{
		pq.push({ r,c,i,0 });
		dis[r][c][i] = 0;
	}
	while (!pq.empty())
	{
		int cur_r = pq.top().x;
		int cur_c = pq.top().y;
		int cur_val = pq.top().val;
		int cur_dir = pq.top().dir;
		pq.pop();
		if (cur_val > dis[cur_r][cur_c][cur_dir])continue;
		for (int i = 0; i < 4; i++)
		{
			if ((cur_dir + 2) % 4 == i)continue;
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			if (valide(nx, ny) && map[nx][ny] != '*')
			{
				if (cur_dir == i) //같은 방향으로 갈떄
				{
					if (dis[nx][ny][i] > dis[cur_r][cur_c][i])
					{
						dis[nx][ny][i] = dis[cur_r][cur_c][i];
						pq.push({ nx,ny,i,dis[nx][ny][i]});
					}
				}
				else //다른 방향으로가서 거울을 추가해야할때
				{
					if (dis[nx][ny][i] > dis[cur_r][cur_c][cur_dir] + 1)
					{
						dis[nx][ny][i] = dis[cur_r][cur_c][cur_dir] + 1;
						pq.push({ nx,ny,i,dis[nx][ny][i]});
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> w >> h;//열 행
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				dis[i][j][k] = INF;
			}
		}
	}
	for (int i = 1; i <= h; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= w; j++)
		{
			map[i][j] = input[j - 1];
			if (map[i][j] == 'C')c_idx.push_back({ i,j });
		}
	}
	dijkstra(c_idx[0].first, c_idx[0].second);
	for (int i = 0; i < 4; i++)
	{
		ans = min(dis[c_idx[1].first][c_idx[1].second][i], ans);
	}
	cout << ans << '\n';
	/*
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cout << dis[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	*/
	return 0;
}