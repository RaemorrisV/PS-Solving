#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
string fire;
int fire_len;
vector<char>ans;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str >> fire;
	fire_len = fire.length();
	for (int i = 0; i < str.length(); i++)
	{
		ans.push_back(str[i]);
		if (ans.back() == fire[fire_len - 1])
		{
			if (ans.size() >= fire_len)
			{
				string tmp = "";
				for (int j = fire_len; j > 0; j--)
				{

					tmp += ans[ans.size() - j];
					//cout << tmp << endl;
					if (tmp == fire)
					{
						//cout << tmp << endl;
						for (int z = 0; z < fire_len; z++)
						{
							ans.pop_back();
						}
					}
				}
			}
		}
	}
	if (ans.size() == 0)
	{
		cout << "FRULA" << '\n';
	}
	else
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i];
		}
	}
	return 0;
}