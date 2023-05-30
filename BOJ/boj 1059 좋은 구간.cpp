#include <iostream>
#include <algorithm>
using namespace std;

int L, n, s, e, ans;
int arr[50];
bool find_num(int first, int second)
{
	for (int i = first; i <= second; i++)
	{
		if (binary_search(arr, arr + L, i))return true;
	}
	return false;
}
; int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + L);
	cin >> n;
	for (int i = 1; i <= arr[L - 1]; i++)
	{
		for (int j = i+1; j <= arr[L - 1]; j++)
		{
			if (i > n || j < n)
			{
				continue;
			}
			if (find_num(i, j) == false)
			{
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}