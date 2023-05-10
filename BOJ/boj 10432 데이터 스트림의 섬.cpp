#include <iostream>
#include <stack>

using namespace std;

int tc, MIN, ans, g;
int arr[12];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		ans = 0;
		cin >> g;
		for (int i = 0; i < 12; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i < 12; i++)
		{
			MIN = arr[i-1];
			for (int j = i; j < 12; j++)
			{
				if (arr[j] < MIN)
				{
					ans++;
					break;
				}
				else if (arr[j] == MIN)break;
			}
		}
		cout << t << " " << ans << "\n";
	}
	return 0;
}