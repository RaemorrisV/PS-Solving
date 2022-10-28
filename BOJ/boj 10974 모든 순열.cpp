#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ans;
void dfs(int start)
{
    ans.push_back(start);
    if (ans.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(ans.begin(), ans.end(), i) == ans.end())
        {
            dfs(i);
            ans.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
        ans.pop_back();
    }
}