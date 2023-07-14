#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>height;
int ans[1000];
int result = 2000000000;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		height.push_back(input);
	}
	for (int i = 0; i <= 83; i++)
	{
		int tempcost = 0;
		for (int j = 0; j < n; j++)
		{
			if (height[j] < i)
			{
				tempcost += (i - height[j]) * (i - height[j]);
			}
			else if (height[j] > i + 17)
			{
				tempcost += (height[j] - (i + 17)) * (height[j] - (i + 17));
			}
		}
		result = min(tempcost, result);
	}
	cout << result << '\n';
	return 0;
}