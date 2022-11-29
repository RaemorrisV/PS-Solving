#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int MAX = 0;
int ans = 0;
int dp[1500001];
vector<pair<int, int>> schedule;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ti, pi;
        cin >> ti >> pi;
        schedule.push_back({ti, pi});
    }
    for (int i = 0; i < n; i++)
    {
        MAX = max(dp[i], MAX);
        if (i + schedule[i].first <= n)
        {
            dp[i + schedule[i].first] = max(MAX + schedule[i].second, dp[i + schedule[i].first]);
            ans = max(ans, dp[i + schedule[i].first]);
        }
    }
    cout << ans << '\n';
    return 0;
}