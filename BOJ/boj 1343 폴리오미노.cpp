#include <iostream>
#include <string>

using namespace std;

string poly[2] = { "AAAA","BB" };
string input;
string ans = "";
int cnt;
bool flag;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		if (flag)break;
		if (input[i] == 'X')cnt++;
		if (input[i] == '.' || i == input.length() - 1)
		{
			if (cnt % 2 == 1)
			{
				ans = "-1";
				flag = true;
			}
			else
			{
				//AAAA老 版快
				for (int j = 0; j < (cnt / 4); j++)
				{
					ans += "AAAA";
				}
				//BB老 版快 贸府
				cnt -= (cnt / 4) * 4;
				for (int j = 0; j < cnt / 2; j++)
				{
					ans += "BB";
				}
				if(input[i] == '.')ans += ".";
				cnt = 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}