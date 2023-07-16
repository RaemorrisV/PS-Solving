#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int bitmap[182][182];
int ans[182][182];
vector<pair<int, int>>q;
int bfs(int r, int c)
{
	int min_value = 1000000000;
	for (int i = 0; i < q.size(); i++)
	{
		min_value = min(min_value, abs(r - q[i].first) + abs(c - q[i].second));
	}
	return min_value;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			bitmap[i][j] = input[j] - '0';
			if (bitmap[i][j] == 1)q.push_back({i,j});
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (bitmap[i][j] == 0)
			{
				ans[i][j]=bfs(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}