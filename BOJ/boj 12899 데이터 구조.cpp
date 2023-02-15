#include <iostream>

using namespace std;

int indextree[4194304];
int n, offset, t, x;
void update(int idx)
{
	int y = idx / 2;
	while (y > 0)
	{
		indextree[y] = indextree[y * 2] + indextree[y * 2 + 1];
		y /= 2;
	}
}
void make_tree(int val, int idx)
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
		if (indextree[start * 2] >= k)//왼쪽 자식
		{
			start *= 2;
		}
		else// 오른쪽 자식
		{
			k -= indextree[start * 2];
			start *= 2;
			start += 1;
		}
	}
	return start - offset + 1;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (offset = 1; offset < 2000000; offset *= 2);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t >> x;
		if (t == 1) //추가하는 
		{
			make_tree(1, x);
		}
		else //삭제해야 수를 찾는 녀석
		{
			int ans = query(x);
			cout << ans << '\n';
			make_tree(-1, ans);
		}
	}
	return 0;
}