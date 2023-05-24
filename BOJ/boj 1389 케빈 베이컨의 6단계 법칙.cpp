#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int ans = 1000000000;
int result;
vector<vector<int>>graph(101);
bool visited[101];
int dis[101];
void bfs(int s)
{
	queue<int>q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it] == false)
			{
				dis[it] = dis[cur] + 1;
				q.push(it);
				visited[it] = true;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += dis[i];
	}
	if (ans > sum)result = s;
	ans = min(ans, sum);
}
void init()
{
	memset(visited, 0, sizeof(visited));
	memset(dis, 0, sizeof(dis));
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		init();
		bfs(i);
	}
	cout << result << "\n";
	return 0;
}