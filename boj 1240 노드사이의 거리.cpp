#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int dis[1001];
bool visited[1001];
vector<vector<pair<int, int>>> graph(1001); //도착과 cost 저장
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it.first] == false)
			{
				q.push(it.first);
				visited[it.first] = true;
				dis[it.first] += dis[cur] + it.second;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].push_back({e, c});
		graph[e].push_back({s, c});
	}
	for (int i = 0; i < m; i++)
	{
		int ts, te;
		cin >> ts >> te;
		bfs(ts);
		cout << dis[te] << '\n';
		memset(visited, 0, sizeof(visited));
		fill(dis, dis + n + 1, 0);
	}
}