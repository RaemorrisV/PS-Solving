#include <iostream>
#include <queue>
#include <algorithm> 
#include <vector>
#define INF 1000002

using namespace std;

int parent[18][100001]; //LCA
int mintable[18][100001]; //최솟값을 위한 정의
int maxtable[18][100001]; //최댓값을 위한 정의
bool visited[100001];
int depth[100001];
vector<vector<pair<int, int>>>graph(100001);
int n, k;
int LCA(int a, int b)
{
	//1.두 노드의 깊이를 같게 놓아준다
	if (depth[a] < depth[b]) //항상 a가 더 깊도록 조정을 해줌
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int diff = depth[a] - depth[b];
	for (int i = 0, mask = 1; mask <= diff; i++, mask <<= 1)
	{
		if (mask & diff)a = parent[i][a];
	}
	//2.위로 가면서 최소공통조상(LCA)를 찾아낸다
	while (a != b)
	{
		int t_a = a;
		int t_b = b;
		for (int i = 0; i < 18; i++)
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
	//a,b의 LCA 는 a or b에 저장 되있음
	return a;
}
void bfs()
{
	//깊이를
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
				visited[it.first] = true;
				q.push(it.first);
				depth[it.first] = depth[cur] + 1;
				mintable[0][it.first] = min(mintable[0][it.first], it.second);
				maxtable[0][it.first] = max(maxtable[0][it.first], it.second);
				parent[0][it.first] = cur;
			}
		}
	}
}
void init()
{
	for (int i = 1; i < 18; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (parent[i][j] != 0)
			{
				mintable[i][j] = min(mintable[i - 1][j], mintable[i - 1][parent[i - 1][j]]);
				maxtable[i][j] = max(maxtable[i - 1][j], maxtable[i - 1][parent[i - 1][j]]);
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
	fill(&mintable[0][0], &mintable[17][n + 1], INF);
	bfs();//깊이와 부모 배열 초기화
	for (int i = 1; i < 18; i++) //LCA 희소배열 만들고
	{
		for (int j = 1; j <= n; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	init();
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int s, e;
		int MAX = 0;
		int MIN = INF;
		cin >> s >> e;
		int lcs_node = LCA(s, e);//최소 공통 조상을 찾아
		int first_diff = depth[e] - depth[lcs_node];
		int second_diff = depth[s] - depth[lcs_node];
		for (int j = 0, mask = 1; mask <= first_diff; mask <<= 1,j++)
		{
			if (mask & first_diff)
			{
				MAX = max(MAX, maxtable[j][e]);
				MIN = min(MIN, mintable[j][e]);
				e = parent[j][e];
			}
		}
		for (int j = 0, mask = 1; mask <= second_diff; mask <<= 1,j++)
		{
			if (mask & second_diff)
			{
				MAX = max(MAX, maxtable[j][s]);
				MIN = min(MIN, mintable[j][s]);
				s = parent[j][s];
			}
		}
		cout << MIN << " " << MAX << '\n';
	}
	return 0;
}