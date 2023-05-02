#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long n, sum;
vector<pair<int, int>>arr;
bool compare(pair<int, int>a, pair<int, int>b)
{
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back({ a,0 });
	}
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		arr[i].second = b;
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++)
	{
		sum += arr[i].first + i * arr[i].second;
	}
	cout << sum << '\n';
	return 0;
}