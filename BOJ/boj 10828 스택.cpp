#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int n, para;
string input;
stack<int> s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input == "push")
        {
            cin >> para;
            s.push(para);
        }
        else if (input == "pop")
        {
            if (s.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (input == "size")
        {
            cout << s.size() << '\n';
        }
        else if (input == "empty")
        {
            if (s.empty())
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
        else if (input == "top")
        {
            if (s.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                cout << s.top() << '\n';
            }
        }
    }

    return 0;
}
