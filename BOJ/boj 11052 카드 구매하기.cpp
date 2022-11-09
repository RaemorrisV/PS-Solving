#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> card;
int dp[1001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    card.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = card[i];
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + dp[i - j - 1]);
        }
    }
    cout << dp[n - 1] << '\n';
    return 0;
}