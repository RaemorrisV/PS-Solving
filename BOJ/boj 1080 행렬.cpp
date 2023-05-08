#include <iostream>

using namespace std;

int n, m, ans; //За ї­
char A[51][51];
char B[51][51];
bool flag;
void simulation(int r, int c)
{
	for (int i = r; i <= r + 2; i++)
	{
		for (int j = c; j <= c + 2; j++)
		{
			if (A[i][j] == '1')A[i][j] = '0';
			else A[i][j] = '1';
	   }
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++)
		{
			A[i][j] = input[j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++)
		{
			B[i][j] = input[j-1];
		}
	}
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = 1; j <= m - 2; j++)
		{
			if (A[i][j] != B[i][j])
			{
				ans++;
				simulation(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i][j] != B[i][j])flag = true;
		}
	}
	if (flag)cout << "-1" << '\n';
	else cout << ans << '\n';
	return 0;
}