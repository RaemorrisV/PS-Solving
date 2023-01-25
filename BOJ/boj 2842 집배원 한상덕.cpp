#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char map[51][51];
int height[51][51];
bool visited[51][51];
int dx[8] = { -1,1,0,0,-1,-1,1,1 };// 상 하 좌 우 대각선
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
int home_cnt = 0;
vector<int>h_order;
pair<int, int>postoffice;
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
	return false;
}
bool bfs(int low, int high)//피로도를 파라미터로 입력 하면
{
	queue<pair<int, int>>q;
	int res = 0;
	int post = height[postoffice.first][postoffice.second];
	if (post<low || post>high)return false;
	visited[postoffice.first][postoffice.second] = true;
	q.push({ postoffice.first,postoffice.second });
	while (!q.empty())
	{
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = cur_r + dx[i];
			int ny = cur_c + dy[i];
			int nh = height[nx][ny];
			if (valide(nx, ny) && visited[nx][ny] == false && nh <= high && nh >= low) //피로도
			{
				visited[nx][ny] = true;
				q.push({ nx,ny });
				if (map[nx][ny] == 'K')res++;
				if (res == home_cnt)return true;
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
		string in;
		cin >> in;
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = in[j - 1];
			if (map[i][j] == 'P')postoffice = { i,j };
			else if (map[i][j] == 'K')home_cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> height[i][j];
			h_order.push_back(height[i][j]);
		}
	}
	sort(h_order.begin(), h_order.end());
	h_order.erase(unique(h_order.begin(), h_order.end()), h_order.end());
	int s = 0;
	int e = 0;
	int ans = 2e9;
	while (e < h_order.size() && s<=e)
	{
		memset(visited, 0, sizeof(visited));
		if (bfs(h_order[s], h_order[e]))// 전부 방문이 가능하다면? 
		{
			ans = min(ans, h_order[e] - h_order[s]);
			s++;
		}
		else
		{
			e++;
		}
	}
	cout << ans << '\n';
	return 0;
}