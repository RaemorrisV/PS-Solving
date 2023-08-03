#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define MOD 10007
using namespace std;

int n, m, h;
int dp[51][1001];
int block[51][11];
string input;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> h;
	getline(cin, input);
	for (int i = 1; i <= n; i++)
	{
		getline(cin, input);
		stringstream ss(input);
		string num;
		int index = 1;
		while (getline(ss, num, ' '))
		{
			int value = stoi(num);
			block[i][index] = value;
			if (value <= h)dp[i][value] = 1;
			index++;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			if (dp[i - 1][j] != 0)
			{
				for (int z = 1; z <= m; z++)
				{
					if (block[i][z] != 0 && block[i][z] + j <= h)
					{
						dp[i][block[i][z] + j] = (dp[i][block[i][z] + j] + dp[i - 1][j]) % MOD;
					}
				}
			}
		}
	}
	cout << dp[n][h] << '\n';
	return 0;
}
