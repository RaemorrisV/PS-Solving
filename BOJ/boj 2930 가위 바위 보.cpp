#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, r;
unordered_map<char, int>trans;
vector<string>myfriend;
string my;
int score_s, score_max, ans;
int score[3][3] = { {1,2,0},
					{0,1,2},
					{2,0,1} };
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	trans['S'] = 0;
	trans['P'] = 1;
	trans['R'] = 2;
	cin >> r >> my >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		myfriend.push_back(input);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < myfriend[i].length(); j++)
		{
			score_s += score[trans[my[j]]][trans[myfriend[i][j]]];
		}
	}
	for (int j = 0; j < r; j++)
	{
		int middle = 0;
		for (int z = 0; z < 3; z++)
		{
			score_max = 0;
			for (int i = 0; i < n; i++) //r이 라운드임
			{
				score_max += score[z][trans[myfriend[i][j]]];
			}
			middle = max(middle, score_max);
		}
		ans += middle;
	}
	cout << score_s << '\n';
	cout << ans << '\n';
	return 0;
}