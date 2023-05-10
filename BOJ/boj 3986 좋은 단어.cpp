#include <iostream>
#include <stack>

using namespace std;

int n, ans;
string word[101];
stack<char>st;
void init()
{
	while (!st.empty())
	{
		st.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> word[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < word[i].length(); j++)
		{
			if (st.empty())st.push(word[i][j]);
			else
			{
				if (st.top() == word[i][j])st.pop();
				else if (st.top() != word[i][j])st.push(word[i][j]);
			}
		}
		if (st.empty())ans++;
		init();
	}
	cout << ans << '\n';
	return 0;
}