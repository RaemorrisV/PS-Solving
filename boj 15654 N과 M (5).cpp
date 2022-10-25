#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, input;
vector<int> arr;
vector<int> ans;
void dfs(int in)
{
    ans.push_back(in);
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
        if (find(ans.begin(), ans.end(), arr[i]) == ans.end())
        {
            dfs(arr[i]);
            ans.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        dfs(arr[i]);
        ans.pop_back();
    }
    return 0;
}