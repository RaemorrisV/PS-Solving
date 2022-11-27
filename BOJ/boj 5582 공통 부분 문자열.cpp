#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int dp[4001][4001];
string first_word;
string second_word;
int ans = -1;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> first_word >> second_word;
	for (int i = 1; i <= second_word.length(); i++)
	{
		for (int j = 1; j <= first_word.length(); j++)
		{
			if (second_word[i - 1] == first_word[j - 1])
			{
				dp[i][j] = 1;
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans << '\n';
	return 0;
}