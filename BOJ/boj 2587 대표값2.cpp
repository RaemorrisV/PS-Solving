#include <iostream>
#include <algorithm>

using namespace std;

int arr[5];
int sum;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 5);
	cout << sum / 5 << '\n';
	cout << arr[2] << '\n';
	return 0;
}