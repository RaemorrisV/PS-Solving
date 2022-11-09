#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int dp[1000];
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
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j] + dp[i - j - 1]);
        }
    }
    cout << dp[n - 1] << "\n";
    return 0;
}