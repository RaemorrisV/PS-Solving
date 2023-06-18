#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>>arr;
int last_t;
int ans = 1;
priority_queue< int, vector<int>, greater<int> > pq;
bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.first == b.first)return a.second < b.second;
	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end(),compare);
	pq.push(arr[0].second);
	for (int i = 1; i < n; i++)
	{
		if (pq.top() > arr[i].first)
		{
			ans++;
			pq.push(arr[i].second);
		}
		else
		{
			pq.pop();
			pq.push(arr[i].second);
		}
	}
	cout << ans << '\n';
	return 0;
}