#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001][3]; //오르막일 경우 내리막일 경우
int arr[100001];
int n;
int MAX = 1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i - 1] <= arr[i])
        {
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else
        {
            dp[i][1] = 1;
        }
        if (arr[i - 1] >= arr[i])
        {
            dp[i][2] = dp[i - 1][2] + 1;
        }
        else
        {
            dp[i][2] = 1;
        }
        MAX = max(MAX, dp[i][1]);
        MAX = max(MAX, dp[i][2]);
    }
    cout << MAX << '\n';
    return 0;
}