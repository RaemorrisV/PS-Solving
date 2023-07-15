#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n;
vector<vector<int>>graph(1001);
bool visited[1001];
int dis[1001][1001];
bool flag;
void bfs(int start)
{
	queue<int>q;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it] == false)
			{
				q.push(it);
				visited[it] = true;
				dis[cur][it] = 1;
				dis[start][it] = 1;
			}
		}
	}

}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
	}
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
		memset(visited, 0, sizeof(visited));
	}
	for (int i = 1; i <= n; i++)
	{
		int counting = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dis[j][i])counting++;
		}
		if (counting == n - 1)
		{
			cout << i << '\n';
			flag = true;
			break;
		}
	}
	if (flag == false)cout << -1 << "\n";
	return 0;
}