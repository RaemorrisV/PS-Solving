#include <iostream>

using namespace std;

long long n, choice, k;
bool visited[21];
long long fac[21];
void factorial()
{
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> choice;
	factorial();
	if (choice == 1)  //수열 출력
	{
		cin >> k;
		for (int i = 1; i <= n; i++)
		{
			int digit = (k - 1) / fac[n - i]; //6까지는 0 이 나와줘야함..
			for (int j = 1; j <= n; j++)
			{
				if (visited[j] == false) //젤 작은 수 부터
				{
					bool flag = false;
					int  cnt = 0;
					for (int t = j; t <= n; t++)
					{
						if (visited[t] == false)cnt++;
						if (cnt - 1 == digit)
						{
							visited[t] = true;
							cout << t << " ";
							flag = true;
							break;
						}
					}
					if (flag)break;
				}
			}
			//min_digit=가장 작은값을 나타냄
			k -= digit * fac[n - i];
		}
		cout << '\n';
	}
	else  //몇 번쨰 수열인지 알아내는 부분 
	{
		long long order = 0;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			visited[input] = true;
			int cnt = 0;
			for (int j = 1; j < input; j++)
			{
				if (visited[j] == false)cnt++;
			}
			order += cnt * fac[n - i - 1];
		}
		cout << order + 1 << '\n';
	}
	return 0;
}