#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n;
int graph[100001];
bool visited[100001];
bool cir[100001];
int ans;
bool flag;
int c_start = 100001;
void init()
{
	memset(cir, 0, sizeof(cir));
	c_start = 100001;
	ans = 0;
}
void dfs(int start)
{
	//사이클이 형성 되었다는 뜻
	if (visited[graph[start]] && cir[graph[start]] == false)//만났을때
	{
		c_start = graph[start];
		cir[start] = true;
		flag = true;
		if (c_start == start)flag = false;
		ans++;
		return;
	}
	if (visited[graph[start]] == false && cir[graph[start]] == false)
	{
		visited[graph[start]] = true;
		dfs(graph[start]);
		cir[start] = true;
		if (flag)ans++;
		if (start == c_start)
		{
			flag = false;
		}
		visited[graph[start]] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> graph[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (cir[i] == false)
			{
				visited[i] = true;
				dfs(i);
				visited[i] = false;
			}
			flag = false;
		}
		cout << n - ans << "\n";
		init();
	}
	return 0;
}