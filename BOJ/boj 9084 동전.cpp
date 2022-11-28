#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
int dp[10001]; 
vector<int> cost;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            cost.push_back(input);
        }
        dp[0] = 1;
        cin >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = cost[i]; j <= m; j++)
            {
                dp[j] += dp[j - cost[i]];
            }
        }
        cout << dp[m] << '\n';
        fill(dp, dp + 10001, 0);
        cost.clear();
    }
    return 0;
}