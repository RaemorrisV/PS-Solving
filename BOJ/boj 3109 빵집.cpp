#include <iostream>

using namespace std;

int r, c, ans;
char map[10000][500];
bool use[10000][500];
int dx[3] = { -1,0,1 };
int dy[3] = { 1,1,1 };
bool flag;
bool valide(int row, int col)
{
	if (row >= 0 && row < r && col >= 0 && col < c)return true;
	return false;
}
void dfs(int row, int col)
{
	if (col == c - 1)
	{
		use[row][col] = true;
		ans++;
		flag = true;
		return;
	}
	for (int k = 0; k < 3; k++)
	{
		int nx = row + dx[k];
		int ny = col + dy[k];
		if (valide(nx, ny) && use[nx][ny] == false && map[nx][ny] == '.')
		{
			use[nx][ny] = true;
			dfs(nx, ny);
			if (flag)break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = input[j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		use[i][0] = true;
		dfs(i, 0);
		flag = false;
	}
	cout << ans << '\n';
	return 0;
}