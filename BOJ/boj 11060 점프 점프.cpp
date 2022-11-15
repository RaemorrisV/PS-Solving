#include <iostream>
#include <algorithm>
using namespace std;

int n;
int maze[1001];
int dp[1001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> maze[i];
        dp[i] = 1001;
    }
    dp[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= i + maze[i]; j++)
        {
            if (j <= n)
            {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
    }
    if (dp[n] == 1001)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << dp[n] << "\n";
    }
    return 0;
}