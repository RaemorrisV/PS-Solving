#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int offset = 1;
int n;
int MAX = 0;
long long ans = 0;
unordered_map<int, int>machine;
long long indextree[1048576];
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
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = indextree[x * 2] + indextree[x * 2 + 1];
		x /= 2;
	}
}
void make_tree(int idx)
{
	idx += offset - 1;
	indextree[idx]++;
	update(idx);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (offset = 1; offset < n; offset *= 2);
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		machine[input] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		MAX = max(MAX, machine[input]);
		if (machine[input] < MAX)
		{
			ans += query(machine[input], MAX);
		}
		make_tree(machine[input]);
	}
	cout << ans << '\n';
	return 0;
}