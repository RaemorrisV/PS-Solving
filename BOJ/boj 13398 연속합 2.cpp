#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[100001][2];
int MAX = -110000000;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    arr.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i + 1];
    }
    dp[1][0] = arr[1];
    dp[1][1] = 0;
    MAX=arr[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        MAX = max(max(dp[i][0], dp[i][1]), MAX);
    }
    cout << MAX << '\n';
    return 0;
}