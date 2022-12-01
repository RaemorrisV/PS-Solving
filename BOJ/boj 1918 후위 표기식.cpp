#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

stack<char> oper;
string infix;
unordered_map<char, int> priority;
vector<char> ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['('] = 0;
    priority[')'] = 0;
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] >= 65 && infix[i] <= 90)
        {
            ans.push_back(infix[i]);
        }
        else
        {
            if (infix[i] == '(')
            {
                oper.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (oper.top() != '(')
                {
                    ans.push_back(oper.top());
                    oper.pop();
                }
                oper.pop();
            }
            else
            {
                while (!oper.empty() && priority[oper.top()] >= priority[infix[i]])
                {
                    ans.push_back(oper.top());
                    oper.pop();
                }
                oper.push(infix[i]);
            }
        }
    }
    while (!oper.empty())
    {
        ans.push_back(oper.top());
        oper.pop();
    }
    for (auto it : ans)
    {
        cout << it;
    }
    cout << '\n';
    return 0;
}