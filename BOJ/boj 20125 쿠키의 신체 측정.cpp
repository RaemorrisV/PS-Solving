#include <iostream>

using namespace std;
char cookie[1001][1001];
int n;
int ans[5];
pair<int, int>heart;
void findLength(int r, int c)
{
	int left = 0;
	int right = 0;
	int wist = 0;
	int r_l = 0;
	int r_r = 0; 
	for (int i = 1; i <= n; i++)
	{
		int ny = c - i; 
		if (cookie[r][ny] != '*'||ny < 1)break;
		left++;
	}
	ans[0] = left;
	for (int i = 1; i <= n; i++)
	{
		int ny = c + i;
		if (cookie[r][ny] != '*' ||ny > n)break;
		right++;
	}
	ans[1] = right;
	int s_r = 0;
	int s_c = c-1;
	for (int i = 1; i <= n; i++)
	{
		int nx = r + i;
		if (cookie[nx][c] != '*')
		{
			s_r = nx - 1;
			break;
		}
		wist++;
	}
	ans[2] = wist;
	for (int i = 1; i <= n; i++)
	{
		int nx = s_r + i;
		if (cookie[nx][s_c] != '*'||nx > n)break;
		r_l++;
	}
	ans[3] = r_l;
	s_c = c + 1;
	for (int i = 1; i <= n; i++)
	{
		int nx = s_r + i;
		if (cookie[nx][s_c] != '*'||nx>n)break;
		r_r++;
	}
	ans[4] = r_r;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for(int j=1;j<=n;j++)
		{ 
			cookie[i][j] = input[j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cookie[i][j] == '*')
			{
				heart.first = i + 1;
				heart.second = j;
				findLength(i + 1, j);
				cout << heart.first << " " << heart.second << '\n';
				for (int i = 0; i < 5; i++)
				{
					cout << ans[i] << " ";
				}
				cout << '\n';
				exit(0);
			}
		}
	}
	return 0;
}