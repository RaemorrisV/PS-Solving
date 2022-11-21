#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> number;
long long dp[101][21];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    number.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> number[i];
    }
    dp[1][number[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (dp[i - 1][j] != 0)
            {
                if (j + number[i] <= 20) // 20 이하
                {
                    dp[i][j + number[i]] += dp[i - 1][j];
                }
                if (j - number[i] >= 0) // 0 이상
                {
                    dp[i][j - number[i]] += dp[i - 1][j];
                }
            }
        }
    }
    cout << dp[n - 1][number[n]] << '\n';
    return 0;
}