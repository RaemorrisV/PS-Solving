#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, k;
int snail[1000][1000];
int step = 1;
int r, c;
pair<int, int> ans;
void make_snail(int start)
{
    snail[start][start] = 1;
    r = start;
    c = start;
    if (snail[r][c] == k)
    {
        ans = {r, c};
    }
    while (1)
    {
        if (snail[r][c] == pow(n, 2))
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << snail[i][j] << " ";
                }
                cout << '\n';
            }
            cout << ans.first << " " << ans.second << '\n';
            break;
        }
        if (snail[r][c] == pow(step, 2))
        {
            snail[r - 1][c] = snail[r][c] + 1;
            r -= 1;
            step += 2;
            if (snail[r][c] == k)
            {
                ans = {r, c};
            }
            for (int i = 1; i <= step - 2; i++)
            {
                c += 1;
                snail[r][c] = snail[r][c - 1] + 1;
                if (snail[r][c] == k)
                {
                    ans = {r, c};
                }
            }
        }
        for (int i = 1; i < step; i++) // 왼쪽을 담당
        {
            r += 1;
            snail[r][c] = snail[r - 1][c] + 1;
            if (snail[r][c] == k)
            {
                ans = {r, c};
            }
        }
        for (int i = 1; i < step; i++) // 아래를 담당
        {
            c -= 1;
            snail[r][c] = snail[r][c + 1] + 1;
            if (snail[r][c] == k)
            {
                ans = {r, c};
            }
        }
        for (int i = 1; i < step; i++) // 오른쪽을 담당
        {
            r -= 1;
            snail[r][c] = snail[r + 1][c] + 1;
            if (snail[r][c] == k)
            {
                ans = {r, c};
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    make_snail((1 + n) / 2);
    return 0;
}