#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>>graph(50001);
bool visited[50001];
int parent[17][50001];
int depth[50001];

void make_table()
{
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}
int LCA(int a, int b)
{
	if (depth[a] < depth[b]) //a의 깊이가 항상 크게 만들어줌
	{
		int temp = a;
		a = b;
		b = temp;
	}
	//1.깊이를 같게 만들어 준다
	int diff = depth[a] - depth[b];
	for (int i = 0, mask = 1; mask <= diff; i++, mask <<= 1)
	{
		if (mask & diff)a = parent[i][a];
	}
	//2.이제 최소 공통 조상을 찾아주자
	while (a != b)
	{
		int t_a = a;
		int t_b = b;
		for (int i = 0; i < 17; i++)
		{
			t_a = parent[i][a];
			t_b = parent[i][b];
			if (t_a == t_b)
			{
				if (i == 0)
				{
					a = parent[0][a];
					b = parent[0][b];
					break;
				}
				else
				{
					a = parent[i - 1][a];
					b = parent[i - 1][b];
					break;
				}
			}
		}
	}
	return a;
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
			if (visited[it] == false)
			{
				parent[0][it] = cur;
				visited[it] = true;
				q.push(it);
				depth[it] = depth[cur] + 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs();
	make_table();
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}