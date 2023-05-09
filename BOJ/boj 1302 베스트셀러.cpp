#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, int>map;
bool compare(pair<string, int>a, pair<string, int>b)
{
	if(a.second != b.second)return a.second > b.second;
	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		map[input]++;
	}
	vector<pair<string, int>>ans(map.begin(), map.end());
	sort(ans.begin(), ans.end(),compare);
	/*
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << '\n';
	}
	*/
	cout << ans[0].first << '\n';
	return 0;
}