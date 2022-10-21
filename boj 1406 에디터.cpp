#include <iostream>
#include <list>
#include <string>
using namespace std;
list<char> str;
string input;
int m;
char command;
char p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        str.push_back(input[i]);
    }
    cin >> m;
    auto cursor = str.end();
    for (int i = 0; i < m; i++)
    {
        cin >> command;
        if (command == 'L')
        {
            if (cursor != str.begin())
            {
                cursor--;
            }
        }
        else if (command == 'D')
        {
            if (cursor != str.end())
            {
                cursor++;
            }
        }
        else if (command == 'B')
        {
            if (cursor != str.begin())
            {
                cursor = str.erase(--cursor);
            }
        }
        else if (command == 'P')
        {
            cin >> p;
            str.insert(cursor, p);
        }
    }
    for (auto it = str.begin(); it != str.end(); it++)
    {
        cout << *it;
    }
    cout << '\n';
    return 0;
}