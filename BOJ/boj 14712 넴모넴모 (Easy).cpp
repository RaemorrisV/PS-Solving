#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[26][26];
int n, m; //행 렬
long long ans;
int dx[3] = { 0,-1,-1 };
int dy[3] = { -1,-1,0 };
bool valid(int r, int c)
{
	if (r >= 0 && r <= n && c >= 0 && c <= m)return true;
	return false;
}
void dfs(int r, int c)
{
	if (c == m + 1)
	{
		c = 1;
		r++;
	}
	if (r == n + 1)
	{
		ans++;
		return;
	}
	int flag = 0;
	for (int i = 0; i < 3; i++)
	{
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (valid(nx, ny) && visited[nx][ny] == false)flag++;
	}
	//있어도 됨
	if (flag != 0)
	{
		visited[r][c] = true;
		dfs(r, c + 1);
		visited[r][c] = false;
	}
	//놓지 않았을 경우
	dfs(r, c + 1);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	dfs(1, 1);
	cout << ans << "\n";
	return 0;
}