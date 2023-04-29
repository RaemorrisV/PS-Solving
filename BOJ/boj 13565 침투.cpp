#include <iostream>
#include <queue>

using namespace std;
int dx[4] = {-1,1,0,0};//상 하 좌 우
int dy[4] = {0,0,-1,1};
int n, m; // n 열 m 행
char map[1001][1001];
bool visited[1001][1001];
bool flag;
bool valide(int r, int c)
{
	if (r >= 1 && r <= m && c >= 1 && c <= n)return true;
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
			if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny]=='0')
			{
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		string a;
		cin >> a;
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = a[j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (map[1][i] == '0')
		{
			bfs(1, i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (map[m][i] == '0' && visited[m][i])
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		cout << "YES" << '\n';
	}
	else

	{
		cout << "NO" << '\n';
	}
	return 0;
}