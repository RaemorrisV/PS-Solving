#include <iostream>

using namespace std;
int n;
int dp[1001]; //1�� ����̰� �̱�ٰ� ���� 0�� �����̰� �̱�ٰ� �����غ���
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	dp[1] = 1;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= n; i++)
	{
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)//�����̰� �̱�� ����� �ϳ��� ������
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 0;
		}
	}
	if (dp[n] == 1)
	{
		cout << "SK" << '\n';
	}
	else
	{
		cout << "CY" << '\n';
	}
	return 0;
}