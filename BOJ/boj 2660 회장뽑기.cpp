#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<vector<int>>graph(51);
vector<pair<int,int>>num_friend;
vector<int>ans;
bool visited[51];
int dis[51];
int depth = 0;
bool compare(pair<int, int>a, pair<int, int>b)
{
	return a.second < b.second;
}
void bfs(int can)
{
	queue<int>q;
	q.push(can);
	visited[can] = true;
	depth = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto it : graph[cur])
		{
			if (visited[it] == false)
			{
				q.push(it);
				dis[it] = dis[cur] + 1;
				depth = max(dis[it], depth);
				visited[it] = true;
			}
		}
	}
	num_friend.push_back({ can,depth });
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (1)
	{
		int f, s;
		cin >> f >> s;
		if (f == -1 && s == -1)break;
		graph[f].push_back(s);
		graph[s].push_back(f);
	}
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
		memset(visited, 0, sizeof(visited));
		memset(dis, 0, sizeof(dis));
	}
	sort(num_friend.begin(), num_friend.end(),compare);
	int MIN = num_friend[0].second;
	for (int i = 0; i < num_friend.size(); i++)
	{
		if (num_friend[i].second == MIN)
		{
			ans.push_back(num_friend[i].first);
		}
	}
	sort(ans.begin(), ans.end());
	cout << MIN << " " << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}