#include <iostream>

using namespace std;

int n, rowcnt, colcnt;
char room[101][101]; 
int row()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (room[i][j] == '.')
			{
				int temp = 0;
				int nj = n;
				for (int k = j; k <= n; k++)
				{
					if (room[i][k] == '.')temp++;
					else
					{
						nj = k;
						break;
					}
				}
				j = nj;
				if (temp >= 2)cnt++;
			}
		}
	}
	return cnt;
}
int col()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (room[j][i] == '.')
			{
				int temp = 0;
				int nj = n;
				for (int k = j; k <= n; k++)
				{
					if (room[k][i] == '.')temp++;
					else
					{
						nj = k;
						break;
					}
				}
				j = nj;
				if (temp >= 2)cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= n; j++)
		{
			room[i][j] = input[j - 1];
		}
	}
	rowcnt = row();
	cout << rowcnt << "\n";
	colcnt = col();
	cout << colcnt << '\n';
	return 0;
}