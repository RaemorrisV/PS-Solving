#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long>score;
int n, p;
long long  new_s;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> new_s >> p;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			score.push_back(input);
		}
		sort(score.begin(), score.end());
		int idx = lower_bound(score.begin(), score.end(), new_s) - score.begin(); //인덱스를 구해줌
		score.insert(score.begin() + idx, new_s);
		if (score.size() <= p) //점수판 안넘겼을때
		{
			int cnt = 0;
			for (int i = score.size() - 1; i >= 0; i--)
			{
				if (score[i] != new_s)
				{
					cnt++;
				}
				else if (score[i] == new_s)
				{
					cnt++;
					break;
				}
			}
			cout << cnt << '\n';
		}
		else //점수판 넘겼을때
		{
			if (idx == 0)
			{
				cout << "-1" << '\n';
		    }
			else
			{
				int cnt = 0;
				for (int i = score.size() - 1; i >= 0; i--)
				{
					if (score[i] != new_s)
					{
						cnt++;
					}
					else if (score[i] == new_s)
					{
						cnt++;
						break;
					}
				}
				cout << cnt << '\n';
			}
		}
	}
	else
	{
		cout << "1" << '\n';
	}
	return 0;
}