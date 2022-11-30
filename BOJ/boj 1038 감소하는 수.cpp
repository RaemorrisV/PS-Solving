#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<long long> ans;
bool desc(string input)
{
    for (int i = 0; i < input.length() - 1; i++)
    {
        if (input[i] <= input[i + 1])return false;
    }
    return true;
}
void dfs(int len, string temp)
{
    if (!desc(temp))
    {
        return;
    }
    else
    {
        ans.push_back(stoll(temp));
    }
    if (temp.length() == 10)
    {
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        dfs(len + 1, temp + to_string(i));
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        dfs(1, to_string(i));
    }
    sort(ans.begin(), ans.end());
    if (n >= ans.size())
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << ans[n] << '\n';
    }
    return 0;
}