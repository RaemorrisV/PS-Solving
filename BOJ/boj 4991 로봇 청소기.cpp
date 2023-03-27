#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct location {
	int r_idx;
	int c_idx;
};
int w, h;//w:열 h:행
char home[21][21];
bool visited[21][21];
vector<location>dirty;
int dirtycnt = 0;
location start;
vector<int>order;
bool visit[10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dis[21][21][21][21];
int ans = 1000000000;
bool flag;
bool valide(int r, int c)
{
	if (r >= 1 && r <= h && c >= 1 && c <= w)return true;
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
			if (valide(nx, ny) && visited[nx][ny] == false && home[nx][ny] != 'x')
			{
				visited[nx][ny] = true;
				dis[r][c][nx][ny] = dis[r][c][cur_r][cur_c] + 1;
				q.push({ nx,ny });
			}
		}
	}
}
void make_dis()
{
	bfs(start.r_idx, start.c_idx);
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < dirty.size(); i++)
	{
		if (dis[start.r_idx][start.c_idx][dirty[i].r_idx][dirty[i].c_idx] == 0)
		{
			flag = true;
			return;
		}
	}
	for (int i = 0; i < dirty.size(); i++)
	{
		bfs(dirty[i].r_idx, dirty[i].c_idx);
		memset(visited, 0, sizeof(visited));
	}
}
void dfs(int cur)
{
	if (order.size() == dirty.size())
	{
		//여기서 bfs
		int temp = 0;
		temp += dis[start.r_idx][start.c_idx][dirty[order[0]].r_idx][dirty[order[0]].c_idx];
		for (int i = 0; i < order.size() - 1; i++)
		{
			temp += dis[dirty[order[i]].r_idx][dirty[order[i]].c_idx][dirty[order[i + 1]].r_idx][dirty[order[i + 1]].c_idx];
		}
		ans = min(ans, temp);
		return;
	}
	for (int i = 0; i < dirty.size(); i++)
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			order.push_back(i);
			dfs(i);
			order.pop_back();
			visit[i] = false;
		}
	}
}
void init()
{
	ans = 1000000000;
	dirty.clear();
	flag = false;
	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)break;
		init();
		for (int i = 1; i <= h; i++)
		{
			string input;
			cin >> input;
			for (int j = 1; j <= w; j++)
			{
				home[i][j] = input[j - 1];
				if (home[i][j] == 'o')
				{
					start = { i,j };
				}
				else if (home[i][j] == '*')
				{
					dirty.push_back({ i,j });
				}
			}
		}
		make_dis();
		if (flag)cout << -1 << '\n';
		else
		{
			for (int i = 0; i < dirty.size(); i++)
			{
				visit[i] = true;
				order.push_back(i);
				dfs(i);
				order.pop_back();
				visit[i] = false;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}