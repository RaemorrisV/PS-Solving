#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> b;
long long ans = 0;
bool visited[10000];
void dfs(int sum, int len)
{
    if (len == 2)
    {
        int idx = lower_bound(arr.begin() + b[1] + 1, arr.end(), -sum) - arr.begin();
        int idx2 = upper_bound(arr.begin() + b[1] + 1, arr.end(), -sum) - arr.begin();
        ans += idx2 - idx;
        return;
    }
    for (int i = b[0]; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            b.push_back(i);
            dfs(sum + arr[i], len + 1);
            b.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr.push_back(in);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        b.push_back(i);
        dfs(arr[i], 1);
        visited[i] = false;
        b.pop_back();
    }
    cout << ans << '\n';
    return 0;
}