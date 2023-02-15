#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
int indegree[1001];
int s, e;
vector<vector<int>>graph(1001);
vector<int>ans;
void topological_sort()
{
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		ans.push_back(cur);
		q.pop();
		for (auto it : graph[cur])
		{
			indegree[it]--;
			if (indegree[it] == 0)q.push(it);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int input;
			cin >> input;
			if (j == 0)s = input;
			else
			{
				indegree[input]++;
				graph[s].push_back(input);
				s = input;
			}
		}
	}
	topological_sort();
	if (ans.size() != n)cout << "0" << '\n';
	else
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}
	return 0;
}