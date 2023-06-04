#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<pair<int, int>>info;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		info.push_back({ a,b });
	}
	for (int i = 0; i < n; i++)
	{
		ans += info[i].second % info[i].first;
	}
	cout << ans << "\n";
	return 0;
}