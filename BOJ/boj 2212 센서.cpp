#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int>censor;
vector<int>diff;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		censor.push_back(a);
	}
	if (n <= k)
	{
		cout << 0 << '\n';
	}
	else
	{
		sort(censor.begin(), censor.end());
		for (int i = 1; i < censor.size(); i++)
		{
			diff.push_back(censor[i] - censor[i - 1]);
		}
		sort(diff.begin(), diff.end());
		int sum = 0;
		for (int i = 0; i < n - k; i++)
		{
			sum += diff[i];
		}
		cout << sum << "\n"; 
	}
	return 0;
}