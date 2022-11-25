#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

double alpha[26];
string input;
int n;
stack<double> s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    cin >> input;
    for (int i = 0; i < n; i++)
    {
        double s;
        cin >> s;
        alpha[i] = s;
    }
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= 65 && input[i] <= 90)
        {

            s.push(alpha[input[i] - 'A']);
        }
        else
        {
            double op1 = s.top();
            s.pop();
            double op2 = s.top();
            s.pop();
            if (input[i] == '*')
            {
                s.push(op2 * op1);
            }
            else if (input[i] == '+')
            {
                s.push(op2 + op1);
            }
            else if (input[i] == '-')
            {
                s.push(op2 - op1);
            }
            else if (input[i] == '/')
            {
                s.push(op2 / op1);
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
    return 0;
}