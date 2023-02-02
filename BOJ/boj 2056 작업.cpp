#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];
int time[10001];
int indegree[10001];
int ans = 0;
vector<vector<int>>graph(10001);
int n;
void topological_sort()//여기서 dp를 수행함
{
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			dp[i] = time[i];
			ans = max(dp[i], ans);
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			indegree[it]--;
			dp[it] = max(dp[it], dp[cur] + time[it]);
			ans = max(dp[it], ans);
			if (indegree[it] == 0)q.push(it);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int cost, cnt;
		cin >> cost >> cnt;
		time[i] = cost;
		indegree[i] = cnt;
		for (int j = 0; j < cnt; j++)
		{
			int a;
			cin >> a;
			graph[a].push_back(i);
		}
	}
	topological_sort();
	cout << ans << '\n';
	return 0;
}