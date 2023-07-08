#include <iostream>

int q;
int dp[26][200000];
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	string input;
	cin >> input;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < input.length(); j++)
		{
			if (j != 0)
			{
				if (input[j] - 'a' == i)
				{
					dp[i][j] += (dp[i][j - 1] + 1);
				}
				else dp[i][j] += dp[i][j - 1];
			}
			else
			{
				if (input[j] - 'a' == i)
				{
					dp[i][j] = 1;
				}
			}
		}
	}
	cin >> q;
	char a;
	int l, s;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> l >> s;
		cout << dp[a - 'a'][s] - dp[a - 'a'][l] + ((input[l]==a) ? 1 : 0 )<< '\n';
	}

	return 0;
}