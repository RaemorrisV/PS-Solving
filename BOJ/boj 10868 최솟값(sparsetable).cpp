#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int sparsetable[18][100001];
void make_table()
{
	int jump = 1;
	for (int i = 2; i <= 17; i++)
	{
		jump *= 2;
		for (int j = 1; j <= n; j++)
		{
			sparsetable[i][j] = min(sparsetable[i - 1][j], sparsetable[i - 1][j + jump / 2]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> sparsetable[1][i];
	}
	make_table();
	for (int i = 0; i < m; i++)
	{
		int a, b;
		int ans = 1000000001;
		cin >> a >> b; //a 는 start
		int diff = b - a + 1;
		for (int j = 1, mask = 1; mask <= diff; j++, mask <<= 1)
		{
			if (diff & mask)
			{
				ans = min(sparsetable[j][a], ans);
				a += mask;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}