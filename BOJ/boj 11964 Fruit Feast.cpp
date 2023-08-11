#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int t;
int dx[2];
bool dp[10000001];
int ans;
void bfs()
{
	queue<pair<int,bool>>q;
	q.push({ dx[0] ,false});
	q.push({ dx[1] ,false});
	q.push({ dx[0]/2 ,true });
	q.push({ dx[1]/2 ,true });
	dp[dx[0]] = true;
	dp[dx[1]] = true;
	dp[dx[0]/2] = true;
	dp[dx[1]/2] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		bool isHalf = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			int nx = cur + dx[i];
			if (nx > t)continue;
			if (isHalf == false && dp[nx / 2] == false)
			{
				dp[nx/2] = true;
				q.push({ nx/2,true });
			}
			if (dp[nx] == false)
			{
				dp[nx] = true;
				q.push({ nx,isHalf });
			}

		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t >> dx[0] >> dx[1];
	bfs();
	for (int i = 1; i <= t; i++)
	{
		if (dp[i])ans = max(ans, i);
	}
	cout << ans << '\n';
	return 0;
}