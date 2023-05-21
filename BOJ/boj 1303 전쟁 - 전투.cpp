#include <iostream>
#include <queue>

using namespace std;

char land[101][101];
bool visited[101][101];
int dx[4] = {-1,1,0,0};//상 하 좌 우
int dy[4] = {0,0,-1,1};
int n, m; //열 행
int ans_w, ans_b;
bool valide(int a, int b)
{
	if (a >= 1 && a <= m && b >= 1 && b <= n)return true;
	return false;
}
int bfs(int r, int c, char solider)
{
	queue<pair<int, int>>q;
	visited[r][c] = true;
	q.push({ r,c });
	int rr = 1;
	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			if (valide(nx, ny) && visited[nx][ny] == false && land[nx][ny] == solider)
			{
				visited[nx][ny] = true;
				q.push({ nx,ny });
				rr++;
			}
		}
	}
	return rr;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= n; j++)
		{
			land[i][j] = input[j - 1];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] == false)
			{
				int r= bfs(i, j, land[i][j]);
				if (land[i][j] == 'W')
				{
					ans_w += r * r;
				}
				else if (land[i][j] == 'B')
				{
					ans_b += r * r;
				}
			}
		}
	}
	cout << ans_w << " " << ans_b << '\n';
	return 0;
}