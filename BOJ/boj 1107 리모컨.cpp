#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char> control;
string channel;
string start = "100";
int MIN = 10000000;
int m;

void dfs(string s, int cnt)
{
    if (s.length() >= 7)
    {
        return;
    }
    MIN = min(cnt + abs(stoi(s) - stoi(channel)), MIN);
    if (cnt == 0)
        s = "";
    for (int i = 0; i < control.size(); i++)
    {
        dfs(s + control[i], cnt + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++)
    {
        control.push_back(i + '0');
    }
    cin >> channel >> m;
    for (int i = 0; i < m; i++)
    {
        char a;
        cin >> a;
        control.erase(find(control.begin(), control.end(), a));
    }
    dfs(start, 0);
    cout << MIN << '\n';
    return 0;
}