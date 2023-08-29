#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, ans;
vector<pair<int, int>>problem;
int dp[10001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int l, t;
		cin >> l >> t;
		problem.push_back({t,l});
	}
	sort(problem.begin(), problem.end());
	for (int i = 0; i < problem.size(); i++)
	{
		int t = problem[i].first;//필요한 공부시간
		int l = problem[i].second;//중요도
		for (int j = n; j >= t; j--)
		{
			dp[j] = max(dp[j], dp[j - t] + l);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}