#include <iostream>
#define MOD  1000000007

using namespace std;

int n, m, k;
int offset = 1;
long long indextree[2097152];
void update(int idx, int val)
{
	int x = idx;
	x /= 2;
	while (x > 0)
	{
		indextree[x] = (indextree[x * 2] % MOD * indextree[x * 2 + 1] % MOD) % MOD;
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	idx = idx + offset - 1;
	indextree[idx] = val;
	update(idx, val);
}
long long query(int start, int end)
{
	start += (offset - 1);
	end += (offset - 1);
	long long res = 1;
	while (start <= end)
	{
		if (start % 2 == 1)
		{
			res = (res % MOD * indextree[start] % MOD) % MOD;
			start++;
		}
		if (end % 2 == 0)
		{
			res = (res % MOD * indextree[end] % MOD) % MOD;
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
	cin >> n >> m >> k;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		make_tree(i + 1, input);
	}
	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			make_tree(b, c);
		}
		else if (a == 2)
		{
			cout << query(b,c) << "\n";
		}
	}
	return 0;
}