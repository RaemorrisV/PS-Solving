#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans; //n За m ї­
int rec[50][50];
bool valide(int r, int c, int s)
{
	if (r + s - 1 >= 0 && r + s - 1 < n && c + s - 1 >= 0 && c + s - 1 < m)return true;
	return false;
}
int check(int r, int c)
{
	int size = 0;
	int value = rec[r][c];
	int res = 1;
	while (1)
	{
		size++;
		if (valide(r, c, size) == false)break;
		if (rec[r][c + size - 1] == value && rec[r + size - 1][c] == value && rec[r + size - 1][c + size - 1] == value)
		{
			res = size;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			rec[i][j] = input[j] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans = max(ans, check(i, j));
		}
	}
	cout << ans * ans << '\n';
	return 0;
}