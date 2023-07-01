#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int k, l;
unordered_map<string, int>q;
bool compare(pair<string, int>a, pair<string, int>b)
{
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> k >> l;
	for (int i = 1; i <= l; i++)
	{
		string input;
		cin >> input;
		//¾ø´Ù¸é
		if (q[input] == 0)
		{
			q[input] = i;
		}
		else if (q[input] < i)
		{
			q[input] = i;
		}
	}
	vector<pair<string, int>>ans(q.begin(), q.end());
	sort(ans.begin(), ans.end(), compare);
	k = min(k, (int)ans.size());
	for (int i = 0; i < k; i++)
	{
		cout << ans[i].first << "\n";
	}
	return 0;
}