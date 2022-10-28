#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	set<int>coordinate;
	vector<int>tt;
	map<int, int>temp;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		coordinate.insert(num);
		tt.push_back(num);
	}
	for (auto iter = coordinate.begin(); iter!= coordinate.end(); iter++)
	{
		temp.insert(pair<int, int>(*iter, cnt));//key value
		cnt++;
	}
	for (int i = 0; i < tt.size(); i++)
	{
		cout << temp[tt[i]] << " ";
	}
	return 0;
}