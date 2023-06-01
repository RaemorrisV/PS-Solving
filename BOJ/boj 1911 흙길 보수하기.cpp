#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
int ans;
vector<pair<int, int>>hole;
bool compare(pair<int, int>a, pair<int, int>b)
{
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		hole.push_back({ a,b });
	}
	sort(hole.begin(), hole.end(), compare);
	int cur = hole[n - 1].second;
	for (int i = n - 1; i >= 0; i--)
	{
		if (cur <= hole[i].first)continue;
		if (cur > hole[i].second)
		{
			cur = hole[i].second;
		}
		int m = (cur - hole[i].first) / l;
		if ((cur - hole[i].first) % l > 0)m++;
		ans += m;
		cur = cur - l * m;
	}
	cout << ans << '\n';
	return 0;
}