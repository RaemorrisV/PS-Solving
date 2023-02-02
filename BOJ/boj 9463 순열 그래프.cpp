#include <iostream>
#include <cstring>

using namespace std;

int t, n;
int offset;
long long indextree[262144];
int map[100001];
long long ans = 0;
void init()
{
	memset(indextree, 0, sizeof(indextree));
	memset(map, 0, sizeof(map));
	ans = 0;
}
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = indextree[x * 2] + indextree[x * 2 + 1];
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	idx += offset - 1;
	indextree[idx] += val;
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
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		init();
		cin >> n;
		for (offset = 1; offset < n; offset *= 2);
		for (int i = 1; i <= n; i++)
		{
			int input;
			cin >> input;
			map[input] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			int input;
			cin >> input;
			if (map[input] != n)
			{
				ans += query(map[input] + 1, n);
			}
			make_tree(map[input], 1);
		}
		cout << ans << '\n';
	}
	return 0;
}