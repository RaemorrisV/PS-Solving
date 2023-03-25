#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int rec[101][101];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int r, c;
		cin >> r >> c;
		for (int i = r; i < r + 10; i++)
		{
			for (int j = c; j < c + 10; j++)
			{
				rec[i][j]++;
			}
		}
	}
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (rec[i][j])
			{
				ans++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}