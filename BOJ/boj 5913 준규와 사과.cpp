#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define EMPTY 9999
using namespace std;

int dx[4] = { -1,1,0,0 };//╩С го аб ©Л
int dy[4] = { 0,0,-1,1 };
int land[6][6];
bool visited[6][6];
int k, ans;
int endDepth;
bool valid(int r, int c)
{
	if (r >= 1 && r <= 5 && c >= 1 && c <= 5)return true;
	return false;
}
void dfs(int r, int c, int depth)
{
	if (depth == endDepth-1)
	{
		if (r==5&&c==5)ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (valid(nx, ny) && visited[nx][ny] == false && land[nx][ny] == 0)
		{
			visited[nx][ny] = true;
			dfs(nx, ny, depth + 1);
			visited[nx][ny] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		land[r][c] = EMPTY;
		visited[r][c] = true;
	}
	land[1][1] = EMPTY;
	endDepth = 25 - k;
	visited[1][1] = true;
	dfs(1, 1, 0);
	cout << ans << "\n";
	return 0;
}