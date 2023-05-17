#include <iostream>
#include <algorithm>
using namespace std;

int n;
int straw[1000000];
int ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> straw[i];
	}
	sort(straw, straw + n);
	for (int i = n - 1; i >= 2; i--)
	{
		int max = straw[i];
		int first = straw[i - 2];
		int second = straw[i - 1];
		if (max < first + second)
		{
			ans = max + first + second;
			break;
		}
	}
	if (ans == 0)
	{
		cout << -1 << '\n';
	}
	else cout << ans << '\n';
	return 0;
}