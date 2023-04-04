#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool maze[52][52];
int n;
int cur_idx = 2;
int min_r, min_c, max_r, max_c;
string input;
bool make_maze(int r, int c)
{
	;
	int cur_r = r;
	int cur_c = c;
	maze[r][c] = true;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'F')
		{
			int nx = cur_r + dx[cur_idx];
			int ny = cur_c + dy[cur_idx];
			maze[nx][ny] = true;
			cur_r = nx;
			cur_c = ny;
		}
		else if (input[i] == 'L')
		{
			cur_idx = (cur_idx + 3) % 4;
		}
		else if (input[i] == 'R')
		{
			cur_idx = (cur_idx + 5) % 4;
		}
	}
	return true;
}
void decision()
{
	int cur_r = 0;
	int cur_c = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'F')
		{
			cur_r += dx[cur_idx];
			cur_c += dy[cur_idx];
			max_r = max(max_r, cur_r);
			max_c = max(max_c, cur_c);
			min_r = min(min_r, cur_r);
			min_c = min(min_c, cur_c);
		}
		else if (input[i] == 'L')
		{
			cur_idx = (cur_idx + 3) % 4;
		}
		else if (input[i] == 'R')
		{
			cur_idx = (cur_idx + 5) % 4;
		}
	}
}
void printmaze()
{
	for (int i = 1; i <= (max_r - min_r) + 1; i++)
	{
		for (int j = 1; j <= (max_c - min_c) + 1; j++)
		{
			if (maze[i][j])cout << ".";
			else cout << "#";
		}
		cout << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> input;
	decision();
	cur_idx = 2;
	make_maze(0 - min_r + 1, 0 - min_c + 1);
	printmaze();
	return 0;
}