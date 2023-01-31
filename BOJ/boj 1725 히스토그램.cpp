#include <iostream>
#include <algorithm>

using namespace std;

int n;
int index[262144];
int arr[100001];
int offset = 1;
int max_idx;
int answer = 0;
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		if (arr[index[x * 2]] > arr[index[x * 2 + 1]])
		{
			index[x] = index[x * 2 + 1];
		}
		else
		{
			index[x] = index[x * 2];
		}
		x /= 2;
	}
}
void make_tree(int idx)
{
	int x = idx + offset - 1;
	index[x] = idx;
	update(x);
}
int query(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	int res = max_idx;
	while (start <= end)
	{
		if (start % 2 == 1)
		{
			if (arr[res] >= arr[index[start]])res = index[start];
			start++;
		}
		if (end % 2 == 0)
		{
			if (arr[res] >= arr[index[end]])res = index[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return res;
}
void ans(int start, int end)
{
	int h = query(start, end);
	int area = (end - start + 1) * arr[h];
	answer = max(answer, area);
	if (h + 1 <= end)//더 가능 한지?
	{
		ans(h + 1, end);
	}
	if (h - 1 >= start)
	{
		ans(start, h - 1);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (offset = 1; offset < n; offset *= 2);
	int MAX = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		MAX = max(arr[i], MAX);
		if (MAX == arr[i])
		{
			max_idx = i;
		}
	}
	fill(index, index + 262144, max_idx);
	for (int i = 1; i <= n; i++)
	{
		make_tree(i);
	}
	ans(1, n);
	cout << answer << '\n';
	return 0;
}