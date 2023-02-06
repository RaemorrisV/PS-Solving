#include <iostream>
#include <algorithm>

using namespace std;

int indextree[1048576];
pair<int, int> arr[500001];// 값 인덱스
int n, offset;
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
	cin >> n;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n + 1);
	for (int i = 1; i <= n; i++)
	{
		make_tree(arr[i].second, 1);
		ans += query(arr[i].second + 1, n);
	}
	cout << ans << '\n';
	return 0;
}