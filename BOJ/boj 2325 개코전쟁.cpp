#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m;
vector<vector<pair<int, int>>>graph(1001);
int dis[1001];
vector<int>parent[1001];
int MAX;
int idx, idx1, temp, temp2;
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
	if (flag)parent[1].push_back(0);
	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cur_cost = pq.top().second;
		pq.pop();
		if (dis[cur] < cur_cost)continue;
		for (auto it : graph[cur])
		{
			if (dis[it.first] > dis[cur] + it.second)
			{
				if (dis[it.first] > dis[cur] + it.second && flag)parent[it.first].clear();
				if (flag)parent[it.first].push_back(cur);
				dis[it.first] = dis[cur] + it.second;
				pq.push({ it.first,dis[it.first] });
			}
		}
	}
}
void find_max(int start)
{
	if (start == 1)return;
	for (auto i : parent[start])
	{
		fill(dis + 1, dis + 1 + n, INF);
		for (int j = 0; j < graph[start].size(); j++)
		{
			if (graph[start][j].first == i)
			{
				idx = j;
				temp = graph[start][j].second;
				graph[start][j].second = INF;
				break;
			}
		}
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (graph[i][j].first == start)
			{
				idx1 = j;
				temp2 = graph[i][j].second;
				graph[i][j].second = INF;
				break;
			}
		}
		dijkstra(false);
		graph[start][idx].second = temp;
		graph[i][idx1].second = temp2;
		MAX = max(MAX, dis[n]);
		find_max(i);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	fill(dis + 1, dis + 1 + n, INF);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	dijkstra(true);
	for (int i = 1; i <= n; i++)
	{
		sort(parent[i].begin(), parent[i].end());
		parent[i].erase(unique(parent[i].begin(), parent[i].end()), parent[i].end());
	}
	MAX = dis[n];
	find_max(n);
	cout << MAX << '\n';
	return 0;
}