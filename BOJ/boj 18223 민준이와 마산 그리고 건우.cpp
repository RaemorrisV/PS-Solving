#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>>graph(5001);
vector<int>parent[5001];
int dis[5001];
int v, e, p;
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};
void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
	pq.push({ 1,0 });
	dis[1] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().first;
		pq.pop();
		for (auto it : graph[cur])
		{
			if (dis[it.first] >= dis[cur] + it.second)
			{
				if (dis[it.first] > dis[cur] + it.second)parent[it.first].clear();
				parent[it.first].push_back(cur);
				dis[it.first] = dis[cur] + it.second;
				pq.push({ it.first, dis[it.first] });
			}
		}
	}
}
void dfs(int start)
{
	if (start == 0)return;
	if (start == p)
	{
		cout << "SAVE HIM" << "\n";
		exit(0);
	}
	for (int i = 0; i < parent[start].size(); i++)
	{
		dfs(parent[start][i]);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e >> p;
	fill(dis, dis + v + 1, INT_MAX);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	parent[1].push_back(0);
	dijkstra();
	dfs(v);
	cout << "GOOD BYE" << '\n';
	return 0;
}