#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x, n;
vector<int>lego;
bool flag;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> x)
	{
		x *= 10000000;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			lego.push_back(input);
		}
		sort(lego.begin(), lego.end());
		int s = 0;
		int e = n - 1;
		while (s < e)
		{
			int sum = lego[s] + lego[e];
			if (sum >= x)
			{
				if (sum == x)
				{
					cout << "yes " << lego[s] << " " << lego[e] << '\n';
					flag = true;
					break;
				}
				e--;
			}
			else
			{
				s++;
			}
		}
		if (flag==false)cout << "danger" << '\n';
		flag = false;
		lego.clear();
	}
	return 0;
}