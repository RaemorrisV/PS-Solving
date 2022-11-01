#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n, s;
int sum = 0;
int ans = 0;
bool visited[20];
void dfs(int l)
{
    sum += arr[l];
    if (sum == s)
    {
        ans++;
    }
    for (int i = l; i < n; i++)
    {
        if (visited[i] == false && arr[l] <= arr[i])
        {
            visited[i] = true;
            dfs(i);
            sum -= arr[i];
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(i);
        sum -= arr[i];
    }
    cout << ans << '\n';
    return 0;
}
