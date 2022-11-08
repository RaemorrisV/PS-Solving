#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
string one, two;
string ans = "";
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> one >> two;
    for (int i = 0; i < one.length() + 1; i++)
    {
        for (int j = 0; j < two.length() + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (one[i - 1] == two[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int x = one.length();
    int y = two.length();
    while (dp[x][y] != 0)
    {
        if (dp[x - 1][y] == dp[x][y])
        {
            x -= 1;
        }
        else if (dp[x][y - 1] == dp[x][y])
        {
            y -= 1;
        }
        else //둘 다 아닐 때
        {
            ans += one[x - 1];
            x -= 1;
            y -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << dp[one.length()][two.length()] << '\n';
    cout << ans << endl;
    return 0;
}