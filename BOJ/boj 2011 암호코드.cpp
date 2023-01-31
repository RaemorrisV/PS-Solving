#include <iostream>
#include <string>
#define MOD 1000000

using namespace std;

int dp[5001];
string input;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> input;
	dp[0] = 1;
	dp[1] = 1;
	if (input[0] == '0')
	{
		cout << "0" << '\n';
		exit(0);
	}
	for (int i = 1; i < input.length(); i++)
	{
		if (input[i] > '0' && input[i + 1] != '0')
		{
			dp[i + 1] += dp[i];
		}
		if (input[i] == '0' && input[i + 1] == '0')
		{
			cout << "0" << '\n';
			exit(0);
		}
		string temp = input.substr(i - 1, 2);
		if (stoi(temp) <= 26 && stoi(temp) >= 10)dp[i + 1] += dp[i - 1];
		dp[i + 1] %= 1000000;
	}
	cout << dp[input.length()] << '\n';
	return 0;
}