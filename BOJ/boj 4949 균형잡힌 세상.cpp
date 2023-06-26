#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (1)
	{
		string input;
		getline(cin, input);
		if (input == ".")break;
		stack<char>st;
		bool flag = false;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '(' || input[i] == '[')
			{
				st.push(input[i]);
			}
			else if (input[i] == ')' || input[i] == ']')
			{
				if (st.empty())
				{
					flag = true;
					break;
				}
				if (input[i] == ')' && st.top() == '(')st.pop();
				else if (input[i] == ']' && st.top() == '[')st.pop();
				else flag = true;
			}
		}
		if (st.empty() && flag==false)cout << "yes" << '\n';
		else
		{
			cout << "no" << '\n';
		}
	}
	return 0;
}