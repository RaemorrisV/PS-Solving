#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int maxtree[270000];
int mintree[270000];
int offset = 1;
void update(int idx)
{
	int x = offset + idx - 1;
	x /= 2;
	while (x > 0)
	{
		maxtree[x] = max(maxtree[x * 2], maxtree[x * 2 + 1]);
		mintree[x] = min(mintree[x * 2], mintree[x * 2 + 1]);
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	maxtree[offset + idx - 1] = val;
	mintree[offset + idx - 1] = val;
	update(idx);
}
void find(int start, int end)
{
	int MAX = 0;
	int MIN = INT_MAX;
	start = start + offset - 1;
	end = end + offset - 1;
	while (start<=end)
	{
		if (start % 2 == 1)//홀수
		{
			MAX = max(MAX, maxtree[start]);
			MIN = min(MIN, mintree[start]);
			start++;
		}
		if (end % 2 == 0)//짝수
		{
			MAX = max(MAX, maxtree[end]);
			MIN = min(MIN, mintree[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}
	cout << MIN << " " << MAX << '\n';
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	fill(mintree, mintree + 270000, INT_MAX);
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		make_tree(i, input);
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		find(a, b);
	}
	return 0;
}