#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num;
int sum = 0;
int dp[100001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        num.push_back(in);
        dp[i + 1] = dp[i] + in;
    }
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[e] - dp[s - 1] << '\n';
    }
    return 0;
}