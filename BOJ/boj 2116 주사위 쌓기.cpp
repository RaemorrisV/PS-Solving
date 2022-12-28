#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int MAX = 0;
int sum = 0;
int ans = 0;
vector<vector<int>> dice(10001);
int n_value[6];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int s;
            cin >> s;
            dice[i].push_back(s);
        }
    }
    n_value[0] = 5;
    n_value[1] = 3;
    n_value[2] = 4;
    n_value[3] = 1;
    n_value[4] = 2;
    n_value[5] = 0;
    for (int i = 0; i < 6; i++)
    {
        int top = dice[1][i];
        int bottom = dice[1][n_value[i]];
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            MAX = 0;
            for (int k = 0; k < 6; k++)
            {
                if (bottom != dice[j][k] && top != dice[j][k])
                {
                    MAX = max(dice[j][k], MAX);
                }
            }
            //cout << j << " " << bottom << " " << top << " " << MAX << endl;
            if (j < n)
            {
                for (int z = 0; z < 6; z++)
                {
                    if (top == dice[j + 1][z]) // 밑
                    {
                        top = dice[j + 1][n_value[z]]; // 다음 top값을 나타내는 부분 임
                        bottom = dice[j + 1][z];
                        break;
                        // cout <<"아래"<< top << endl;
                    }
                }
            }
            sum += MAX;
        }
        ans = max(sum, ans);
    }
    cout << ans << '\n';
    return 0;
}