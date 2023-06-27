#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> negative;
vector<int> positive;
int ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input < 0)//음수라면
		{
			negative.push_back(input);
		}
		else positive.push_back(input);
	}
	sort(negative.begin(), negative.end());
	sort(positive.begin(), positive.end());
	if (negative.empty() || positive.empty())
	{
		if (positive.empty())
		{
			ans =abs(negative[0]);
			for (int i = m; i < negative.size(); i += m)
			{
				ans += abs(negative[i] * 2);
			}
		}
		else if (negative.empty())
		{
			ans = positive[positive.size()-1];
			for (int i = positive.size() - m - 1; i >= 0; i -= m)
			{
				if (i != 0 && i - m < 0)//음수라면
				{
					ans += positive[i] * 2;
				}
				else ans += positive[i] * 2;
			}
		}
	}
	else if (abs(negative[0]) <= abs(positive[positive.size() - 1]))
	{
		ans += abs(positive[positive.size() - 1]);
		for (int i = positive.size()-m-1; i >= 0; i -= m)
		{
			if (i!=0 && i - m < 0)//음수라면
			{
				ans += positive[i] * 2;
			}
			else ans += positive[i] * 2;
		}
		for (int i = 0; i < negative.size(); i += m)
		{
			ans += abs(negative[i] * 2);
		}
	}
	else if (abs(negative[0]) > abs(positive[positive.size() - 1]))
	{
		ans += abs(negative[0]);
		for (int i = m; i < negative.size(); i += m)
		{
			ans += abs(negative[i] * 2);
		}
		for (int i = positive.size()-1; i >= 0; i -= m)
		{
			if (i != 0 && i - m < 0)//음수라면
			{
				ans += positive[i] * 2;
			}
			else ans += positive[i] * 2;
		}
	}
	cout << ans << '\n';
	return 0;
}