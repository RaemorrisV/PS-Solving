#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, t;
vector<vector<int>>graph(501);
int build_time[501];
int indegree[501];
int ans[501];
void topological_sort()
{
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			ans[i] = build_time[i];
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			indegree[it]--;
			ans[it] = max(ans[it], ans[cur]);
			if (indegree[it] == 0)
			{
				ans[it] += build_time[it];
				q.push(it);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		build_time[i + 1] = t;
		while (1)
		{
			int a;
			cin >> a;
			if (a == -1)
			{
				break;
			}
			else
			{
				graph[a].push_back(i + 1);
				indegree[i + 1]++;
			}
		}
	}
	topological_sort();
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}