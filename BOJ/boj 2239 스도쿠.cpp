#include <iostream>
#include <vector>

using namespace std;

int board[10][10];
bool visited[81];
vector<pair<int, int>> blank;
bool valide(int x, int y, int num)
{
	for (int i = 1; i <= 9; i++) // 행과 열을 체크
	{
		if (i != y)
		{
			if (board[x][i] == num)
				return false;
		}
		if (i != x)
		{
			if (board[i][y] == num)
				return false;
		}
	}
	// 3x3부분 체크
	for (int i = ((x - 1) / 3) * 3 + 1; i <= ((x - 1) / 3) * 3 + 3; i++) // 4 56   1 2 3
	{
		for (int j = ((y - 1) / 3) * 3 + 1; j <= ((y - 1) / 3) * 3 + 3; j++)
		{
			if (i != x && j != y && board[i][j] == num)
				return false;
		}
	}
	return true;
}
void dfs(int len, int num, int x, int y)
{
	if (valide(x, y, num) == false)
	{
		return;
	}
	if (len == blank.size())
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				cout << board[i][j];
			}
			cout << '\n';
		}
		exit(0);
	}
	for (int j = 1; j <= 9; j++)
	{
		board[blank[len].first][blank[len].second] = j;
		dfs(len + 1, j, blank[len].first, blank[len].second);
		board[blank[len].first][blank[len].second] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 1; i <= 9; i++)
	{
		string in;
		cin >> in;
		for (int j = 1; j <= 9; j++)
		{
			board[i][j] = in[j - 1] - '0';
			if (board[i][j] == 0)
				blank.push_back({ i, j });
		}
	}
	for (int j = 1; j <= 9; j++)
	{
		board[blank[0].first][blank[0].second] = j;
		dfs(1, j, blank[0].first, blank[0].second);
		board[blank[0].first][blank[0].second] = 0;
	}
	return 0;
}