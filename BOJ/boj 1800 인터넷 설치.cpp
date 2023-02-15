#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 2000000 
using namespace std;

int n, m, k;
vector<vector<pair<int, int>>>graph(1001);
int dis[1001];
vector<int>cost;
int ans = INF;
bool bfs(int para)
{
	queue<pair<int, int>>q;
	dis[1] = 0;
	q.push({ 1 ,0 });
	while (!q.empty())
	{
		int cur = q.front().first;
		q.pop();
		for (auto it : graph[cur])
		{
			int c = it.second > para ? 1 : 0;
			if (dis[it.first] > dis[cur] + c)
			{
				dis[it.first] = dis[cur] + c;
				q.push({ it.first,dis[it.first]});
			}
		}
	}
	return dis[n] <= k;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
		cost.push_back(c);
	}
	sort(cost.begin(), cost.end());
	int s = 0;
	int e = cost[cost.size() - 1];
	while (s <= e)
	{
		fill(dis + 1, dis + n + 1, INF);
		int mid = (s + e) / 2;
		if (bfs(mid))
		{
			e = mid - 1;
			ans = mid;
		}
		else
		{
			s = mid + 1;
		}
	}
	if (ans == INF)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}