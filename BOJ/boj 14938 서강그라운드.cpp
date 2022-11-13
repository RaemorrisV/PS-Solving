#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int n, m, r;
int total_length[101];
int sum = 0;
int MAX = -1;
vector<vector<pair<int, int>>>graph(101);
vector<int>item_cnt(101);
void bfs(int s)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ 0,s });
	total_length[s] = 0;
	while (!q.empty())
	{
		int cur = q.top().second;
		q.pop();
		for (auto it : graph[cur])
		{
			if (total_length[cur] + it.second <= m)
			{
				if (total_length[it.first] > total_length[cur] + it.second)
				{
					total_length[it.first] = total_length[cur] + it.second;
					q.push({ total_length[it.first],it.first });
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> item_cnt[i];
	}
	for (int i = 0; i < r; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].push_back({ e,c });
		graph[e].push_back({ s,c });
	}
	for (int i = 1; i <= n; i++)
	{
		fill(total_length, total_length + n + 1, INT_MAX);
		bfs(i);
		for (int j = 1; j <= n; j++)
		{
			if (total_length[j] <= m)
			{
				sum += item_cnt[j];
			}
		}
		MAX = max(MAX, sum);
		sum = 0;
	}
	cout << MAX << '\n';
	return 0;
}