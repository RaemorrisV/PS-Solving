#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
vector<pair<string, int>>character;
vector<int>bb; 
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		int in;
		cin >> str >> in;
		character.push_back({ str,in });
		bb.push_back(in);
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		int idx = lower_bound(bb.begin(), bb.end(), a ) - bb.begin();
		cout << character[idx].first << '\n';
	}
	return 0;
}