#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m, k;
long long indextree[2048];
int offset;
vector<int>city[1001];
long long ans;
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = indextree[2 * x] + indextree[2 * x + 1];
		x /= 2;
	}
}
void make_tree(int idx)
{
	idx += offset - 1;
	indextree[idx]++;
	update(idx);
}
long long query(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	long long res = 0;
	while (start <= end)
	{
		if (start % 2 == 1)res += indextree[start++];
		if (end % 2 == 0)res += indextree[end--];
		start /= 2;
		end /= 2;
	}
	return res;
}
void init()
{
	ans = 0;
	memset(indextree, 0, sizeof(indextree));
	for (int i = 1; i <= n; i++)
	{
		city[i].clear();
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m >> k;
		for (offset = 1; offset < m; offset *= 2);
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;// 동해 >> 서해
			city[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) //중복 까지 고려를 해줘야됨
		{
			for (int j = 0; j < city[i].size(); j++)
			{
				if (city[i][j] != m)
				{
					ans += query(city[i][j] + 1, m);
				}
			}
			for (int j = 0; j < city[i].size(); j++)
			{
				make_tree(city[i][j]);
			}
		}
		cout << "Test case " << tc << ": " << ans << '\n';
		init();
	}
	return 0;
}