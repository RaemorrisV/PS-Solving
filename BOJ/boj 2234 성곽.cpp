#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <cstring>
using namespace std;

bool visited[51][51];
int input[51][51];
bitset<4> maze[51][51];
int room[2501];
int dx[4] = { 1,0,-1,0 }; //남 동 북 서
int dy[4] = { 0,1,0,-1 };
int n, m;//열 열
int ans[3];
void tentotwo(int r, int c, int num)
{
	//십진수를 이진수로 바꾸는
	for (int i = 3; i >= 0; i--)
	{
		maze[r][c][i] = num % 2;
		num /= 2;
	}
}
bool valid(int r, int c)
{
	if (r >= 1 && r <= m && c >= 1 && c <= n)return true;
	return false;
}
int bfs(int r, int c,int count)
{
	queue<pair<int, int>>q;
	int area = 1;
	q.push({ r,c });
	input[r][c] = count;
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
			if (maze[cur_r][cur_c][i] == 0 && visited[nx][ny] == false)
			{
				area++;
				visited[nx][ny] = true;
				input[nx][ny] = count;
				q.push({ nx,ny });
			}
		}
	}
	return area;
}
int bfs2(int r, int c,int count)
{
	queue<pair<int, int>>q;
	int area = room[count];
	int total = room[count];
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
			if (valid(nx, ny) && maze[cur_r][cur_c][i] == 1 && input[nx][ny]!=count)
			{
				total = max(total, area + room[input[nx][ny]]);
			}
			if (maze[cur_r][cur_c][i] == 0 && visited[nx][ny] == false)
			{
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	return total;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> input[i][j];
			tentotwo(i, j, input[i][j]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] == false)
			{
				int size = bfs(i, j,ans[0]);
				ans[1] = max(size, ans[1]);
				room[ans[0]] = size;
				ans[0]++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	int t = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] == false)
			{
				int size = bfs2(i, j, t);
				t++;
				ans[2] = max(size, ans[2]);
			}
		}
	}
	for (auto it : ans)
	{
		cout << it << "\n";
	}
	return 0;
}