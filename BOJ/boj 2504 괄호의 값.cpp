#include <iostream>
#include <stack>
#include <string>

using namespace std;

string in;
stack<char> st;
int sum = 0;
string par = "";
int dfs(string temp)
{
    stack<char> stac;
    string next = "";
    int total = 0;
    if (temp.length() == 2)
    {
        return 1;
    }
    for (int i = 1; i <= temp.size() - 2; i++)
    {
        next += temp[i];
        if (temp[i] == '[' || temp[i] == '(')
        {
            stac.push(temp[i]);
        }
        else if (temp[i] == ']')
        {
            if (stac.top() == '[')
            {
                stac.pop();
            }
        }
        else if (temp[i] == ')')
        {
            if (stac.top() == '(')
            {
                stac.pop();
            }
        }
        if (stac.empty())
        {
            if (next[0] == '(')
            {
                total += 2 * dfs(next);
                next = "";
            }
            else
            {
                total += 3 * dfs(next);
                next = "";
            }
        }
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> in;
    for (int i = 0; i < in.length(); i++)
    {
        par += in[i];
        if (in[i] == '[' || in[i] == '(')
        {
            st.push(in[i]);
        }
        else if (in[i] == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                sum = 0;
                break;
            }
            if (st.top() == '[')
            {
                st.pop();
            }
        }
        else if (in[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                sum = 0;
                break;
            }
            if (st.top() == '(')
            {
                st.pop();
            }
        }
        if (st.empty())
        {
            if (par[0] == '(')
            {
                sum += 2 * dfs(par);
                par = "";
            }
            else
            {
                sum += 3 * dfs(par);
                par = "";
            }
        }
    }
    if (st.empty())
    {
        cout << sum << '\n';
    }
    else // 올바른 괄호가 아님
    {
        cout << "0" << '\n';
    }
    return 0;
}