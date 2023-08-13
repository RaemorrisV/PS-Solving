#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;

int n, k, ans = INF;
vector<vector<pair<int, int>>>graph(11);
int dis[11][11];
bool visited[11];
void init()
{
	fill(&dis[0][0], &dis[10][11], INF);
}
void dfs(int start, int depth, int totalSum)
{
	if (depth == n)
	{
		ans = min(ans, totalSum);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			dfs(i, depth + 1, totalSum + dis[start][i]);
			visited[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	init();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dis[i][j];
		}
	}
	//플로이드 워셜
	for (int z = 0; z < n; z++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dis[i][z] + dis[z][j] < dis[i][j])
				{
					dis[i][j] = dis[i][z] + dis[z][j];
				}
			}
		}
	}
	visited[k] = true;
	dfs(k, 1, 0);
	cout << ans << '\n';
	return 0;
}