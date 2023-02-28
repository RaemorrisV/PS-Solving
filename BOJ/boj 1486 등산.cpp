#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;

int mt[25][25];
int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };
int n, m, t, d; //행 열 
int ans = 0; //가장 높은 위치
int T[25][25];
int T2[25][25];
struct info {
	int r;
	int c;
	int time;
};
bool valide(int row, int col)
{
	if (row >= 0 && row < n && col >= 0 && col < m)return true;
	return false;
}
//만약 적은 시간으로 들어왔으면? -> 다익스트라도 될듯?
struct compare {
	bool operator()(info a, info b)
	{
		return a.time > b.time;
	}
};
void dijkstra(int x,int y)
{
	priority_queue<info, vector<info>, compare>pq;
	pq.push({ x,y,0 });
	T[x][y] = 0;
	while (!pq.empty())
	{
		int cur_row = pq.top().r;
		int cur_col = pq.top().c;
		int cur_time = pq.top().time;
		pq.pop();
		if (T[cur_row][cur_col] < cur_time)continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_row + dx[i];
			int ny = cur_col + dy[i];
			int diff = abs(mt[cur_row][cur_col] - mt[nx][ny]);
			if (valide(nx, ny) && diff <= t)
			{
				if (mt[cur_row][cur_col] >= mt[nx][ny])
				{
					if (T[cur_row][cur_col] + 1 <= d && T[nx][ny] > T[cur_row][cur_col] + 1)
					{
						T[nx][ny] = T[cur_row][cur_col] + 1;
						pq.push({ nx,ny,T[nx][ny] });
					}
				}
				else if (mt[cur_row][cur_col] < mt[nx][ny])
				{
					if (T[cur_row][cur_col] + pow(diff, 2) <= d && T[nx][ny] > T[cur_row][cur_col] + pow(diff, 2))
					{
						T[nx][ny] = T[cur_row][cur_col] + pow(diff, 2);
						pq.push({ nx,ny,T[nx][ny] });
					}
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	fill(&T[0][0], &T[24][25], INF);
	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; i++)//행
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)//열
		{
			if (input[j] >= 97)mt[i][j] = input[j] - 'a' + 26;
			else if (input[j] >= 65)mt[i][j] = input[j] - 'A';
		}
	}
	dijkstra(0,0);
	copy(&T[0][0],&T[0][0]+25*25,&T2[0][0]);
	for (int i = 0; i < n; i++)//행
	{
		for (int j = 0; j < m; j++)//열
		{
			fill(&T[0][0], &T[24][25], INF);
			dijkstra(i, j);
			if (T2[i][j] + T[0][0] <= d)ans = max(ans, mt[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}