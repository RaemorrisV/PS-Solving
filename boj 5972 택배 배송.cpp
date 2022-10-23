#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
# define INF INT_MAX
using namespace std;
int dis[50001];
int n, m;
vector<vector<pair<int, int>>>graph(50001);//연결된 곳과 cost
void dijkstra(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;//cost와 다음
	q.push({ 0,s });
	dis[s] = 0;
	while (!q.empty())
	{
		int cur_cost = q.top().first;
		int cur = q.top().second;
		q.pop();
		for (auto it : graph[cur])
		{
			if (dis[it.first] > dis[cur] + it.second)
			{
				dis[it.first] = dis[cur] + it.second;
				q.push({ it.second,it.first });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	fill(dis, dis + n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].push_back({ e,c });
		graph[e].push_back({ s,c });
	}
	dijkstra(1);
	cout << dis[n] << "\n";
	return 0;
}