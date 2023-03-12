#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int A[205][205]; // 행
vector<vector<int>>B(205); // 열
int r, c, k;
int row, col;
int MAX = 0;
unordered_map<int, int>use_cnt;
vector<int>t1;
int ans = -1;
bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}
int calculate(int cur_r, char op)
{
	vector<pair<int, int>>temp;
	if (op == 'R')//R 연산
	{
		for (int i = 0; i < t1.size(); i++)
		{
			temp.push_back({ t1[i],use_cnt[t1[i]] });
		}
		sort(temp.begin(), temp.end(), compare);
		int size = min((int)temp.size() * 2, 100);
		for (int i = 0; i < temp.size(); i++)
		{
			A[cur_r][i*2 + 1] = temp[i].first;
			A[cur_r][i*2 + 2] = temp[i].second;
		}
		MAX = max(MAX, size);
		return size;
	}
	else if (op == 'C') //C 연산
	{
		for (int i = 0; i < t1.size(); i++)
		{
			temp.push_back({ t1[i],use_cnt[t1[i]] });
		}
		sort(temp.begin(), temp.end(), compare);
		int size = min((int)temp.size() * 2, 100);
		for (int i = 0; i < size/2; i++)
		{
			A[i*2 + 1][cur_r] = temp[i].first;
			A[i*2 + 2][cur_r] = temp[i].second;
		}
		MAX = max(MAX, size);
		return size;
	}
}
void simulation()
{
	vector<int>end;
	if (row >= col)//R 연산을 진행 해줘야됨 모든 행에 대해서 진행
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (A[i][j] != 0)
				{
					use_cnt[A[i][j]]++;
					t1.push_back(A[i][j]);
				}
			}
			//중복 제거 해줘야 할듯
			sort(t1.begin(), t1.end());
			t1.erase(unique(t1.begin(), t1.end()), t1.end());
			int aaa = calculate(i, 'R');
			end.push_back(aaa);
			use_cnt.clear();
			t1.clear();
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = end[i - 1] + 1; j <= MAX; j++)
			{
				A[i][j] = 0;
			}
		}
		end.clear();
		col = MAX;
		MAX = 0;
	}
	else if (row < col)//C 연산을 진행 해주면 됨 모든 열에 대해서 진행
	{
		for (int i = 1; i <= col; i++)
		{
			for (int j = 1; j <= row; j++)
			{
				if (A[j][i] != 0)
				{
					use_cnt[A[j][i]]++;
					t1.push_back(A[j][i]);
				}
			}
			sort(t1.begin(), t1.end());
			t1.erase(unique(t1.begin(), t1.end()), t1.end());
			int  aaa = calculate(i, 'C');
			end.push_back(aaa);
			use_cnt.clear();
			t1.clear();
		}
		//여기부터
		for (int i = 1; i <= col; i++)
		{
			for (int j = end[i-1]+1; j <= MAX; j++)
			{
				A[j][i] = 0;
			}
		}
		end.clear();
		row = MAX;
		MAX = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> k;
	row = 3;
	col = 3;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i <=100; i++)
	{
		if (A[r][c] == k)
		{
			ans = i;
			break;
		}
		if (i == 100)break;
		simulation();
	}
	cout << ans << '\n';
	return 0;
}