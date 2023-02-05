#include <iostream>

using namespace std;

int n, k, offset;
int first = 1;
int indextree[524288];
int arr[250001];
long long ans = 0;
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
int query()
{
	int start = 1;
	int cnt = (k + 1) / 2;
	while (start < offset)
	{
		if (indextree[start * 2] >= cnt)//  왼쪽 자식
		{
			start *= 2;
		}
		else
		{
			cnt -= indextree[start * 2];
			start = start * 2 + 1;
		}
	}
	return start - offset + 1;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (offset = 1; offset < 65536; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += 1;
		if (i < k)
		{
			make_tree(arr[i], 1);
		}
		else if (i == k)
		{
			make_tree(arr[i], 1);
			ans += (query() - 1);
		}
		else //k부터
		{
			make_tree(arr[i], 1);
			make_tree(arr[first], -1);
			first++;
			ans += (query() - 1);
		}
	}
	cout << ans << '\n';
	return 0;
}