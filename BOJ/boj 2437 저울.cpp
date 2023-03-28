#include <iostream>
#include <algorithm>

using namespace std;

int n;
int weight[1001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i];
	}
	sort(weight, weight + n + 1);
	int sum = 1;
	for (int i = 1; i <= n; i++)
	{
		if (sum < weight[i])break;
		sum += weight[i];
	}
	cout << sum << '\n';
	return 0;
}