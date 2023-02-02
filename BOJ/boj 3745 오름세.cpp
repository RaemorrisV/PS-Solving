#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>ans;
void init()
{
	ans.clear();
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> n)
	{
		init();
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (i == 0)ans.push_back(a);
			else
			{
				if (ans.back() < a)
				{
					ans.push_back(a);
				}
				else
				{
					int idx = lower_bound(ans.begin(), ans.end(), a) - ans.begin();
					ans[idx] = a;
				}
			}
		}
		cout << ans.size() << "\n";
	}
	return 0;
}