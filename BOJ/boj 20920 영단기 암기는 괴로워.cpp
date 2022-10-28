#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct info
{
    int cnt;
    int len;
};
unordered_map<string, info> str;
int n, m;
bool compare(pair<string, info> a, pair<string, info> b)
{
    if (a.second.cnt > b.second.cnt)
        return a.second.cnt > b.second.cnt;
    else if (a.second.cnt == b.second.cnt)
    {
        if (a.second.len > b.second.len)
            return a.second.len > b.second.len;
        else if (a.second.len == b.second.len)
        {
            return a.first < b.first;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        if (input.length() >= m)
        {
            if (str.find(input) == str.end())
            {
                str[input].cnt = 1;
                str[input].len = input.length();
            }
            else
            {
                str[input].cnt++; //갯수증가
            }
        }
    }
    vector<pair<string, info>> ans(str.begin(), str.end());
    sort(ans.begin(), ans.end(), compare);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << '\n';
    }
    return 0;
}