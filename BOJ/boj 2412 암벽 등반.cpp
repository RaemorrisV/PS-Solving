#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int n, t, ans;
unordered_map<string, bool>coordinate;
unordered_map<string, bool>visited;
struct queueinfo {
	int r;
	int c;
	int dis;
};
void bfs()
{
	queue<queueinfo>q;
	q.push({ 0,0 ,0 });
	visited[to_string(0) + ',' + to_string(0)] = true;
	while (!q.empty())
	{
		int cur_r = q.front().r;
		int cur_c = q.front().c;
		int cur_dis = q.front().dis;
		q.pop();
		if (cur_c == t)
		{
			ans = cur_dis;
			return;
		}
		for (int i = -2; i <= 2; i++)
		{
			for (int j = -2; j <= 2; j++)
			{
				if (i == 0 && j == 0)continue;
				int nx = cur_r + i;
				int ny = cur_c + j;
				string coor = to_string(nx) + ',' + to_string(ny);
				if (coordinate[coor] && !visited[coor])
				{
					visited[coor] = true;
					q.push({ nx,ny ,cur_dis + 1 });
				}
			}
		}
	}

}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		coordinate[to_string(x) + ',' + to_string(y)] = true;
	}
	bfs();
	if (ans == 0)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}