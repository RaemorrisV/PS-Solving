#include <iostream>

using namespace std;

int n, offset;
int indextree[262144];
int ans[100001];
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
int query(int input)
{
	int start = 1;
	while (start < offset)
	{
		if (indextree[start * 2] >= input) //왼쪽 자식으로 가는경우
		{
			start *= 2;
		}
		else //오른쪽 자식으로 가는 경우
		{
			input -= indextree[start * 2];
			start *= 2;
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
		make_tree(i, 1);
	}
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		int index = query(input + 1);
		make_tree(index, -1);
		ans[index] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}