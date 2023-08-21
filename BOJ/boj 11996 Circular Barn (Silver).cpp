#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, ans;
int waitCow[1000];
int dis[1000];
vector<int>noLine;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> waitCow[i];
		if (waitCow[i] == 0)noLine.push_back(i);
	}
	sort(noLine.begin(), noLine.end());
	while (!noLine.empty())
	{
		int index = noLine[noLine.size() - 1];
		while (1)
		{
			if (waitCow[index] != 0)
			{
				if (index > noLine[noLine.size() - 1])
				{
					noLine[noLine.size() - 1] += n;
					dis[noLine[noLine.size() - 1] - n] += (dis[index] + (noLine[noLine.size() - 1] - index));
					waitCow[noLine[noLine.size() - 1] - n]++;
				}
				else
				{
					dis[noLine[noLine.size() - 1]] += (dis[index] + (noLine[noLine.size() - 1] - index));
					waitCow[noLine[noLine.size() - 1]]++;
				}
				waitCow[index]--;
				dis[index] = 0;
				if (waitCow[index] == 0)
				{
					noLine.push_back(index);
					sort(noLine.begin(), noLine.end());
				}
				noLine.pop_back();
				break;
			}
			if (index == 0)index = n - 1;
			else index--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		ans += dis[i] * dis[i];
	}
	cout << ans << '\n';
	return 0;
}