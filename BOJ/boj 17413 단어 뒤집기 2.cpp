#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
bool flag;
stack<char> st;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
        {
            flag = true;
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            cout << s[i];
            continue;
        }
        else if (s[i] == '>')
        {
            flag = false;
            cout << s[i];
            continue;
        }
        if (flag)
        {
            cout << s[i];
        }
        else
        {
            if (s[i] == ' ')
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << s[i];
            }
            else if (i == s.length() - 1)
            {
                st.push(s[i]);
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    return 0;
}