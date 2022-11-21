#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;
stack<char> s;
int ans = 0;
int check;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>input;
    for (int i = 0; i < input.length(); i++)
    {
        if (i <= input.length() - 2 && input[i] == '(' && input[i + 1] == ')') //레이저일 경우
        {
            ans += s.size();
            i+=1;
        }
        else if (input[i] == '(')
        {
            s.push('(');
        }
        else if (input[i] == ')')
        {
            ans++;
            s.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}