#include <iostream>

using namespace std;

int n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = n - i; j >= 1; j--)
		{
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}
	for (int i = n-1; i >= 1; i--)
	{
		for (int j = i; j <= n-1; j++) //1 2 3 4
		{
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}
	return 0;
}