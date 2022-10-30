#include <iostream>

using namespace std;
int n, v;
int arr[100];
int ans = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> v;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == v)
		{
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}