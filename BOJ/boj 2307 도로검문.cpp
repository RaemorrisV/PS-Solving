#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

int n, m, ans, MIN;
int dis[1001];
vector<vector<pair<int, int>>>graph(1001);
vector<int>parent[1001];
struct compare {
	bool operator()(pair<int, int>a, pair<int, int>b)
	{
		return a.second > b.second;
	}
};
void dijkstra(bool flag)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
	pq.push({ 1,0 });
	dis[1] = 0;
	if (flag)parent[1].push_back(-1);
	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		if (cur_cost > dis[cur])continue;
		for (auto it : graph[cur])
		{
			if (dis[it.first] > dis[cur] + it.second)
			{
				if (flag)
				{
					parent[it.first].clear();
					parent[it.first].push_back(cur);
				}
				dis[it.first] = dis[cur] + it.second;
				pq.push({ it.first,dis[it.first] });
			}
		}
	}
}
void find_ans(int p)
{
	if (p == 1)return;
	int idx, p_idx, temp, p_temp;
	for (int i = 0; i < graph[p].size(); i++)
	{
		if (graph[p][i].first == parent[p][0])
		{
			idx = i;
			temp = graph[p][i].second;
			graph[p][i].second = INF;

		}
	}
	for (int i = 0; i < graph[parent[p][0]].size(); i++)
	{
		if (graph[parent[p][0]][i].first == p)
		{
			p_idx = i;
			p_temp = graph[parent[p][0]][i].second;
			graph[parent[p][0]][i].second = INF;
		}
	}
	fill(dis + 1, dis + n + 1, INF);
	dijkstra(false);
	if (dis[n] == INF)ans = INF;
	ans = max(ans, dis[n] - MIN);
	graph[p][idx].second = temp;
	graph[parent[p][0]][p_idx].second = p_temp;
	find_ans(parent[p][0]);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	fill(dis + 1, dis + n + 1, INF);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	dijkstra(true);
	MIN = dis[n];
	find_ans(n);
	if (ans == MIN)cout << 0 << '\n';
	else if (ans == INF)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}