#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<char, int>mapping;
unordered_map<int, char>mapping2;
char map[26][26];
int r, c;
pair<int, int>mosc;
int dx[4] = { -1,0,1,0 }; //상 좌 하 우
int dy[4] = { 0,-1,0,1 };
bool correctDir[8][4];
int dir;
pair<int, int>ans;
int ansBlock = 0;
pair<int, int>ansDir;
bool visited[26][26];
bool valid(int row, int col)
{
	if (row >= 1 && row <= r && col >= 1 && col <= c)return true;
	return false;
}
void init()
{
	//1 -> 블록1 , 2 -> 블록 2 , 3 -> 블록 3, 4->블록 4 , 5-> 블록 | , 6-> 블록 -, 7->블록 + 
	mapping['1'] = 1;
	mapping['2'] = 2;
	mapping['3'] = 3;
	mapping['4'] = 4;
	mapping['|'] = 5;
	mapping['-'] = 6;
	mapping['+'] = 7;
	mapping2[1] = '1';
	mapping2[2] = '2';
	mapping2[3] = '3';
	mapping2[4] = '4';
	mapping2[5] = '|';
	mapping2[6] = '-';
	mapping2[7] = '+';
	int cur_dir1 = -1;
	int cur_dir2 = 0;
	for (int i = 1; i <= 4; i++)
	{
		cur_dir1 += 1;
		cur_dir2 += 1;
		cur_dir1 = cur_dir1 % 4;
		cur_dir2 = cur_dir2 % 4;
		correctDir[i][cur_dir1] = true;
		correctDir[i][cur_dir2] = true;
	}
	for (int i = 0; i < 4; i++)
	{
		correctDir[7][i] = true;
	}
	correctDir[5][0] = true;
	correctDir[5][2] = true;
	correctDir[6][1] = true;
	correctDir[6][3] = true;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'M')
			{
				mosc.first = i;
				mosc.second = j;
			}
		}
	}
	init();
	int cur_r = mosc.first;
	int cur_c = mosc.second;
	visited[cur_r][cur_c] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = cur_r + dx[i];
		int ny = cur_c + dy[i];
		if (valid(nx, ny) && map[nx][ny] != '.' && correctDir[mapping[map[nx][ny]]][i])
		{
			dir = i;
			break;
		}
	}
	while (1)
	{
		cur_r += dx[dir];
		cur_c += dy[dir];
		visited[cur_r][cur_c] = true;
		if (map[cur_r][cur_c] == 'Z')break;
		if (map[cur_r][cur_c] == '.')//핵심로직
		{
			ans.first = cur_r;
			ans.second = cur_c;
			ansDir.first = dir;
			if (ansBlock != 0)
			{
				ansBlock = 7;
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = cur_r + dx[i];
				int ny = cur_c + dy[i];
				if (valid(nx, ny) && (visited[nx][ny]==false || map[nx][ny]=='+') && map[nx][ny] != '.' && correctDir[mapping[map[nx][ny]]][i])
				{
					dir = i;
					ansDir.second = dir;
					break;
				}
			}
			if (ansDir.first == 0 && ansDir.second == 0 || ansDir.first == 2 && ansDir.second == 2)ansBlock = 5;
			else if(ansDir.first == 3 && ansDir.second == 3 || ansDir.first == 1 && ansDir.second == 1)ansBlock = 6;
			else if (ansDir.first == 0 && ansDir.second == 3 || ansDir.first == 1 && ansDir.second == 2)ansBlock = 1;
			else if (ansDir.first == 2 && ansDir.second == 3 || ansDir.first == 1 && ansDir.second == 0)ansBlock = 2;
			else if (ansDir.first == 3 && ansDir.second == 0 || ansDir.first == 2 && ansDir.second == 1)ansBlock = 3;
			else if (ansDir.first == 3 && ansDir.second == 2 || ansDir.first == 0 && ansDir.second == 1)ansBlock = 4;

		}
		else
		{
			if (map[cur_r][cur_c] == '1')
			{
				if (dir == 0)dir = 3;
				else dir = 2;
			}
			else if (map[cur_r][cur_c] == '2')
			{
				if (dir == 2)dir = 3;
				else dir = 0;
			}
			else if (map[cur_r][cur_c] == '3')
			{
				if (dir == 2)dir = 1;
				else dir = 0;
			}
			else if (map[cur_r][cur_c] == '4')
			{
				if (dir == 3)dir = 2;
				else dir = 1;
			}
		}
	}
	//출력
	cout << ans.first << " " << ans.second << " " << mapping2[ansBlock] << '\n';
	return 0;
}