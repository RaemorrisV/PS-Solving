#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> gear(1001); // N극 0 S극 1 //1 시계방향 -1 반시계 방향
int t, k, s, e;
vector<int> info(1001);
int ans = 0;
void rotate_info(int num, int dir)
{
    info[num] = dir;
    for (int i = num; i <= t; i++)
    {
        if (i + 1 == t + 1)break;
        if (gear[i][2] != gear[i + 1][6])
        {
            info[i + 1] = -info[i];
        }
    }
    for (int i = num; i >= 1; i--)
    {
        if (i - 1 == 0)break;
        if (gear[i][6] != gear[i - 1][2])
        {
            info[i - 1] = -info[i];
        }
    }
}
void rotate()
{
    for (int i = 1; i <= t; i++)
    {
        if (info[i] == -1) //반시계라면
        {
            int temp = gear[i][0];
            for (int j = 0; j < 7; j++)
            {
                gear[i][j] = gear[i][j+1];
            }
            gear[i][7] = temp;
        }
        else if (info[i] == 1) //시계방향이라면
        {
            int temp = gear[i][7];
            for (int j = 7; j > 0; j--)
            {
                gear[i][j] = gear[i][j-1];
            }
            gear[i][0] = temp;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            gear[i].push_back(input[j] - '0');
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> s >> e;
        rotate_info(s, e);
        rotate();
        fill(info.begin(), info.end(), 0);
    }
    for (int i = 1; i <= t; i++)
    {
        if (gear[i][0] == 1)
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}