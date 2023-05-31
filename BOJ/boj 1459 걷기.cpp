#include <iostream>
#include <algorithm>
using namespace std;

long long x, y, w, s;//За ї­
long long ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> x >> y >> w >> s;
	if (2 * w <= s)
	{
		ans = w * (x + y);
	}
	else
	{
		if (w >= s)
		{
			ans = min(x, y) * s + (max(x, y) - min(x, y)) / 2 * 2 * s + ((max(x, y) - min(x, y)) % 2) * w;
		}
		else //w<s
		{
			ans = min(x, y) * s + (max(x, y) - min(x, y)) * w;
		}
	}
	cout << ans << "\n";
	return 0;
}