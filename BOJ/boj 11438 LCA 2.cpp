#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int depth[100001];
bool visited[100001];
int sparse[18][100001]; //약 13만
vector<vector<int>>graph(100001);
void sparsearr()
{
	int offset = 1;
	int cnt = 0;
	for (offset = 1; offset < n; offset *= 2)
	{
		cnt++;
	}
	for (int i = 1; i <= cnt-1; i++)  // 행
	{
		for (int j = 1; j <= n; j++) //열
		{
			sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
		}
	}
}
void bfs()
{
	queue<int>q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it] == false)
			{
				sparse[0][it] = cur;
				visited[it] = true;
				depth[it] = depth[cur] + 1;
				q.push(it);
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
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(); //부모와 길이 저장
	sparsearr(); //희소배열 완성
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (depth[a] < depth[b])
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int diff = depth[a] - depth[b];
		for (int j = 0, mask = 1; mask <= diff; j++, mask <<= 1)
		{
			if (diff & mask) a = sparse[j][a];
		}
		while (a != b)
		{
			int t_a = a;
			int t_b = b;
			for (int k = 0; k <= 17; k++)
			{
				t_a = sparse[k][a];
				t_b = sparse[k][b];
				if (t_a == t_b)
				{
					if (k == 0)
					{
						a = sparse[0][a];
						b = sparse[0][b];
						break;
					}
					else
					{
						a = sparse[k - 1][a];
						b = sparse[k - 1][b];
						break;
					}
				}
			}
		}
		cout << a << "\n";
	}
	return 0;
}