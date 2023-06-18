#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, m;
vector<int>a;
vector<int>b;
int ans;
void init()
{
	ans = 0;
	a.clear();
	b.clear();
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> n >> m;
		init();
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			a.push_back(input);
		}
		for (int i = 0; i < m; i++)
		{
			int input;
			cin >> input;
			b.push_back(input);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int bidx = m - 1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (bidx == -1)break;
			if (a[i] > b[bidx])//먹을 수 있는 경우를 보자
			{
				ans += bidx + 1;
			}
			else //만약 먹을 수 가 없다면
			{
				while (1)
				{
					if (bidx == -1)break;
					if (a[i] > b[bidx])//먹을 수 있는 경우를 보자
					{
						ans += bidx + 1;
						break;
					}
					else
					{
						bidx--;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}