#include <iostream>

using namespace std;

int n, m;
int offset = 1;
long long indextree[2097152];
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
	cin >> n >> m;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 0; i < m; i++)
	{
		int a, b, c; 
		cin >> a;
		if (a == 0) //sum 함수를 사용함
		{
			cin >> b >> c;
			if (b > c)
			{
				cout << query(c, b) << '\n';
			}
			else
			{
				cout << query(b, c) << '\n';
			}
		}
		else //수정함수를 사용함
		{
			cin >> b >> c;
			make_tree(b,c);
		}
	}
	return 0;
}