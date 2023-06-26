
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int t;
string password;
stack<char>st;
stack<char>behind;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 0; tc < t; tc++)
	{
		cin >> password;
		for (int i = 0; i < password.length(); i++)
		{
			if (password[i] == '-')
			{
				if (st.empty())continue;
				st.pop();
			}
			else if (password[i] == '<')
			{
				if (st.size() != 0)
				{
					behind.push(st.top());
					st.pop();
				}
			}
			else if (password[i] == '>')
			{
				if (behind.size() != 0)
				{
					st.push(behind.top());
					behind.pop();
				}
			}
			else
			{
				st.push(password[i]);
			}
		}
		string ans = "";
		while (!behind.empty())
		{
			st.push(behind.top());
			behind.pop();
		}
		while (!st.empty())
		{
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}