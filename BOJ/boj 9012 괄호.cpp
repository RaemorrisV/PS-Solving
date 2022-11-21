#include <iostream>
#include <stack>
using namespace std;

int t;
string input;
bool flag;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        stack<char> s;
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            if (input[j] == '(')
            {
                s.push('(');
            }
            else if (input[j] == ')')
            {
                if (!s.empty())
                {
                    s.pop();
                }
                else
                {
                    flag = true;
                    break;
                }
            }
        }
        if (!s.empty() || flag)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
        flag = false;
    }
    return 0;
}