#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, ans;
int board[20][20];
void dfs(int depth, int dir)
{
	if (depth == 5)return;
	if (dir == 0) //up
	{
		vector<int>temp;
		vector<int>want;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[j][i] != 0)temp.push_back(board[j][i]);
			}
			for (int j = 0; j < temp.size(); j++)
			{
				if (j != temp.size() - 1 && temp[j] == temp[j + 1])
				{
					want.push_back(temp[j] * 2);
					j++;
				}
				else {
					want.push_back(temp[j]);
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (j < want.size())board[j][i] = want[j];
				else board[j][i] = 0;
			}
			temp.clear();
			want.clear();
		}
	}
	else if (dir == 1) //down
	{
		vector<int>temp;
		vector<int>want;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[j][i] != 0)temp.push_back(board[j][i]);
			}
			reverse(temp.begin(), temp.end());
			for (int j = 0; j < temp.size(); j++)
			{
				if (j != temp.size() - 1 && temp[j] == temp[j + 1])
				{
					want.push_back(temp[j] * 2);
					j++;
				}
				else {
					want.push_back(temp[j]);
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (j < want.size())board[(n - 1)-j][i] = want[j];
				else board[(n - 1)-j][i] = 0;
			}
			temp.clear();
			want.clear();
		}
	}
	else if (dir == 2) //right
	{
		vector<int>temp;
		vector<int>want;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] != 0)temp.push_back(board[i][j]);
			}
			reverse(temp.begin(), temp.end());
			for (int j = 0; j < temp.size(); j++)
			{
				if (j != temp.size() - 1 && temp[j] == temp[j + 1])
				{
					want.push_back(temp[j] * 2);
					j++;
				}
				else {
					want.push_back(temp[j]);
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (j < want.size())board[i][(n - 1)-j] = want[j];
				else board[i][(n - 1) - j] = 0;
			}
			temp.clear();
			want.clear();
		}
	}
	else if (dir == 3) //left
	{
		vector<int>temp;
		vector<int>want;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] != 0)temp.push_back(board[i][j]);
			}
			for (int j = 0; j < temp.size(); j++)
			{
				if (j != temp.size() - 1 && temp[j] == temp[j + 1])
				{
					want.push_back(temp[j] * 2);
					j++;
				}
				else {
					want.push_back(temp[j]);
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (j < want.size())board[i][j] = want[j];
				else board[i][j] = 0;
			}
			temp.clear();
			want.clear();
		}
	}
	//가장 최댓값 초기화 시켜줌
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, board[i][j]);
		}
	}
	//본격 백트래킹
	//memset(backup, 0, sizeof(backup));
	int backup[20][20];
	for (int i = 0; i < 4; i++)
	{
		copy(&board[0][0], &board[0][0] + 20 * 20, &backup[0][0]);
		//memcpy(backup, board, sizeof(board));
		dfs(depth + 1, i);
		copy(&backup[0][0], &backup[0][0] + 20 * 20, &board[0][0]);
		//memcpy(board, backup, sizeof(backup));
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int backup[20][20];
	//memset(backup, 0, sizeof(backup));
	for (int i = 0; i < 4; i++)
	{
		copy(&board[0][0], &board[0][0] + 20 * 20, &backup[0][0]);
		//memcpy(backup, board, sizeof(board));
		dfs(0, i);
		copy(&backup[0][0], &backup[0][0] + 20 * 20, &board[0][0]);
		//memcpy(board, backup, sizeof(backup));
	}
	cout << ans << "\n";
	return 0;
}