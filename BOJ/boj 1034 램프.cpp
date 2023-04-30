#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k; //За ї­
string light[51];
int ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> light[i];
	}
	cin >> k;
	for (int i = 1; i <= n; i++)
	{
		int zero = 0;
		for (int j = 0; j < light[i].length(); j++)
		{
			if (light[i][j] == '0')zero++;
		}
		if (zero <= k && zero % 2 == k % 2)
		{
			int counting = 0;
			for (int j = 1; j <= n; j++)
			{
				if (light[i] == light[j])counting++;
			}
			ans = max(ans, counting);
		}
	}
	cout << ans << '\n';
	return 0;
}