#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
int idx;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> t;
    while (s.length() != t.length())
    {
        idx = t.length() - 1;
        if (t[idx] == 'A')
        {
            t.erase(idx, 1);
        }
        else // b라면?
        {
            t.erase(idx, 1);
            reverse(t.begin(), t.end());
        }
    }
    if (s == t)
        cout << "1" << '\n';
    else
        cout << "0" << '\n';
    return 0;
}