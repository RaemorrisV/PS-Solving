#include <iostream>
#include <vector>

using namespace std;

int n, m; //아이들의 수는 10억 까지
vector<int>color;
int MAX;
long long ans;
long long decision(int mid)
{
	long long total = 0;
	for (int i = 0; i < m; i++)
	{
		if (color[i] < mid)
		{
			total += 1;
		}
		else
		{
			total += color[i] / mid;
			if (color[i] % mid != 0)
			{
				total += 1;
			}
		}
	}
	return total;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		MAX = max(MAX, a);
		color.push_back(a);
	}
	int s = 1;
	int e = MAX;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (decision(mid) <= n)
		{
			e = mid - 1;
			ans = mid;
		}
		else
		{
			s = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}