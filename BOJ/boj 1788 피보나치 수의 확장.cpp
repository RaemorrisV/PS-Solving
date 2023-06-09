#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[1000001];
int n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	if (n == 0)
	{
		cout << 0 << '\n' << 0 << '\n';
	}
	else
	{
		for (int i = 2; i <= abs(n); i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		}
		if (abs(n) % 2 == 0 && n < 0)//짝수고 음수라면
		{
			cout << -1 << '\n' << dp[abs(n)] << '\n';
		}
		else if (abs(n) % 2 == 0 && n > 0)//짝수고 양수라면
		{
			cout << 1 << '\n' << dp[n] << '\n';
		}
		else //홀수라면
		{
			cout << 1 << '\n' << dp[abs(n)] << '\n';
		}
	}
	return 0;
}