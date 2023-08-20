#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m, ans = -1;
char table[10][10];
vector<int>num;
bool valid(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
	return false;
}
void dfs(int r, int c, int row_diff, int col_diff)
{
	int temp = 0;
	for (int i = 0; i < num.size(); i++)
	{
		temp += num[i] * (int)pow(10, i);
	}
	//완전 제곱수 확인 
	double sqr = sqrt(temp);
	if ((sqr - (int)sqr) == 0)ans = max(ans, temp);
	if (row_diff == 0 && col_diff == 0)return;
	int nx = r + row_diff;
	int ny = c + col_diff;
	if (valid(nx, ny))
	{
		num.push_back(table[nx][ny] - '0');
		dfs(nx, ny, row_diff, col_diff);
		num.pop_back();
	}
	else return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string row;
		cin >> row;
		for (int j = 1; j <= m; j++)
		{
			table[i][j] = row[j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int z = -n; z <= n; z++)
			{
				for (int q = -m; q <= m; q++)
				{
					num.push_back(table[i][j] - '0');
					dfs(i, j, z, q);
					num.pop_back();
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}