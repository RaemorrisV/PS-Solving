#include <iostream>
#include <algorithm>

using namespace std;

int n, offset;
long long sumtree[262144];
int mintree[262144];
int arr[100002];
long long ans = 0;
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		sumtree[x] = sumtree[x * 2] + sumtree[x * 2 + 1];
		if (arr[mintree[x * 2]] < arr[mintree[x * 2 + 1]])
		{
			mintree[x] = mintree[x * 2];
		}
		else mintree[x] = mintree[x * 2 + 1];
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	idx += offset - 1;
	mintree[idx] = val;
	sumtree[idx] = arr[val];
	update(idx);
}
long long query(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	long long res = 0;
	while (start <= end)
	{
		if (start % 2 == 1)res += sumtree[start++];
		if (end % 2 == 0)res += sumtree[end--];
		start /= 2;
		end /= 2;
	}
	return res;
}
int minquery(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	int res = 100001;
	while (start <= end)
	{
		if (start % 2 == 1)
		{
			if (arr[mintree[start]] < arr[res])
			{
				res = mintree[start];
			}
			start++;
		}
		if (end % 2 == 0)
		{
			if (arr[mintree[end]] < arr[res])
			{
				res = mintree[end];
			}
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return res;
}
void dfs(int start, int end)
{
	int minvalue = minquery(start, end);
	long long sum = query(start, end);
	ans = max(ans, sum * arr[minvalue]);
	//종료 조건
	if (minvalue + 1 <= end)//왼쪽으로 갈 수 있음
	{
		dfs(minvalue + 1, end);
	}
	if (minvalue - 1 >= start)//오른쪽으로 갈 수 있음
	{
		dfs(start, minvalue - 1);
	}

}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	arr[100001] = 1000001;
	fill(mintree, mintree + 262144, 100001);
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		make_tree(i, i);
	}
	dfs(1, n);
	cout << ans << '\n';
	return 0;
}