#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, ans;
int choice[7];
int count_score()
{
	//���� ���� 4���� ������
	for (int i = 1; i <= 6; i++)
	{
		if (choice[i] == 4)
		{
			return 50000 + i * 5000;
		}
	}
	//���� ���� 3���� ������
	for (int i = 1; i <= 6; i++)
	{
		if (choice[i] == 3)
		{
			return 10000 + i * 1000;
		}
	}
	//���� ���� 2���� �ν�
	for (int i = 1; i <= 6; i++)
	{
		if (choice[i] == 2)
		{
			for (int j = i + 1; j <= 6; j++)
			{
				// 2,000��+(2���� ���� ��)��500��+(�� �ٸ� 2���� ���� ��)��500
				if (choice[j] == 2)return 2000 + i * 500 + j * 500;
			}
			// 1,000��+(���� ��)��100
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