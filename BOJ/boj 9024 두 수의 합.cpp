#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, k;
int arr[1000001];
int MIN = 2000000000;
int cnt = 0;
void init()
{
	cnt = 0;
	MIN = 2000000000;
	memset(arr, 0, sizeof(arr));
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i - 1];
		}
		sort(arr, arr + n);
		int s = 0;
		int e = n - 1;
		while (s < e)
		{
			int diff = abs((arr[e] + arr[s]) - k);
			if (MIN == diff)cnt++;
			else if (MIN > diff)cnt = 1;
			MIN = min(MIN, diff);
			int sum = arr[e] + arr[s];
			if (k <= sum)
			{
				e--;
			}
			else //k>sum
			{
				s++;
			}
		}
		cout << cnt << "\n";
		init();
	}
	return 0;
}