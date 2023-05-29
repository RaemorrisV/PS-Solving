#include <iostream>
#include <vector>

using namespace std;
int n, m, ans;//행 열
int board[1001][1001];
vector<pair<int, int>>queen;
vector<pair<int, int>>knight;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
	return false;
}
void check()
{
	for (int i = 0; i < queen.size(); i++)
	{
		//가로
		for (int j = queen[i].second - 1; j >= 1; j--)
		{
			int x = queen[i].first;
			if (valide(x, j) && board[x][j] == 2)break;
			else if (valide(x, j) && board[x][j] != 2)
			{
				board[x][j] = 1;
			}
		}
		for (int j = queen[i].second + 1; j <= m; j++)
		{
			int x = queen[i].first;
			if (valide(x, j) && board[x][j] == 2)break;
			else if (valide(x, j) && board[x][j] != 2)
			{
				board[x][j] = 1;
			}
		}
		//세로
		for (int j = queen[i].first - 1; j >= 1; j--)
		{
			int y = queen[i].second;
			if (valide(j, y) && board[j][y] == 2)break;
			else if (valide(j, y) && board[j][y] != 2)
			{
				board[j][y] = 1;
			}
		}
		for (int j = queen[i].first + 1; j <= n; j++)
		{
			int y = queen[i].second;
			if (valide(j, y) && board[j][y] == 2)break;
			if (valide(j, y) && board[j][y] != 2)
			{
				board[j][y] = 1;
			}
		}
		//대각선  - - , - + , + + , + - 
		bool flag1 = false;
		bool flag2 = false;
		bool flag3 = false;
		bool flag4 = false;
		for (int j = 1; j <= 1500; j++)
		{
			int nx1 = queen[i].first - j;
			int ny1 = queen[i].second - j;
			int nx2 = queen[i].first - j;
			int ny2 = queen[i].second + j;
			int nx3 = queen[i].first + j;
			int ny3 = queen[i].second + j;
			int nx4 = queen[i].first + j;
			int ny4 = queen[i].second - j;
			if (valide(nx1, ny1) && board[nx1][ny1] == 2)flag1 = true;
			else if (valide(nx1, ny1) && board[nx1][ny1] != 2 && flag1 == false)
			{
				board[nx1][ny1] = 1;
			}
			if (valide(nx2, ny2) && board[nx2][ny2] == 2)flag2 = true;
			else if (valide(nx2, ny2) && board[nx2][ny2] != 2 && flag2 == false)
			{
				board[nx2][ny2] = 1;
			}
			if (valide(nx3, ny3) && board[nx3][ny3] == 2)flag3 = true;
			else if (valide(nx3, ny3) && board[nx3][ny3] != 2 && flag3 == false)
			{
				board[nx3][ny3] = 1;
			}
			if (valide(nx4, ny4) && board[nx4][ny4] == 2)flag4 = true;
			else if (valide(nx4, ny4) && board[nx4][ny4] != 2 && flag4 == false)
			{
				board[nx4][ny4] = 1;
			}
		}
	}
	for (int i = 0; i < knight.size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int nx = knight[i].first + dx[j];
			int ny = knight[i].second + dy[j];
			if (valide(nx, ny) && board[nx][ny] != 2)
			{
				board[nx][ny] = 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < 3; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
			if (i == 0)queen.push_back({ x,y });
			else if (i == 1)knight.push_back({ x,y });
			board[x][y] = 2; 
		}
	}
	check();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 0)ans++;
			//cout << board[i][j] << " ";
		}
		//cout << endl;
	}
	cout << ans << "\n";
	return 0;
}