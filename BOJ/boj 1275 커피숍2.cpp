#include <iostream>

using namespace std;

int n, q;
long long indextree[262144];
int offset = 1;
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
	indextree[idx] = val;
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
	cin >> n >> q;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		make_tree(i, input);
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)
		{
			cout << query(y, x) << '\n';
		}
		else
		{
			cout << query(x, y) << '\n';
		}
		make_tree(a, b);
	}
	return 0;
}