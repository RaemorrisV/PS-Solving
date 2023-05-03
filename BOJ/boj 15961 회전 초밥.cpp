#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, d, k, c;
int ans = 0;
vector<int>arr;
int sum = 0;
unordered_map<int, int>counting;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		if (i < k)
		{
			if (counting[a] == 0)
			{
				sum++;
			}
			counting[a]++;
		}
	}
	if (counting[c] == 0)
	{
		sum++;
	}
	counting[c]++;
	ans = max(ans, sum);
	int sub = 0;
	int add = k - 1;
	for (int i = 1; i < n; i++)
	{
		if (add + 1 > n - 1)
		{
			add = add + 1 - n;
		}
		else add++;
		counting[arr[sub]] -= 1;
		if (counting[arr[sub]] == 0)sum -= 1;
		sub++;
		if (counting[arr[add]] == 0)sum += 1;
		counting[arr[add]]++;
		ans = max(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}