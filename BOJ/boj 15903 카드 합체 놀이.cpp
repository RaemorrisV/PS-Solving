#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long n, m, ans;
vector<long long>arr;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++)
	{
		long long temp = arr[0] + arr[1];
		arr[0] = temp;
		arr[1] = temp;
		sort(arr.begin(), arr.end());
	}
	for (int i = 0; i < n; i++)
	{
		ans += arr[i];
	}
	cout << ans << '\n';
	return 0;
}