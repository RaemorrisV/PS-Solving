#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<vector<int>>order(32001);
int indegree[32001];
vector<int>ans;
struct compare {
	bool operator()(int a, int b) {
		return a > b;
	}
};
void topological_sort()
{
	priority_queue<int, vector<int>, compare>pq;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)pq.push(i);
	}
	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		ans.push_back(cur);
		if (!order[cur].empty())
		{
			for (int i = 0; i < order[cur].size(); i++)
			{
				indegree[order[cur][i]] -= 1;
				if (indegree[order[cur][i]] == 0)
				{
					pq.push(order[cur][i]);
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		order[a].push_back(b);
		indegree[b] += 1;
	}
	topological_sort();
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}