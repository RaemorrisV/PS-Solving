#include <iostream>

using namespace std;

int n, sum;
int arr[101];
int score[101];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 1)
		{
			score[i] += score[i - 1] + 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sum += score[i];
	}
	cout << sum << '\n';
	return 0;
}