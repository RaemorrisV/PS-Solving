#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int>w;
int n, ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		w.push_back(a);
	}
	sort(w.begin(), w.end());
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, w[i] * (n - i));
	}
	cout << ans << "\n";
	return 0;
}