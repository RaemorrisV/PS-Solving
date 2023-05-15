#include <iostream>

using namespace std;

int t;
int a, b;
int find_ans()
{
	if (a > b)
	{
		int temp = b;
		b = a;
		a = temp;
	}
	while (a != b)
	{
		if (a < b)
		{
			b /= 2;
		}
		else if (a > b)
		{
			a /= 2;
		}
	}
	return 10 * a;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> a >> b;
		int ans = find_ans();
		cout << ans << '\n';
	}
	return 0;
}