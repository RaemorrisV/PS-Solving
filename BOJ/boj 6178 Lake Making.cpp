#include <iostream>
#include <vector>

using namespace std;

int r, c, e, n;
struct oper {
	int x;
	int y;
	int m;
};
vector<oper>cowOper;
int map[101][101];
void simulation(int index)
{
	int s_r = cowOper[index].x;
	int s_c = cowOper[index].y;
	int count = cowOper[index].m;
	int maxValue = -3;
	for (int i = s_r; i < s_r + 3; i++)
	{
		for (int j = s_c; j < s_c + 3; j++)
		{
			maxValue = max(maxValue, map[i][j]);
		}
	}
	for (int z = 0; z < count; z++)
	{
		for (int i = s_r; i < s_r + 3; i++)
		{
			for (int j = s_c; j < s_c + 3; j++)
			{
				if (map[i][j] == maxValue)
				{
					map[i][j]--;
				}
			}
		}
		maxValue--;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> e >> n;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cowOper.push_back({ a,b,c });
	}
	for (int i = 0; i < n; i++)
	{
		simulation(i);
	}
	int ans = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (e - map[i][j] <= 0)map[i][j] = 0;
			else map[i][j] = e - map[i][j];
			ans += map[i][j];
		}
	}
	cout << 72 * 72 * ans << "\n";
	return 0;
}