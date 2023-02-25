#include <iostream>

using namespace std;

int n, m, offset;
int indextree[1048576];
void update(int idx)
{
	int  x = idx / 2;
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
int query(int k)
{
	int start = 1;
	while (start < offset)
	{
		if (indextree[start * 2] >= k)//왼쪽으로 갈 수 있음
		{
			start *= 2;
		}
		else //오른쪽으로 갈 수 있음
		{
			start *= 2;
			k -= indextree[start];
			start += 1;
		}
	}
	return start - offset + 1;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		make_tree(i, a);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			make_tree(b, c);
		}
		else
		{
			cin >> b;
			cout << query(b) << '\n';
		}
	}
	return 0;
}