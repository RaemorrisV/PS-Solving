#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000005
using namespace std;

int n;
int map[501][501];
int dp[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;
struct info {
	int r;
	int c;
	int val;
};
vector<info>road;
bool valide(int a, int b)
{
	if (a >= 1 && a <= n && b >= 1 && b <= n)return true;
	return false;
}
bool compare(info a, info b)
{
	return a.val < b.val;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			dp[i][j] = 1;
			road.push_back({ i,j,map[i][j] });
		}
	}
	sort(road.begin(), road.end(), compare);
	for (int i = 0; i < road.size(); i++)
	{
		int row = road[i].r;
		int col = road[i].c;
		int curval = road[i].val;
		for (int j = 0; j < 4; j++)
		{
			int nx = row + dx[j];
			int ny = col + dy[j];
			if (valide(nx, ny) && map[row][col] > map[nx][ny])
			{
				dp[row][col] = max(dp[row][col], dp[nx][ny] + 1);
			}
		}
		ans = max(ans, dp[row][col]);
	}
	cout << ans << '\n';
	return 0;
}