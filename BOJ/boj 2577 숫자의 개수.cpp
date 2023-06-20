#include <iostream>
#include <string>

using namespace std;
int total = 1;
int ans[10];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 3; i++)
	{
		int a;
		cin >> a;
		total *= a;
	}
	string result = to_string(total);
	for (int i = 0; i < result.length(); i++)
	{
		ans[result[i] - '0']++;
	}
	for (auto it : ans)
	{
		cout << it << '\n';
	}
	return 0;
} 