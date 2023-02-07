#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 900000000000

using namespace std;

long long dis[50]; //이득의 금액
int n, m, s, e;
vector<vector<pair<int, int>>>graph(50);//도착 지점과 비용
int get_money[50];
bool visited[50];
bool flag = false;
bool bfs(int start, int end)
{
	queue<int>q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it.first] == false)
			{
				visited[it.first] = true;
				q.push(it.first);
			}
		}
	}
	if (visited[end])return true;
	return false;
}
void bellman_ford(int start, int end)
{
	dis[start] = get_money[start];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dis[j] != -INF)
			{
				for (auto it : graph[j])
				{
					if (dis[it.first] < dis[j] + (get_money[it.first] - it.second))
					{
						dis[it.first] = dis[j] + (get_money[it.first] - it.second);
					}
				}
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (dis[j] != -INF)
		{
			for (auto it : graph[j])
			{
				if (dis[it.first] < dis[j] + (get_money[it.first] - it.second))
				{
					flag = bfs(it.first, end);
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	fill(dis, dis + 50, -INF);
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v,c });
	}
	for (int i = 0; i < n; i++)
	{
		cin >> get_money[i];
	}
	bellman_ford(s, e);
	if (flag)
	{
		cout << "Gee" << '\n';
	}
	else
	{
		if (dis[e] == -INF)cout << "gg" << '\n';
		else cout << dis[e] << '\n';
	}
	return 0;
}