#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int t, n, offset;
long long ans;
int indextree[262144];
vector<pair<int, int>>coordinate;//xÁÂÇ¥ yÁÂÇ¥
unordered_map<int, int>match;
vector<int>y_value;
void init()
{
	coordinate.clear();
	memset(indextree, 0, sizeof(indextree));
	match.clear();
	y_value.clear();
	ans = 0;
}
bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.first == b.first)return a.second > b.second;
	return a.first < b.first;
}
void update(int idx)
{
	int x = idx / 2;
	while (x > 0)
	{
		indextree[x] = indextree[x * 2] + indextree[x * 2 + 1];
		x /= 2;
	}
}
void make_tree(int idx, int val)
{
	idx += offset - 1;
	indextree[idx] += val;
	update(idx);
}
int query(int start, int end)
{
	start += offset - 1;
	end += offset - 1;
	int res = 0;
	while (start <= end)
	{
		if (start % 2 == 1)res += indextree[start++];
		if (end % 2 == 0)res += indextree[end--];
		start /= 2;
		end /= 2;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		init();
		cin >> n;
		for (offset = 1; offset < n; offset *= 2);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			coordinate.push_back({ x,y });
			y_value.push_back(y);
		}
		sort(coordinate.begin(), coordinate.end(), compare);
		sort(y_value.begin(), y_value.end());
		int ind = 1;
		for (int i = 0; i < n; i++)
		{
			if (match[y_value[i]] == 0)
			{
				match[y_value[i]] = ind;
				ind++;
			}
		}
		//y indextree »ý¼º
		for (int i = 0; i < n; i++)
		{
			make_tree(match[y_value[i]], 1);
		}
		for (int i = 0; i < n; i++)
		{
			make_tree(match[coordinate[i].second], -1);
			ans += query(1, match[coordinate[i].second]);
		}
		cout << ans << '\n';
	}
	return 0;
}