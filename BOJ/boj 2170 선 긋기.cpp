#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)return a.second < b.second;
	return a.first < b.first;
}
vector<pair<int, int>>arr;
int n, ans, s, e;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y; //항상 y가 크게 만들어 줘야지
		if (x > y)
		{
			int temp = x;
			x = y;
			y = temp;
		}
		arr.push_back({ x,y });
	}
	sort(arr.begin(), arr.end(), compare);
	s = arr[0].first;
	e = arr[0].second;
	for (int i = 1; i < n; i++)
	{
		//cout<<"for check " << s << " " << e << endl;
		if (arr[i].first <= e) //계속해서 나갈 수 있을때
		{
			e = max(e, arr[i].second);
		}
		else
		{
			ans += e - s;
			s = arr[i].first;
			e = arr[i].second;
		}
	}
	ans += e - s;
	cout << ans << "\n";
	return 0;
}