#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int n, c;
unordered_map<int, int>fre;
unordered_map<int, int>idx;
vector<int>info;
bool compare(int a, int b)
{
	if (fre[a] == fre[b])return idx[a] < idx[b];
	return fre[a] > fre[b];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		fre[a]++;
		if (idx[a] == 0)idx[a] = i;
		info.push_back(a);
	}
	sort(info.begin(), info.end(), compare);
	for (int i = 0; i < info.size(); i++)
	{
		cout << info[i] << " ";
	}
	cout << '\n';
	return 0;
}