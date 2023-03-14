#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, K;
int map[13][13];//0: 흰색 1: 빨간색 2: 파란색
int dx[4] = { -1,0,1,0 }; // u r d left
int dy[4] = { 0,1,0,-1 };
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
	return false;
}
struct order {
	int n_th;
};
struct horse {
	int r_idx;
	int c_idx;
	int dir;
};
int turn = 0;
vector<order>info[13][13]; //앞에 있을 수록 아래에 있다!
horse horseinfo[11];
bool simulation()
{
	for (int i = 1; i <= K; i++)
	{
		int row = horseinfo[i].r_idx;
		int col = horseinfo[i].c_idx;
		int nx = row + dx[horseinfo[i].dir];
		int ny = col + dy[horseinfo[i].dir];
		if (valide(nx, ny) == false || map[nx][ny] == 2)//파란색 연산
		{
			horseinfo[i].dir = (horseinfo[i].dir + 2) % 4;
			nx = row + dx[horseinfo[i].dir];
			ny = col + dy[horseinfo[i].dir];
			if (map[nx][ny] == 2 || valide(nx, ny) == false)continue;
			if (map[nx][ny] == 1)
			{
				for (int j = 0; j < info[row][col].size(); j++)
				{
					if (info[row][col][j].n_th == i)
					{
						for (int k = info[row][col].size() - 1; k >= j; k--)
						{
							info[nx][ny].push_back({ info[row][col][k].n_th });
							horseinfo[info[row][col][k].n_th].r_idx = nx;
							horseinfo[info[row][col][k].n_th].c_idx = ny;
						}
						info[row][col].erase(info[row][col].begin() + j, info[row][col].end());
						break;
					}
				}
			}
			else if (map[nx][ny] == 0)
			{
				for (int j = 0; j < info[row][col].size(); j++)
				{
					if (info[row][col][j].n_th == i)
					{
						for (int k = j; k < info[row][col].size(); k++)
						{
							info[nx][ny].push_back({ info[row][col][k].n_th });
							horseinfo[info[row][col][k].n_th].r_idx = nx;
							horseinfo[info[row][col][k].n_th].c_idx = ny;
						}
						info[row][col].erase(info[row][col].begin() + j, info[row][col].end());
						break;
					}
				}
			}
		}
		else if (map[nx][ny] == 1)//빨간색인 경우
		{
			for (int j = 0; j < info[row][col].size(); j++)
			{
				if (info[row][col][j].n_th == i)
				{
					for (int k = info[row][col].size() - 1; k >= j; k--)
					{
						info[nx][ny].push_back({ info[row][col][k].n_th });
						horseinfo[info[row][col][k].n_th].r_idx = nx;
						horseinfo[info[row][col][k].n_th].c_idx = ny;
					}
					info[row][col].erase(info[row][col].begin() + j, info[row][col].end());
					break;
				}
			}
		}
		else if (map[nx][ny] == 0)//흰색인 경우
		{
			for (int j = 0; j < info[row][col].size(); j++)
			{
				if (info[row][col][j].n_th == i)
				{
					for (int k = j; k < info[row][col].size(); k++)
					{
						info[nx][ny].push_back({ info[row][col][k].n_th });
						horseinfo[info[row][col][k].n_th].r_idx = nx;
						horseinfo[info[row][col][k].n_th].c_idx = ny;
					}
					info[row][col].erase(info[row][col].begin() + j, info[row][col].end());
					break;
				}
			}
		}
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (info[j][k].size() >= 4)return true;
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> K;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		int a, b, c; // 행 열 dir
		cin >> a >> b >> c;
		int temp;
		if (c == 1)temp = 1;
		else if (c == 2)temp = 3;
		else if (c == 3)temp = 0;
		else if (c == 4)temp = 2;
		info[a][b].push_back({ i + 1 });
		horseinfo[i + 1] = { a,b,temp };
	}
	while (1)
	{
		turn++;
		if (turn > 1000)
		{
			turn = -1;
			break;
		}
		if (simulation())break;
	}
	cout << turn << '\n';
	return 0;
}