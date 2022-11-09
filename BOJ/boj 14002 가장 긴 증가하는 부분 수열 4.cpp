#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;
vector<int> ans;
int dp[1000];
int MAX = 1;
int idx;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        MAX = max(dp[i], MAX);
        if (MAX == dp[i])
        {
            idx = i;
        }
    }
    int cnt = MAX;
    for (int j = idx; j >= 0; j--)
    {
        if (dp[j] == cnt)
        {
            ans.push_back(arr[j]);
            cnt--;
        }
    }
    cout << MAX << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}