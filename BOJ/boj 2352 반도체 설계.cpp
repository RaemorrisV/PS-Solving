#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[40000];
vector<int>ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i == 0)ans.push_back(arr[i]);
		else if (ans.back() < arr[i])ans.push_back(arr[i]);
		else if (ans.back() >= arr[i])
		{
			int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[idx] = arr[i];
		}
	}
	cout << ans.size() << '\n';
	return 0;
}