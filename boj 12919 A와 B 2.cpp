#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
bool possible = false;
void dfs(string a)
{
    if (a.length() == s.length())
    {
        if (a == s)
        {
            possible = true;
            cout << possible << endl;
            exit(0);
        }
        return;
    }
    if (a[0] == 'B')
    {
        string temp = a;
        reverse(temp.begin(), temp.end());
        temp.erase(temp.begin() + (temp.length() - 1));
        dfs(temp);
    }
    if (a[a.length() - 1] == 'A')
    {
        string temp = a;
        temp.erase(temp.begin() + (temp.length() - 1));
        dfs(temp);
    }
}
int main()
{
    cin >> s >> t;
    dfs(t);
    cout << possible << endl;
    return 0;
}