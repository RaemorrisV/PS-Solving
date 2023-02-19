#include <iostream>

using namespace std;

int indextree[262144];
int n, k, offset;
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
int query(int order)
{
	int start = 1;
	while (start < offset)
	{
		if (indextree[start * 2] >= order)//왼쪽 자식으로 가는 경우
		{
			start *= 2;
		}
		else //오른쪽 자식으로 가는 경우
		{
			order -= indextree[start * 2];
			start *= 2;
			start += 1;
		}
	}
	return start - offset + 1;
}
int query2(int start, int end)
{
	int res = 0;
	start += offset - 1;
	end += offset - 1;
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
	cin >> n >> k;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		make_tree(i, 1);
	}
	cout << "<";
	int index = 1;
	int size = n;
	for (int i = 1; i <= n; i++)
	{
		index = (index + k - 1) % size;
		if (index == 0)index = size;
		if (i == n)cout << query(index);
		else cout << query(index) << ", ";
		size--;
		make_tree(query(index), -1);
	}
	cout << ">" << '\n';
	return 0;
}