#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool flag;
int checking, sum;
vector<int>arr;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 7; i++)
	{
		int a;
		cin >> a;
		if (a % 2 == 1)checking++;
		arr.push_back(a);
	}
	if (checking == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		sort(arr.begin(), arr.end());
		int MIN = 0;
		for (auto it : arr)
		{
			if (it % 2 == 1)
			{
				MIN = it;
				break;
			}
		}
		for (auto it : arr)
		{
			if (it % 2 == 1)sum += it;
		}
		cout << sum << '\n';
		cout << MIN << '\n';
	}
	return 0;
}