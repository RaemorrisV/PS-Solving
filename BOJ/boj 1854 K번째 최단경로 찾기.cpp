#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int n, m, k;
struct node {
	int vertex;
	int cost;
};
bool operator<(node a, node b)
{
	return a.cost > b.cost;
}
int dis[1001][101];
int visit_cnt[1001];
vector<vector<node>>graph(1001);
void dijkstra()
{
	priority_queue<node>pq;
	pq.push({ 1,0 });
	while (!pq.empty())
	{
		int cur = pq.top().vertex;
		int cur_cost = pq.top().cost;
		pq.pop();
		if (visit_cnt[cur] >= k)continue;
		visit_cnt[cur]++;
		dis[cur][visit_cnt[cur]] = cur_cost;
		for (auto it : graph[cur])
		{
			pq.push({ it.vertex,dis[cur][visit_cnt[cur]] + it.cost });
		}
	}
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
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dis[i][j] = INT_MAX;
		}
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
	{
		if (dis[i][k] != INT_MAX)
		{
			cout << dis[i][k] << '\n';
		}
		else
		{
			cout << "-1" << endl;
		}
	}
	return 0;
}