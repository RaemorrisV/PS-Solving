#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int ans = -10000005;
int sum[100001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		sum[i] = sum[i - 1] + input;
		if (i >= k)
		{
			int value = sum[i] - sum[i - k];
			ans = max(ans, value);
		}
	}
	cout << ans << "\n";
	return 0;
}