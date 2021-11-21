#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#define MAX 987654321
using namespace std;
int n, m;
int dp[31][40001];
int weight[31];
int marble[8];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];//추의 무게
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> marble[i];//구슬의 무게
    }
    dp[1][weight[1]] = 1;//초기화를 해줌
    for (int i = 2; i <= n; i++)//dp를 채워 나가면 됨
    {
        for (int j = 1; j <= 40000; j++)
        {
            if (dp[i - 1][j] == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (j - weight[i] == 0)
                {
                    dp[i][j] = 1;
                }
                else if (dp[i - 1][abs(j - weight[i])] == 1 || dp[i - 1][j + weight[i]] == 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }

        }
    }

    /*
     for (int i = 1; i <= n; i++)//dp를 채워 나가면 됨
    {
        for (int j = 1; j <= 15; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = 1; i <= m; i++)
    {
        if (dp[n][marble[i]] == 1)
        {
            cout << "Y" << " ";
        }
        else
        {
            cout << "N" << " ";
        }
    }
    cout << '\n';

    return 0;
}