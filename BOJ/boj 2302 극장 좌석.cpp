#include <iostream>

using namespace std;

int dp[41];
int n, m;
bool vip[41];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int input;
		cin >> input;
		vip[input] = true;
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (vip[i])
		{
			dp[i] = dp[i - 1];
		}
		else if (vip[i - 1])
		{
			dp[i] = dp[i - 1];
		}
		else  // 교환이 가능 하다고 생각함
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	*/
	cout << dp[n] << '\n';
	return 0;
}