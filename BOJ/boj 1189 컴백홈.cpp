#include <iostream>

using namespace std;

int r, c, k, ans;
int dx[4] = { -1,1,0,0 }; //╩С го аб ©Л
int dy[4] = { 0,0,-1,1 };
char map[6][6];
bool visited[6][6];
bool valid(int row, int col)
{
	if (row >= 0 && row < r && col >= 0 && col < c)return true;
	return false;
}
void dfs(int row, int col,int dis)
{
	if (row == 0 && col == c - 1)
	{
		if (dis == k)ans++;
		return;
	}
	if (dis == k)return;
	for (int i = 0; i < 4; i++)
	{
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (valid(nx, ny) && visited[nx][ny] == false && map[nx][ny] != 'T')
		{
			visited[nx][ny] = true;
			dfs(nx, ny, dis + 1);
			visited[nx][ny] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> k; 
	for (int i = 0; i < r; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = input[j];
		}
	}
	visited[r - 1][0] = true;
	dfs(r - 1, 0, 1);
	visited[r - 1][0] = false;
	cout << ans << "\n";
	return 0;
}