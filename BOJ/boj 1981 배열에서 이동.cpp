#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = { -1,1,0,0 }; //상 하 좌 우
int dy[4] = { 0,0,-1,1 };
int n;
int arr[101][101];
bool visited[101][101];
vector<int>num;
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
	return false;
}
bool bfs(int low, int high)
{
	if (low > arr[1][1] || high < arr[1][1])return false;
	queue<pair<int, int>>q;
	q.push({ 1,1 });
	visited[1][1] = true;
	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			int nc = arr[nx][ny];
			if (valide(nx, ny) && visited[nx][ny] == false && nc >= low && nc <= high)
			{
				visited[nx][ny] = true;
				q.push({ nx,ny });
				if (nx == n && ny == n)return true;
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			num.push_back(arr[i][j]);
		}
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	int s = 0;
	int e = 0;
	int ans = 202;
	while (s <= e && e < num.size())
	{
		memset(visited, 0, sizeof(visited));
		if (bfs(num[s], num[e])) //갈 수 있다면?
		{
			ans = min(ans, num[e] - num[s]);
			s++;
		}
		else // 갈 수 없다면?
		{
			e++;
		}
	}
	cout << ans << '\n';
	return 0;
}