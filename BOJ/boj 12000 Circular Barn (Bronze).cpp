#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> cow;
int ans = 1000000000;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int cowNum;
		cin >> cowNum;
		cow.push_back(cowNum);
	}
	for (int i = 0; i < n; i++)
	{
		int midValue = 0;
		int moveCount = 1;
		for (int j = i + 1; j < i + n; j++)
		{
			midValue += cow[j % n] * moveCount++;
		}
		ans = min(ans, midValue);
	}
	cout << ans << "\n";
	return 0;
}
