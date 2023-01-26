#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#define INF 2e9

using namespace std;

int n, m, s, d;
vector<vector<pair<int, int>>>graph(500);
int dis[501];
bool visited[501];
bool no_enter[501][501];
vector<int>path[501];
struct info {
	int end;
	int cost;
};
struct compare {
	bool operator()(const info a, const info b) {
		return a.cost > b.cost;
	}
};
void init()
{
	memset(no_enter, 0, sizeof(no_enter));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		graph[i].clear();
		path[i].clear();
	}
}
void block()
{
	queue<int>q;
	q.push(d);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == s)continue;
		for (int i = 0; i < path[cur].size(); i++)
		{
			no_enter[path[cur][i]][cur] = true;
			if (visited[path[cur][i]] == false) //메모리 초과를 막기위한 방안
			{
				visited[path[cur][i]] = true;
				q.push(path[cur][i]);
			}
		}
	}
}
void dijkstra(int start)
{
	priority_queue<info, vector<info>, compare>pq;
	dis[start] = 0;
	pq.push({ start,0 });
	path[start].push_back(start);
	while (!pq.empty())
	{
		int cur = pq.top().end;
		int cur_cost = pq.top().cost;
		pq.pop();
		if (dis[cur] < cur_cost) continue;
		for (auto it : graph[cur])
		{
			if (dis[it.first] > dis[cur] + it.second && no_enter[cur][it.first] == false)//최단거리를 찾아 relaxation
			{
				dis[it.first] = dis[cur] + it.second;
				pq.push({ it.first,dis[it.first] });
				path[it.first].clear();
				path[it.first].push_back(cur);
			}
			else if (dis[it.first] == dis[cur] + it.second)  //최단거리경로가 여러 곳 일수도 있음
			{
				path[it.first].push_back(cur);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		cin >> s >> d;
		for (int i = 0; i < m; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;
			graph[u].push_back({ v,p });
		}
		fill(dis, dis + 501, INF);
		dijkstra(s);
		block();
		fill(dis, dis + 501, INF);
		dijkstra(s);
		if (dis[d] == INF)cout << "-1" << '\n';
		else cout << dis[d] << '\n';
		init();
	}
	return 0;
}