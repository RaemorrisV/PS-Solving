#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int x, y, g;//x 는 현재 y는 기억하고 있는 몸무게
vector<int>ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> g;
	x = 2;
	y = 1;
	while (y < x)
	{
		int diff = (int)(pow(x, 2) - pow(y, 2));
		//cout << "디버그용 출력 " << diff << " " << x << " " << y << endl;
		if (diff < g)
		{
			x++;
		}
		else if (diff == g)
		{
			ans.push_back(x);
			y++;
		}
		else
		{
			y++;
		}
	}
	if (ans.empty())
	{
		cout << -1 << "\n";
	}
	else
	{
		sort(ans.begin(), ans.end());
		for (auto it : ans)
		{
			cout << it << "\n";
		}
	}
	return 0;
}