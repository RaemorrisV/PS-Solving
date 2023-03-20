#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
bool broken[9];
struct egg {
	int dura;
	int weight;
};
egg arr[9];
void dfs(int idx)
{
	if (idx == n + 1)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (broken[i])cnt++;
		}
		ans = max(ans, cnt);
		return;
	}
	if (!broken[idx])
	{
		int broken_cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (broken[i] && i != idx)broken_cnt++;
		}
		if (broken_cnt == n - 1)
		{
			dfs(idx + 1);
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (!broken[i] && i != idx)
				{
					arr[idx].dura -= arr[i].weight;
					arr[i].dura -= arr[idx].weight;
					if (arr[idx].dura <= 0)broken[idx] = true;
					if (arr[i].dura <= 0)broken[i] = true;
					dfs(idx + 1);
					arr[idx].dura += arr[i].weight;
					arr[i].dura += arr[idx].weight;
					if (arr[idx].dura > 0)broken[idx] = false;
					if (arr[i].dura > 0)broken[i] = false;
				}
			}
		}
	}
	else
	{
		dfs(idx + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].dura >> arr[i].weight;
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}