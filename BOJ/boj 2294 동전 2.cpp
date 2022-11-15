#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> cost;
int dp[10001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int input;
        cin >> input;
        cost.push_back(input);
        if (input <= 10000)
        {
            dp[input] = 1;
        }
    }
    sort(cost.begin(), cost.end());
    cost.erase(unique(cost.begin(), cost.end()), cost.end());
    for (int i = 1; i <= k; i++)
    {
        if (dp[i] == 0)
        {
            dp[i] = 100001;
        }
        for (int j = 0; j < cost.size(); j++)
        {
            if (cost[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - cost[j]] + dp[cost[j]]);
            }
        }
    }
    if (dp[k] != 100001)
    {
        cout << dp[k] << '\n';
    }
    else
    {
        cout << "-1" << '\n';
    }
    return 0;
}