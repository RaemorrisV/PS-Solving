#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, input;
int valid[201];
vector<int>remember;
int MAX = 100000000;
int MIN = 100000000;
int winner;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		cin >> n;
		vector<vector<int>>team(201);//최종점수와 각각 점수
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			remember.push_back(input);
			valid[input] += 1;
		}
		int score = 1;
		for (int i = 0; i < remember.size(); i++)
		{
			if (valid[remember[i]] == 6) //자격이 안됨 //자격이 되는 팀
			{
				team[remember[i]].push_back(score++);
			}
		}
		for (int i = 0; i < remember.size(); i++)
		{
			int sum = 0;
			if (valid[remember[i]] == 6)  //자격이 되는 팀
			{
				for (int j = 0; j < 4; j++)
				{
					sum += team[remember[i]][j];
				}
				MAX = min(MAX, sum);
			}
		}
		for (int i = 0; i < remember.size(); i++)
		{
			int sum1 = 0;
			if (valid[remember[i]] == 6) //자격이 안됨 //자격이 되는 팀
			{
				for (int j = 0; j < 4; j++)
				{
					sum1 += team[remember[i]][j];
				}
				if (sum1 == MAX)
				{
					MIN = min(MIN, team[remember[i]][4]);
					if (MIN == team[remember[i]][4])
					{
						winner = remember[i];
					}
				}
			}
		}
		cout << winner << '\n';
		MAX = 100000000;
		MIN = 100000000;
		memset(valid, 0, sizeof(valid));
		remember.clear();
	}
	return 0;
}