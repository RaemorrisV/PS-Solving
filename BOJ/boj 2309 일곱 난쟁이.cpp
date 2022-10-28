#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(9);
vector<int> ans;
int sum = 0;
void dfs(int s)
{
    ans.push_back(s);
    sum += s;
    if (ans.size() == 7 && sum == 100)
    {
        for (int i = 0; i < 7; i++)
        {
            cout << ans[i] << "\n";
        }
        exit(0);
    }
    for (int i = 0; i < 9; i++)
    {
        if (find(ans.begin(), ans.end(), arr[i]) == ans.end())
        {
            dfs(arr[i]);
            ans.pop_back();
            sum -= arr[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 9; i++)
    {
        dfs(arr[i]);
        ans.pop_back();
        sum -= arr[i];
    }
    return 0;
}