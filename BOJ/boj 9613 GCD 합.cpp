#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

long long t, n, sum;
int arr[101];
int GCD(int a, int b)
{
	while (a != 0)
	{
		int temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}
void init()
{
	memset(arr, 0, sizeof(arr));
	sum = 0;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> n;
		init();
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		sort(arr+1, arr + n+1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				sum += GCD(arr[i], arr[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}