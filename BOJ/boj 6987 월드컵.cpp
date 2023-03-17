#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <string>
using namespace std;

int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };
struct total {
	int win;
	int draw;
	int lose;
};
total team[6];
total input[6];
int ans[4];
void dfs(int num, int depth)
{
	//dfs 종료조건 
	if (depth == 15)
	{
		string temp = "";
		for (int i = 0; i < 6; i++)
		{
			if (input[i].win != team[i].win || input[i].lose != team[i].lose || input[i].draw != team[i].draw)return;
		}
		ans[num] = 1;
		return;
	}
	int t1 = team1[depth];
	int t2 = team2[depth];
	team[t1].win++;
	team[t2].lose++;
	dfs(num, depth + 1);
	team[t1].win--;
	team[t2].lose--;
	//t1과 비겼을 경우
	team[t1].draw++;
	team[t2].draw++;
	dfs(num, depth + 1);
	team[t1].draw--;
	team[t2].draw--;
	//t1이 졌을경우
	team[t1].lose++;
	team[t2].win++;
	dfs(num, depth + 1);
	team[t1].lose--;
	team[t2].win--;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			input[j] = { a,b,c };
		}
		dfs(i, 0);
	}
	for (int i = 0; i < 4; i++)
	{
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}