#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1002][1002];
string one, two, ans;
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
    cout << dp[one.length()][two.length()] << '\n';
    return 0;
}