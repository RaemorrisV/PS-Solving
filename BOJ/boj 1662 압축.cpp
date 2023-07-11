#include <iostream>
#include <stack>

using namespace std;

string s;
bool visited[50];
int ans = 0;
stack<int>st;
int dfs(int start, int end)
{
	int count = 0;
	for (int i = start + 1; i < end; i++)
	{
		if (s[i] == '(' && visited[i] == false)
		{
			st.push(i);
			visited[i] = true;
			int top = st.top();
			count += (s[top - 1] - '0') * dfs(top, s.length());
			count--;
		}
		else if (s[i] == ')'&& visited[i]==false)
		{
			visited[i] = true;
			st.pop();
			return count;
		}
		else if(!visited[i])
		{
			visited[i] = true;
			count++;
		}
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' && visited[i] == false)
		{
			visited[i] = true;
			st.push(i);
			int top = st.top();
			count += (s[top - 1] - '0') * dfs(top, s.length());
			count--;
		}
		else if (s[i] == ')' && visited[i]==false)
		{
			visited[i] = true;
			st.pop();
		}
		else if (!visited[i])
		{
			visited[i] = true;
			count++;
		}
	}
	cout << count << '\n';
	return 0;
}