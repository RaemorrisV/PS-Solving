#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int MAX = 0;
int dp[1001];
vector<int>arr(1001);
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	MAX = arr[1];
	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j] + arr[i], dp[i]);
				MAX = max(dp[i], MAX);
			}
		}
	}
	cout << MAX << endl;
	return 0;
}