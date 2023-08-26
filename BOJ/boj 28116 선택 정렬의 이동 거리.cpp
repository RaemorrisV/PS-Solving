#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int n;
int ans[500001];
int arr[500001];
vector<pair<int, int>>info;
unordered_map<int, int>check;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
		check[a] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int value = i;
		int index = check[i];
		ans[arr[i]] += abs(index - i);
		ans[value] += abs(index - i);
		int temp = arr[i];
		arr[i] = i;
		arr[index] = temp;
		check[temp] = index;

	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}