#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans;
vector<pair<int, int>>cow;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		cow.push_back({a,b});
	}
	sort(cow.begin(), cow.end());
	for (int i = 0; i < n; i++)
	{
		if (ans < cow[i].first)
		{
			ans = cow[i].first + cow[i].second;
		}
		else
		{
			ans += cow[i].second;
		}
	}
	cout << ans << "\n";
	return 0;
}