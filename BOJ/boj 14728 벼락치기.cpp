#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, t, ans;
vector<pair<int, int>>problem;
int dp[10001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		int k, s;
		cin >> k >> s;
		problem.push_back({ k,s });
	}
	sort(problem.begin(), problem.end());
	for (int i = 0; i < problem.size(); i++)
	{
		int k = problem[i].first;
		int s = problem[i].second;

		for (int j = t; j >= k; j--) 
		{
			dp[j] = max(dp[j], dp[j - k] + s);
		}
	}
	cout << dp[t] << "\n";
	return 0;
}