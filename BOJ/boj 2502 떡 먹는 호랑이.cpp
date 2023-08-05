#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d, k;
pair<int,int> dp[31];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> d >> k;
	dp[1].first = 1;
	dp[1].second = 0;
	dp[2].first = 0;
	dp[2].second = 1;
	for (int i = 3; i <= d; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	for (int i = 1; i <= k; i++)
	{
		if ((k - dp[d].first * i) % dp[d].second == 0)
		{
			cout << i << '\n' << (k - dp[d].first * i) / dp[d].second << '\n';
			break;
		}
	}
	return 0;
}
