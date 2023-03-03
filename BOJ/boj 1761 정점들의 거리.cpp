#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>>graph(40001);
int parent[17][40001];
int parent_cost[17][40001];
int dis[40001];
bool visited[40001];
int ans;
void sparse()
{
	//희소 배열 구하기
	for (int i = 1; i < 17; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			parent_cost[i][j] = parent_cost[i - 1][j] + parent_cost[i - 1][parent[i - 1][j]];
		}
	}
	/*
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << parent_cost[i][j] << " ";
		}
		cout << endl;
	}
	*/ 
}
void lca(int a, int b)//a가 항상 위쪽에 존재함
{
	//먼저 위치를 같게 만들어 줘야함
	int diff = dis[b] - dis[a];
	for (int j = 0, mask = 1; mask <= diff; j++, mask <<= 1)
	{
		if (mask & diff)
		{
			ans += parent_cost[j][b];
			b = parent[j][b];
		}
	}
	//높이를 같게 만들어 줬다면 이제 공통 조상을 찾도록해보자
	while (a != b)
	{
		for (int i = 0; i < 17; i++)
		{
			if (parent[i][b] == parent[i][a] && i != 0)
			{
				ans += parent_cost[i - 1][b];
				ans += parent_cost[i - 1][a];
				b = parent[i - 1][b];
				a = parent[i - 1][a];
				break;
			}
			else if (parent[i][b] == parent[i][a] && i == 0)
			{
				ans += parent_cost[0][b];
				ans += parent_cost[0][a];
				b = parent[0][b];
				a = parent[0][a];
				break;
			}
		}
	}
	cout << ans << '\n';
	ans = 0;
}
void bfs()
{
	queue<int>q;
	visited[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it.first] == false)
			{
				parent[0][it.first] = cur;
				visited[it.first] = true;
				parent_cost[0][it.first] = it.second;
				dis[it.first] = dis[cur] + 1;
				q.push(it.first);
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
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	bfs();
	sparse();
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (dis[a] > dis[b])
		{
			int temp = a;
			a = b;
			b = temp;
		}
		lca(a, b);
	}
	return 0;
}