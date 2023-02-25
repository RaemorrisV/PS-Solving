#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

vector<vector<pair<int, int>>>graph(1001);
int n, m;
bool visited[1001][1001];
int parent[1001];
int dis[1001];
vector<pair<int, int>>ans;
struct compare {
	bool operator() (pair<int, int>a, pair<int, int>b)
	{
		return a.second > b.second;
	}
};
void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
	dis[1] = 0;
	pq.push({ 1,0 });
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
				dis[it.first] = dis[cur] + it.second;
				parent[it.first] = cur;
				pq.push({ it.first,dis[it.first] });
			}
		}
	}
}
void find_road(int cur)
{
	if (cur == 1)return;
	int par = parent[cur];
	if (visited[cur][par] == false)
	{
		visited[cur][par] = true;
		ans.push_back({ cur,par });
	}
	find_road(par);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	fill(dis + 1, dis + n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	dijkstra();
	for (int i = 2; i <= n; i++)
	{
		find_road(i);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << '\n';
 	}
	return 0;
}