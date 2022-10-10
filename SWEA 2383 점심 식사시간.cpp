#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
int room[11][11];
vector<pair<int, int>>people;
vector<tuple<int, int, int>>stairs;//행 열 걸리는 시간 값을 저장해둠
priority_queue<int, vector<int>, greater<int>>stairs1;//첫번째 계단에서 기다리는 사람들
priority_queue<int, vector<int>, greater<int>>stairs2;//첫번째 계단에서 기다리는 사람들
vector<int>a1;//1번 계단모음
vector<int>a2;//2번 계단모음
int t, n;
int MIN = 1000000;
int cnt = 0;
int ans()//1번 계단하고 2번 계단 두개로 나눠서 진행
{
	int cnt1 = 0, cnt2 = 0;
	vector<int>come1;
	vector<int>come2;
	for (int i = 0; i < a1.size(); i++)
	{
		int man = abs(people[a1[i]].first - get<0>(stairs[0])) + abs(people[a1[i]].second - get<1>(stairs[0])) + 1;
		come1.push_back(man);
	}
	sort(come1.begin(), come1.end());
	for (int i = 0; i < a2.size(); i++)
	{
		int man = abs(people[a2[i]].first - get<0>(stairs[1])) + abs(people[a2[i]].second - get<1>(stairs[1])) + 1;
		come2.push_back(man);
	}
	sort(come2.begin(), come2.end());
	for (int i = 0; i < come1.size(); i++)
	{
		if (stairs1.size() < 3)//그냥 들어가도됨
		{
			stairs1.push(come1[i] + get<2>(stairs[0]));
		}
		else
		{
			if (come1[i] >= stairs1.top())//들어오는게 늦어?
			{
				stairs1.push(come1[i] + get<2>(stairs[0]));
				stairs1.pop();
			}
			else //얜 좀 기다려야지
			{
				stairs1.push(stairs1.top() + get<2>(stairs[0]));
				stairs1.pop();
			}
		}
	}
	for (int i = 0; i < come2.size(); i++)
	{
		if (stairs2.size() < 3)//그냥 들어가도됨
		{
			stairs2.push(come2[i] + get<2>(stairs[1]));
		}
		else
		{
			if (come2[i] >= stairs2.top())//들어오는게 늦어?
			{
				stairs2.push(come2[i] + get<2>(stairs[1]));
				stairs2.pop();
			}
			else //얜 좀 기다려야지
			{
				stairs2.push(stairs2.top() + get<2>(stairs[1]));
				stairs2.pop();
			}
		}
	}
	while (!stairs1.empty())
	{
		cnt1 = max(stairs1.top(), cnt1);
		stairs1.pop();
	}
	while (!stairs2.empty())
	{
		cnt2 = max(stairs2.top(), cnt2);
		stairs2.pop();
	}
	//cout << cnt1 << " " << cnt2 << endl; 
	return max(cnt1, cnt2);
}
void dfs(int len)//dfs를 통해 모든경우의 수를 구해보도록 하자
{
	if (len == people.size())
	{
		//cnt++;
		int ww = ans();
		MIN = min(ww, MIN);
		//cout<<cnt <<" "<< ww << " " << MIN << endl;
		return;
	}
	a1.push_back(len);
	dfs(len + 1);
	a1.pop_back();
	a2.push_back(len);
	dfs(len + 1);
	a2.pop_back();
}

int main()
{
	cin >> t;
	for (int z = 1; z <= t; z++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> room[i][j];
				if (room[i][j] == 1)
				{
					people.push_back({ i,j });
				}
				else if (room[i][j] != 0 && room[i][j] != 1)
				{
					stairs.push_back({ i,j,room[i][j] });
				}
			}
		}
		dfs(0);
		cout << "#" << z << " " << MIN << "\n";
		fill(&room[0][0], &room[n][n + 1], 0);
		people.clear(); stairs.clear();
		a1.clear(); a2.clear();
		MIN = 1000000;
	}
	return 0;
}