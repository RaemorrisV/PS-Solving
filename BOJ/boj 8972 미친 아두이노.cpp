#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;//행 열
int board[101][101];
string order;
int dx[9] = { 1,1,1,0,0,0,-1,-1,-1 };
int dy[9] = { -1,0,1,-1,0,1,-1,0,1 };
pair<int, int>jong_location;
bool flag;
struct info {
	int r_v;
	int c_v;
	int m_v;
};
vector<info>arr;
bool valid(int row, int col)
{
	if (row >= 1 && row <= r && col >= 1 && col <= c)return true;
	return false;
}
int dis(int row, int col)
{
	return abs(jong_location.first - row) + abs(jong_location.second - col);
}
void simulation(int oper)
{
	int row = jong_location.first;
	int col = jong_location.second;
	if (board[row + dx[oper]][col + dy[oper]] == 1)
	{
		flag = true;
		return;
	}
	jong_location = { row + dx[oper],col + dy[oper] };
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (board[i][j] == 1)
			{
				int move = 4;
				int MIN = 100000000;
				for (int z = 0; z < 9; z++)
				{
					if (z == 4)continue;
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (!valid(nx, ny))continue;
					if (nx == jong_location.first && ny == jong_location.second)
					{
						flag = true;
						return;
					}
					int cal = dis(nx, ny);
					if (MIN > cal)
					{
						move = z;
						MIN = cal;
					}
				}
				arr.push_back({ i,j,move });
			}
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		int rv = arr[i].r_v;
		int cv = arr[i].c_v;
		int mv = arr[i].m_v;
		board[rv][cv]--;
		board[rv + dx[mv]][cv + dy[mv]]++;
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (board[i][j] >= 2)board[i][j] = 0;
		}
	}
	arr.clear();
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		string row;
		cin >> row;
		for (int j = 1; j <= c; j++)
		{
			if (row[j - 1] == 'I')
			{
				jong_location = { i,j };
			}
			else if (row[j - 1] == 'R')
			{
				board[i][j] = 1;
			}
		}
	}
	cin >> order;
	for (int i = 0; i < order.length(); i++)
	{
		simulation(order[i] - '0' - 1);
		if (flag)
		{
			cout << "kraj " << i + 1 << '\n';
			break;
		}
	}
	if (flag == false)
	{
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (i == jong_location.first && j == jong_location.second)
				{
					cout << 'I';
				}
				else if (board[i][j] == 0)
				{
					cout << '.';
				}
				else if (board[i][j] == 1)
				{
					cout << 'R';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}
