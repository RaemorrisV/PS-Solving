#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, para;
string command;
queue<int> q;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> para;
            q.push(para);
        }
        else if (command == "pop")
        {
            if (!q.empty())
            {
                int out = q.front();
                cout << out << '\n';
                q.pop();
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (command == "size")
        {
            cout << q.size() << '\n';
        }
        else if (command == "empty")
        {
            if (!q.empty())
            {
                cout << "0" << '\n';
            }
            else
            {
                cout << "1" << '\n';
            }
        }
        else if (command == "front")
        {
            if (!q.empty())
            {
                int out = q.front();
                cout << out << '\n';
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
        else if (command == "back")
        {
            if (!q.empty())
            {
                int out = q.back();
                cout << out << '\n';
            }
            else
            {
                cout << "-1" << '\n';
            }
        }
    }
}