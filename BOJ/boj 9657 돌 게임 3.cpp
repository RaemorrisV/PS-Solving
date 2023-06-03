#include <iostream>

using namespace std;
int n;
int dp[1001]; //1이 상근이가 이긴다고 가정 0이 찬영이가 이긴다고 가정해보자
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	dp[1] = 1;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= n; i++)
	{
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)//찬영이가 이기는 결과가 하나라도 있으면
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}
	if (dp[n] == 1)
	{
		cout << "SK" << '\n';
	}
	else
	{
		cout << "CY" << '\n';
	}
	return 0;
}