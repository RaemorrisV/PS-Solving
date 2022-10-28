#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> arr;
vector<int> ans;
void dfs(int s)
{
    ans.push_back(s);
    if (ans.size() == m)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= s)
        {
            dfs(arr[i]);
            ans.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(arr[i]);
        ans.pop_back();
    }
    return 0;
}