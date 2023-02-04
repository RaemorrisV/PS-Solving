#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[1000];
bool compare(int a, int b)
{
	return a > b;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, compare);
	cout << arr[k - 1] << '\n';
	return 0;
}