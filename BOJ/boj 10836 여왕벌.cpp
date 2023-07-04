#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int m, n;//격자의 크기와 날짜 수
int home[700][700];
int dx[3] = { 0,-1,-1 }; //왼 왼위 위
int dy[3] = { -1,-1,0 };
vector<vector<int>>growth(1000002);
int cnt[1401];
void simulation(int day)
{
	//먼저 왼쪽 열과 (x,0) 제일 위쪽 행(0,x)
	for (int i = 0; i < growth[day][0]; i++)
	{
		cnt[i] += 0;
	}
	for (int i = 0; i < growth[day][1]; i++)
	{
		cnt[growth[day][0] + i] += 1;
	}
	for (int i = 0; i < growth[day][2]; i++)
	{
		cnt[growth[day][1] + growth[day][0] + i] += 2;
	}
}
void show()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << home[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	fill(&home[0][0], &home[m - 1][m], 1);
	for (int i = 0; i < n; i++)
	{
		int zero, one, two;
		cin >> zero >> one >> two;
		growth[i].push_back(zero);
		growth[i].push_back(one);
		growth[i].push_back(two);
		simulation(i); 
	}
	int tmp = 0;
	for (int i = m - 1; i >= 0; i--) {
		home[i][0] += cnt[tmp++];
	}
	for (int i = 1; i < m; i++) {
		home[0][i] += cnt[tmp++];
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < m; j++)
		{
			home[i][j] = home[i - 1][j];
		}
	}
	show();
	return 0;
}