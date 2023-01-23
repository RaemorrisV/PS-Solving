#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int indextree[262144];
int offset = 1;
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = min(indextree[2 * x], indextree[2 * x + 1]);
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
	int res = 2e9;
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
	cin >> n;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i < 262144; i++)
	{
		indextree[i] = 2e9;
	}
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		make_tree(i,input);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)//update
		{
			cin >> b >> c;
			make_tree(b, c);
		}
		else //query
		{
			cin >> b >> c;
			cout << query(b, c) << '\n';
		}
	}
	return 0;
}