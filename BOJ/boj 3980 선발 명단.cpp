#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
int ability[12][12];
int ans = 0;
bool visited[12];
void dfs(int num, int sum)
{
	if (num == 12)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 11; i++)
	{
		if (ability[num][i] && visited[i] == false)
		{
			visited[i] = true;
			dfs(num + 1, sum + ability[num][i]);
			visited[i] = false;
		}
	}
}
void init()
{
	memset(ability, 0, sizeof(ability));
	memset(visited, 0, sizeof(visited));
	ans = 0;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		init();
		for (int i = 1; i <= 11; i++)
		{
			for (int j = 1; j <= 11; j++)
			{
				cin >> ability[i][j];
			}
		}
		for (int i = 1; i <= 11; i++)
		{
			if (ability[1][i])
			{
				visited[i] = true;
				dfs(2, ability[1][i]);
				visited[i] = false;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}