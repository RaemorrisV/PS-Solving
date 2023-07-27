#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[5][9];
bool visited[13];
int total;
bool flag;
vector<pair<int, int>>star;
bool isPossible()
{
	flag = false;
	//기준 (0.4)
	int sum = 0;
	int r = 0;
	int c = 4;
	for (int i = 0; i < 4; i++)
	{
		int nx = r + i;
		int ny = c - i;
		if (map[nx][ny] >= 'A' && map[nx][ny] <= 'L')sum += map[nx][ny] - 'A' + 1;
	}
	if (sum > 26)return false;
	if (sum != 26)flag = true;
	sum = 0;
	r = 0;
	c = 4;
	for (int i = 0; i < 4; i++)
	{
		int nx = r + i;
		int ny = c + i;
		if (map[nx][ny] >= 'A' && map[nx][ny] <= 'L')sum += map[nx][ny] - 'A' + 1;
	}
	if (sum > 26)return false;
	if (sum != 26)flag = true;
	//기준 (1,1)
	sum = 0;
	r = 1;
	c = 1;
	for (int i = 0; i < 7; i++)
	{
		int ny = c + i;
		if (map[r][ny] >= 'A' && map[r][ny] <= 'L')sum += map[r][ny] - 'A' + 1;
	}
	if (sum > 26)return false;
	if (sum != 26)flag = true;
	sum = 0;
	r = 1;
	c = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = r + i;
		int ny = c + i;
		if (map[nx][ny] >= 'A' && map[nx][ny] <= 'L')sum += map[nx][ny] - 'A' + 1;
	}
	if (sum > 26)return false;
	if (sum != 26)flag = true;
	//기준 (3,1)
	sum = 0;
	r = 3;
	c = 1;
	for (int i = 0; i < 7; i++)
	{
		int nx = r;
		int ny = c + i;
		if (map[nx][ny] >= 'A' && map[nx][ny] <= 'L')sum += map[nx][ny] - 'A' + 1;
	}
	if (sum > 26)return false;
	if (sum != 26)flag = true;
	//기준 (4, 4)
	sum = 0;
	r = 4;
	c = 4;
	for (int i = 0; i < 4; i++)
	{
		int nx = r - i;
		int ny = c + i;
		if (map[nx][ny] >= 'A' && map[nx][ny] <= 'L')sum += map[nx][ny] - 'A' + 1;
	}
	if (sum > 26)return false;
	if (sum != 26)flag = true;
	return true;
}
void dfs(int word, int depth)
{

	if (depth == star.size())
	{
		if (isPossible() && flag == false)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << map[i][j];
				}
				cout << "\n";
			}
			exit(0);
		}
		return;
	}
	for (int z = 1; z < 13; z++)
	{
		if (visited[z] == false)
		{
			visited[z] = true;
			map[star[depth].first][star[depth].second] = 'A' + z - 1;
			dfs(z, depth+1);
			map[star[depth].first][star[depth].second] = 'x';
			visited[z] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < 9; j++)
		{
			map[i][j] = input[j];
			if (map[i][j] == 'x')star.push_back({ i,j });
			else if (map[i][j] >= 'A' && map[i][j] <= 'L')
			{
				visited[map[i][j] - 'A' + 1] = true;
			}
		}
	};
	for (int z = 1; z < 13; z++)
	{
		if (visited[z] == false)
		{
			visited[z] = true;
			map[star[0].first][star[0].second] = 'A' + z - 1;
			dfs(z, 1);
			map[star[0].first][star[0].second] = 'x';
			visited[z] = false;
		}
	}
	return 0;
}