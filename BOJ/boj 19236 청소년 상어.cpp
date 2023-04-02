#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//시계 
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int ans = 0;
int result = 0;
//구조체에 현재의 위치랑 방향저장
struct seainfo {
	int r;
	int c;
	int dir;
	int num;
	bool eaten;
};
bool valide(int row, int col)
{
	if (row >= 0 && row < 4 && col >= 0 && col < 4)return true;
	return false;
}
seainfo shark;
seainfo map[4][4];
seainfo fish[17];
void simulation()
{
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].eaten == false)
		{
			for (int j = 0; j < 8; j++)
			{
				int nx = fish[i].r + dx[(fish[i].dir + j) % 8];
				int ny = fish[i].c + dy[(fish[i].dir + j) % 8];
				if (valide(nx, ny) && !(nx == shark.r && ny == shark.c))
				{
					if (map[nx][ny].eaten)//비어 있을 경우
					{
						map[nx][ny] = map[fish[i].r][fish[i].c];
						map[fish[i].r][fish[i].c].eaten = true;
						fish[i].r = nx;
						fish[i].c = ny;
						fish[i].dir = (fish[i].dir + j) % 8;
					}
					else //다른 물고기가 있을 경우
					{
						seainfo temp = map[nx][ny];
						map[nx][ny] = map[fish[i].r][fish[i].c];
						map[fish[i].r][fish[i].c] = temp;
						fish[i].dir = (fish[i].dir + j) % 8;
						fish[temp.num].r = fish[i].r;
						fish[temp.num].c = fish[i].c;
						fish[i].r = nx;
						fish[i].c = ny;
					}
					break;
				}
			}
		}
	}
}
void dfs(int cur_r, int cur_c)
{
	//여기다 시뮬레이션 돌려
	simulation();
	//상어가 먹을 수 있음
	for (int i = 1; i <= 4; i++)
	{
		int nx = cur_r + i * dx[shark.dir];
		int ny = cur_c + i * dy[shark.dir];
		if (valide(nx, ny) && map[nx][ny].eaten == false)//먹을수 있으면 가야겠지
		{
			seainfo temp[4][4];
			seainfo t[17];
			copy(fish, fish + 17, t);
			copy(&map[0][0], &map[0][0] + 16, &temp[0][0]);
			shark.r = nx;
			shark.c = ny;
			ans += map[nx][ny].num;
			result = max(result, ans);
			shark.dir = fish[map[nx][ny].num].dir;
			fish[map[nx][ny].num].eaten = true;
			map[nx][ny].eaten = true;
			dfs(nx, ny);
			copy(&temp[0][0], &temp[0][0] + 16, &map[0][0]);
			copy(t, t + 17, fish);
			shark.r = cur_r;
			shark.c = cur_c;
			shark.dir = fish[map[cur_r][cur_c].num].dir;
			ans -= map[nx][ny].num;
		}
	}
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b;
			cin >> a >> b;
			map[i][j] = { i,j,b - 1,a,false };
			fish[a] = { i,j,b - 1,a ,false };
			if (i == 0 && j == 0)
			{
				ans = a;
				result = a;
				fish[a].eaten = true;
				map[0][0].eaten = true;
				shark = { 0,0, b - 1,1234 ,false };
			}
		}
	}
	simulation();
	for (int i = 1; i <= 4; i++)
	{
		int nx = i * dx[shark.dir];
		int ny = i * dy[shark.dir];
		if (valide(nx, ny) && map[nx][ny].eaten == false)//먹을수 있으면 가야겠지
		{
			seainfo t[17];
			seainfo temp[4][4];
			copy(fish, fish + 17, t);
			copy(&map[0][0], &map[0][0] + 4*4, &temp[0][0]);
			shark.r = nx;
			shark.c = ny;
			ans += map[nx][ny].num;
			result = max(result, ans);
			shark.dir = fish[map[nx][ny].num].dir;
			fish[map[nx][ny].num].eaten = true;
			map[nx][ny].eaten = true;
			dfs(nx, ny);
			copy(&temp[0][0], &temp[0][0] + 16, &map[0][0]);
			copy(t, t + 17, fish);
			shark.r = 0;
			shark.c = 0;
			shark.dir = fish[map[0][0].num].dir;
			ans -= map[nx][ny].num;
		}
	}
	cout << result << '\n';
	return 0;
}