#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int>arr;
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
	int f = 0;
	int s = n - 1;
	while (f < s)
	{
		int sum = arr[f] + arr[s];
		if (sum > m)
		{
			s--;
		}
		else if (sum == m)
		{
			ans++;
			s--;
		}
		else
		{
			f++;
		}
	}
	cout << ans << '\n';
	return 0;
}