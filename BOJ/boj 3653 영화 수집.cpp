#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, n, m;
int indextree[524288];
int idx[100001];
int offset;
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
int query(int start, int end)
{ 
	start += offset - 1;
	end += offset - 1;
	int res = 0;
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
	memset(indextree, 0, sizeof(indextree));
	memset(idx, 0, sizeof(idx));
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		init();
		cin >> n >> m;
		for (offset = 1; offset < n + m; offset *= 2);
		for (int i = 1; i <= n; i++)
		{
			make_tree(i + m, 1);
			idx[i] = i + m;
		}
		int s = m;
		for (int i = 1; i <= m; i++)
		{
			int input;
			cin >> input;
			cout << query(1, idx[input] - 1) << " ";
			make_tree(idx[input], -1);
			idx[input] = s;
			make_tree(idx[input], 1);
			s--;
		}
		cout << '\n';
	}
	return 0;
}