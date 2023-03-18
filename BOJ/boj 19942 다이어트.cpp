#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n;
int ans = 90000;
int minimum[4];
int info[16][5];//단백질 탄수화물 지방 비타민 가격
vector<int>choice;
vector<int>ansvector;
int sum[5];
bool visited[16];
void dfs(int num)
{
	//종료 조건 써주기
	bool flag = true;
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < choice.size(); i++)
	{
		int idx = choice[i];
		sum[0] += info[idx][0]; //단백질
		sum[1] += info[idx][1]; //지방
		sum[2] += info[idx][2]; //탄수화물
		sum[3] += info[idx][3]; //비타민
		sum[4] += info[idx][4]; //가격
	}
	for (int i = 0; i < 4; i++)
	{
		if (minimum[i] > sum[i])flag=false;
	}
	if (flag && ans > sum[4])//만약 갱신이 되었다면
	{
		ansvector.clear();
		for (int i = 0; i < choice.size(); i++)
		{
			ansvector.push_back(choice[i]);
		}
		ans = min(ans, sum[4]);
	}
	for (int i = num + 1; i <= n; i++)
	{
		choice.push_back(i);
		dfs(i);
		choice.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		cin >> minimum[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> info[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		choice.push_back(i);
		dfs(i);
		choice.pop_back();
	}
	if (ans == 90000)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << ans << '\n';
		for (int i = 0; i < ansvector.size(); i++)
		{
			cout << ansvector[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}