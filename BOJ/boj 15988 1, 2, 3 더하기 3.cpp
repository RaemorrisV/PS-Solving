#include <iostream>

using namespace std;

int n, t;
int dp[1000001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++)
    {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000009 + dp[i - 3] % 1000000009) % 1000000009;
    }
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}