#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { -1,0,1,0 };//상 좌 하 우
int dy[4] = { 0,1,0,-1 };
bool visited[21][21];
int board[21][21];
int n, m, k;
int ans;
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
	return false;
}
struct dice {
	int top;
	int bottom;
	int left;
	int right;
	int upper;
	int lower;
	int dir;
	int r;
	int c;
};
dice cur_dice = { 1,6,4,3,2,5,1,1,1 };
void rotate(int B, int A)
{
	if (A > B)
	{
		//시계 방향으로 90도 회전
		cur_dice.dir = (cur_dice.dir + 1) % 4;
	}
	else if (A < B)
	{
		cur_dice.dir = (cur_dice.dir + 3) % 4;
	}
}
void move(int d)
{
	if (d == 0)
	{
		int temp = cur_dice.top;
		cur_dice.top = cur_dice.lower;
		cur_dice.lower = cur_dice.bottom;
		cur_dice.bottom = cur_dice.upper;
		cur_dice.upper = temp;
	}
	else if (d == 1)
	{
		int temp = cur_dice.top;
		cur_dice.top = cur_dice.left;
		cur_dice.left = cur_dice.bottom;
		cur_dice.bottom = cur_dice.right;
		cur_dice.right = temp;
	}
	else if (d == 2)
	{
		int temp = cur_dice.top;
		cur_dice.top = cur_dice.upper;
		cur_dice.upper = cur_dice.bottom;
		cur_dice.bottom = cur_dice.lower;
		cur_dice.lower = temp;

	}
	else
	{
		int temp = cur_dice.top;
		cur_dice.top = cur_dice.right;
		cur_dice.right = cur_dice.bottom;
		cur_dice.bottom = cur_dice.left;
		cur_dice.left = temp;
	}
}
int bfs(int row, int col,int B)
{
	queue<pair<int, int>>q;
	visited[row][col] = true;
	q.push({ row,col });
	int re = B;
	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			if (valide(nx, ny) && visited[nx][ny] == false && board[nx][ny] == B)
			{
				re += B;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return re;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= k; i++)
	{
		int nx = cur_dice.r + dx[cur_dice.dir];
		int ny = cur_dice.c + dy[cur_dice.dir];
		if (!valide(nx, ny))
		{
			cur_dice.dir = (cur_dice.dir + 2) % 4;
		}
		move(cur_dice.dir);
		nx = cur_dice.r + dx[cur_dice.dir];
		ny = cur_dice.c + dy[cur_dice.dir];
		cur_dice.r = nx;
		cur_dice.c = ny;
		rotate(board[nx][ny], cur_dice.bottom);
		memset(visited, 0, sizeof(visited));
		ans += bfs(nx, ny, board[nx][ny]);
	}
	cout << ans << '\n';
	return 0;
}