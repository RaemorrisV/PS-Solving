#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>>graph(101);
bool visited[101];
bool possible[101][101];
vector<int>ans;
int dis;
void bfs(int start)
{
	queue<int>q;
	visited[start] = true;
	q.push(start);
	possible[start][start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it] == false)
			{
				possible[start][it] = true;
				possible[it][start] = true;
				visited[it] = true;
				q.push(it);
			}
		}
	}
}
void ans_cal()
{
	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= n; j++)
		{
			if (possible[i][j] == false)count++;
		}
		ans.push_back(count);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e; 
		cin >> s >> e;
		graph[s].push_back(e);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		bfs(i);
	}
	ans_cal();
	for (auto it : ans)
	{
		cout << it << "\n";
	}
	return 0;
}