#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<int>index;
bool check(int mid)
{
	int end = 0;
	for (int i = 0; i < index.size(); i++)
	{
		if (index[i] - mid <= end)
		{
			end = index[i] + mid;
		}
		else
		{
			return false;
		}
	}
	if(end>=n)return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int lo;
		cin >> lo;
		index.push_back(lo);
	}
	int s = 0;
	int e = n;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (check(mid))//µÇ¸é ÁÙ¿©ºÁ
		{
			ans = mid;
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}