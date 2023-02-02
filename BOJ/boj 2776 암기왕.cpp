#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, m;
int arr[1000000];
void init()
{
	memset(arr, 0, sizeof(arr));
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		init();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int q;
			cin >> q;
			int idx = lower_bound(arr, arr + n, q) - arr;
			if (idx >= n || arr[idx] != q)cout << "0" << '\n';
			else cout << "1" << "\n";
		}
	}
	return 0;
}