#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string n;
bool possible[8][10];
int ans = -1;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n.length(); i++)
	{
		for (int j = 1; j <= n.length(); j++)
		{
			if (n[i - 1] == '6' || n[i - 1] == '9')//서로 바꿔서 사용할수 있음
			{
				if (possible[j][6] == false)
				{
					possible[j][6] = true;
					ans = max(ans, j);
					break;
				}
				else if (possible[j][9] == false)
				{
					possible[j][9] = true;
					ans = max(ans, j);
					break;
				}
			}

			else
			{
				if (possible[j][n[i - 1] - '0'] == false)
				{
					possible[j][n[i - 1] - '0'] = true;
					ans = max(ans, j);
					break;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}