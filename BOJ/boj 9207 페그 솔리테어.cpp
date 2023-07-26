#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char board[5][9];
int dx[4] = { -1,1,0,0 }; //╩С го аб ©Л
int dy[4] = { 0,0,-1,1 };
int total;
int ans = 1000000000;
int ansMove;
vector<pair<int, int>>arr;
bool valid(int r, int c)
{
	if (r >= 0 && r < 5 && c >= 0 && c < 9)return true;
	return false;
}
void dfs(int remain, int move)
{
	if (ans > remain) {
		ans = remain;
		ansMove = move;
	}
	for (int i = 0; i < remain; i++)
	{
		int r = arr[i].first;
		int c = arr[i].second;
		for (int z = 0; z < 4; z++)
		{
			int nx = r + dx[z];
			int ny = c + dy[z];
			int nnx = nx + dx[z];
			int nny = ny + dy[z];
			if (valid(nx, ny) && board[nx][ny] == 'o' && valid(nnx, nny) && board[nnx][nny] == '.')
			{
				vector<pair<int, int>>temparr = arr;
				arr[i].first = nnx;
				arr[i].second = nny;
				for (int j = 0; j < remain; j++)
				{
					if (arr[j].first == nx && arr[j].second == ny)
					{
						arr.erase(arr.begin() + j);
						break;
					}
				}
				char temp[5][9];
				copy(&board[0][0], &board[0][0] + 5 * 9, &temp[0][0]);
				board[r][c] = '.';
				board[nx][ny] = '.';
				board[nnx][nny] = 'o';
				dfs(remain - 1, move + 1);
				arr = temparr;
				copy(&temp[0][0], &temp[0][0] + 5 * 9, &board[0][0]);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int tc = 0; tc < n; tc++)
	{
		for (int i = 0; i < 5; i++)
		{
			string input;
			cin >> input;
			for (int j = 0; j < 9; j++)
			{
				board[i][j] = input[j];
				if (board[i][j] == 'o')
				{
					total++;
					arr.push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < total; i++)
		{
			int r = arr[i].first;
			int c = arr[i].second;
			for (int z = 0; z < 4; z++)
			{
				int nx = r + dx[z];
				int ny = c + dy[z];
				int nnx = nx + dx[z];
				int nny = ny + dy[z];
				if (valid(nx, ny) && board[nx][ny] == 'o' && valid(nnx, nny) && board[nnx][nny] == '.')
				{
					vector<pair<int, int>>temparr = arr;
					arr[i].first = nnx;
					arr[i].second = nny;
					for (int j = 0; j < total; j++)
					{
						if (arr[j].first == nx && arr[j].second == ny)
						{
							arr.erase(arr.begin()+j);
							break;
						}
					}
					char temp[5][9];
					copy(&board[0][0], &board[0][0] + 5 * 9, &temp[0][0]);
					board[r][c] = '.';
					board[nx][ny] = '.';
					board[nnx][nny] = 'o';
					dfs(total - 1, 1);
					arr = temparr;
					copy(&temp[0][0], &temp[0][0] + 5 * 9, &board[0][0]);
				}
			}
		}
		if (ans == 1000000000)
		{
			cout << total << " " << 0 << '\n';
		}
		else cout << ans << " " << ansMove << "\n";
		total = 0;
		ans = 1000000000;
		arr.clear();
	}
	return 0;
}