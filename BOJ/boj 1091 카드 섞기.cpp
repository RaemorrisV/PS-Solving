#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, ans;
vector<pair<int, int>>first;
vector<pair<int, int>>temp;
vector<int>p;
vector<int>s;
unordered_map<int, int>mapping;
bool flag;
void simulation()
{
	while (1)
	{
		bool isFind = true;
		for (int i = 0; i < n; i++)
		{
			if (p[i] != mapping[i] % 3)
			{
				isFind = false;
				break;
			}
		}
		if (isFind)break;
		vector<pair<int, int>>temp2 = temp;
		unordered_map<int, int>temp3 = mapping;
		for (int i = 0; i < s.size(); i++)
		{
			temp[s[i]].first = temp2[i].first;
			temp[s[i]].second = temp2[i].second;
			mapping[temp2[i].first] = s[i];
		}
		ans++;
		if (first == temp)
		{
			flag = true;
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		p.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		s.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		mapping[i] = i;
		first.push_back({ i, i % 3 });
		temp.push_back({ i, i % 3 });
	}
	simulation();
	if (flag)cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}