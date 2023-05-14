#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ans;
int choice[7];
int count_score()
{
	//같은 눈이 4개가 나오면
	for (int i = 1; i <= 6; i++)
	{
		if (choice[i] == 4)
		{
			return 50000 + i * 5000;
		}
	}
	//같은 눈이 3개만 나오면
	for (int i = 1; i <= 6; i++)
	{
		if (choice[i] == 3)
		{
			return 10000 + i * 1000;
		}
	}
	//같은 눈이 2개씩 두쌍
	for (int i = 1; i <= 6; i++)
	{
		if (choice[i] == 2)
		{
			for (int j = i + 1; j <= 6; j++)
			{
				// 2,000원+(2개가 나온 눈)×500원+(또 다른 2개가 나온 눈)×500
				if (choice[j] == 2)return 2000 + i * 500 + j * 500;
			}
			// 1,000원+(같은 눈)×100
			return 1000 + i * 100;
		}
	}
	int late = 0;
	for (int i = 1; i <= 6; i++)
	{
		if (choice[i] == 1)late = i;
	}
	return late * 100;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int input;
			cin >> input;
			choice[input]++;
		}
		ans = max(ans, count_score());
		memset(choice, 0, sizeof(choice));
	}
	cout << ans << '\n';
	return 0;
}