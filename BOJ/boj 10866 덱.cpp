#include <iostream>
#include <deque>
#include <string>

using namespace std;
int n, para;
string command;
deque<int> d;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push_front")
        {
            cin >> para;
            d.push_front(para);
        }
        else if (command == "push_back")
        {
            cin >> para;
            d.push_back(para);
        }
        else if (command == "pop_front")
        {
            if (d.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                int out = d.front();
                cout << out << "\n";
                d.pop_front();
            }
        }
        else if (command == "pop_back")
        {
            if (d.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                int out = d.back();
                cout << out << "\n";
                d.pop_back();
            }
        }
        else if (command == "size")
        {
            cout << d.size() << "\n";
        }
        else if (command == "empty")
        {
            if (d.empty())
            {
                cout << "1" << '\n';
            }
            else
            {
                cout << "0" << '\n';
            }
        }
        else if (command == "front")
        {
            if (d.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                int out = d.front();
                cout << out << "\n";
            }
        }
        else if (command == "back")
        {
            if (d.empty())
            {
                cout << "-1" << '\n';
            }
            else
            {
                int out = d.back();
                cout << out << "\n";
            }
        }
    }
    return 0;
}