#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int MIN = 1000333;
int sum;
bool valide(int val)
{
	if (val >= m && val <= n)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for (int i = 1; i <= 100; i++)
	{
		int value = pow(i, 2);
		if (valide(value))
		{
			MIN = min(MIN, value);
			sum += value;
		}
	}
	if (MIN == 1000333)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << sum << '\n';
		cout << MIN << '\n';
	}
	return 0;
}