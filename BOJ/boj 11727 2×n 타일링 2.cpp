#include <iostream>

using namespace std;

int dp[1001];
int n;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }
    cout << dp[n] % 10007 << '\n';
    return 0;
}