#include <iostream>

using namespace std;

int n;
char map[2188][2188];
void dfs(int s, int r1, int c1)
{
    if (s == 3)
    {
        for (int i = r1; i < r1 + 3; i++)
        {
            for (int j = c1; j < c1 + 3; j++)
            {
                if (i == r1 + 1 && j == c1 + 1)
                {
                    map[i][j] = ' ';
                }
                else
                {
                    map[i][j] = '*';
                }
            }
        }
        return;
    }
    for (int i = s / 3 + r1; i <=2 * s / 3 + r1; i++)
    {
        for (int j = s / 3 + c1; j <= 2 * s / 3 + c1; j++)
        {
            map[i][j] = ' ';
        }
    }
    dfs(s / 3, r1, c1);         //첫번째
    dfs(s / 3, r1, c1 + s / 3); //두번째
    dfs(s / 3, r1, c1 + 2 * s / 3);
    dfs(s / 3, r1 + s / 3, c1);
    dfs(s / 3, r1 + s / 3, c1 + 2 * s / 3);
    dfs(s / 3, r1 + 2 * s / 3, c1);
    dfs(s / 3, r1 + 2 * s / 3, c1 + s / 3);
    dfs(s / 3, r1 + 2 * s / 3, c1 + 2 * s / 3);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    dfs(n, 1, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}