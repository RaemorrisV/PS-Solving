#include <iostream>
#include <vector>

using namespace std;
int n, ans;
vector<int>arr;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
	for (int i = n-1; i >= 1; i--)
	{
		if (arr[i] <= arr[i - 1])
		{
			ans += arr[i - 1] - arr[i] + 1;
			arr[i - 1] -= arr[i - 1] - arr[i] + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}