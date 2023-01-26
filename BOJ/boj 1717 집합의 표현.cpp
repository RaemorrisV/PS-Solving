#include <iostream>

using namespace std;

int n, m;
int disjoint_set[1000001];
void make_set()
{
	for (int i = 0; i <= n; i++)
	{
		disjoint_set[i] = i;
	}
}
int find_set(int a)
{
	if (disjoint_set[a] != a)
	{
		disjoint_set[a] = find_set(disjoint_set[a]);
	}
	return disjoint_set[a];
}
void union_set(int a, int b)
{
	int a_root = find_set(a);
	int b_root = find_set(b);
	disjoint_set[b_root] = a_root;
	find_set(b);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	make_set();
	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) //union
		{
			union_set(a, b);
		}
		else //
		{
			if (find_set(a) == find_set(b))cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
	return 0;
}