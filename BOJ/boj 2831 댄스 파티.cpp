#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans;
vector<int>up_man;
vector<int>down_man;
vector<int>up_girl;
vector<int>down_girl;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		if (height > 0)up_man.push_back(height);
		else down_man.push_back(-1 * height);
	}
	sort(up_man.begin(), up_man.end());
	sort(down_man.begin(), down_man.end());
	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		if (height > 0)up_girl.push_back(height);
		else down_girl.push_back(-1 * height);
	}
	sort(up_girl.begin(), up_girl.end());
	sort(down_girl.begin(), down_girl.end());
	int girlIndex = 0;
	int boyIndex = 0;
	while (girlIndex < up_girl.size() && boyIndex < down_man.size())
	{
		if (up_girl[girlIndex] < down_man[boyIndex])
		{
			ans++;
			girlIndex++;
			boyIndex++;
		}
		else
		{
			boyIndex++;
		}
	}
	girlIndex = 0;
	boyIndex = 0;
	while (girlIndex < down_girl.size() && boyIndex < up_man.size())
	{
		if (down_girl[girlIndex] > up_man[boyIndex])
		{
			ans++;
			girlIndex++;
			boyIndex++;
		}
		else
		{
			girlIndex++;
		}
	}
	cout << ans << '\n';
	return 0;
}