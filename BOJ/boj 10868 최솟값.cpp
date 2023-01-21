#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int offset = 1;
int indextree[262144];
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = min(indextree[x * 2], indextree[x * 2 + 1]);
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	idx += offset - 1;
	indextree[idx] = val;
	update(idx);
}
int query(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	int res = 1000000001;
	while (start <= end)
	{
		if (start % 2 == 1)
		{
			res = min(res, indextree[start]);
			start++;
		}
		if (end % 2 == 0)
		{
			res = min(res, indextree[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		make_tree(i, a);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << query(a, b) << '\n';
	}
	return 0;
}