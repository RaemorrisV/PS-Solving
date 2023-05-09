#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int>arr;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == n)ans++;
	}
	cout << ans << '\n';
	return 0;
}