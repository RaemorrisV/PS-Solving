#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];
int ans = 2000000001;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n + 1);
	int s = 1;
	int e = 1;
	while (s <= e && e <= n)
	{
		//cout << arr[s] << " " << arr[e] << endl;
		if (arr[e] - arr[s] >= m)
		{
			ans = min(ans, arr[e] - arr[s]);
			s++;
		}
		else
		{
			e++;
		}
	}
	cout << ans << '\n';
	return 0;
}