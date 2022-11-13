#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
bool visited[100001];
vector<vector<int>>graph(100001);
vector<int>want;
int idx = 1;
void dfs(int s)
{
	visited[s] = true;
	unordered_map<int, bool>check;
	for (auto it : graph[s])
	{
		if (visited[it] == false)
		{
			check[it] = true;
		}
	}
	for (int i = 0; i < check.size(); i++)
	{
		if (check[want[idx]] == true)
		{
			int temp = want[idx];
			idx++;
			dfs(temp);
		}
		else if (check[want[idx]] == false)
		{
			cout << "0" << '\n';
			exit(0);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	want.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> want[i];
	}
	if (want[0] != 1)
	{
		cout << "0" << '\n';
		exit(0);
	}
	dfs(1);
	cout << "1" << '\n';
	return 0;
}