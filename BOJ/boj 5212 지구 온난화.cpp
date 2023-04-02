#include <iostream>
#include <algorithm>

using namespace std;

int min_r, min_c, max_r, max_c;
int r, c;
char map[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool under[11][11];
bool valide(int row, int col)
{
	if (row >= 1 && row <= r && col >= 1 && col <= c)return true;
	return false;
}
void simulation()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] == 'X')
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (valide(nx, ny) && map[nx][ny] == '.')
					{
						cnt++;
					}
					else if (valide(nx, ny) == false)cnt++;
				}
				if (cnt >= 3)under[i][j] = true;
				else
				{
					max_r = max(i, max_r);
					max_c = max(j, max_c);
					min_r = min(i, min_r);
					min_c = min(j, min_c);
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c;
	min_r = 1234;
	min_c = 1234;
	for (int i = 1; i <= r; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= c; j++)
		{
			map[i][j] = input[j - 1];
			if(map[i][j]=='.')under[i][j] = true;
		}
	}
	simulation();
	for (int i = min_r; i <= max_r; i++)
	{
		for (int j = min_c; j <= max_c; j++)
		{
			if (under[i][j])cout << ".";
			else cout << "X";
		}
		cout << '\n';
	}
	return  0;
}