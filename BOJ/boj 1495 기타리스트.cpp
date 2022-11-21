#include <iostream>
#include <vector>

using namespace std;

int n, s, m;
vector<int> v;
int dp[51][1001];
bool flag;
int ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> s >> m;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    dp[0][s] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i - 1][j] == 1)
            {
                if (j + v[i] <= m)
                {
                    flag = true;
                    dp[i][j + v[i]] = 1;
                }
                if (j - v[i] >= 0)
                {
                    flag = true;
                    dp[i][j - v[i]] = 1;
                }
            }
        }
        if (flag == false)
        {
            cout << "-1" << '\n';
            exit(0);
        }
        flag = false;
    }
    for (int j = 0; j <= m; j++)
    {
        if (dp[n][j] == 1)
        {
            ans = j;
        }
    }
    cout << ans << '\n';
    return 0;
}