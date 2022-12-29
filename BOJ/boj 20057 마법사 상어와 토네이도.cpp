#include <iostream>
#include <vector>
using namespace std;

int n;
int field[500][500];
int dx[4] = {0, 1, 0, -1}; // 좌 하 우 상
int dy[4] = {-1, 0, 1, 0};
// 좌 하 우 상 맨 마지막이 a임
int t_dx[4][10] = {{-1, 1, -2, 2, -1, 1, -1, 1, 0, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0}, {1, 1, 0, 0, 0, 0, -1, -1, -2, -1}};
int t_dy[4][10] = {{1, 1, 0, 0, 0, 0, -1, -1, -2, -1}, {1, -1, -2, 2, -1, 1, -1, 1, 0, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0}};
int percent[9] = {1, 1, 2, 2, 7, 7, 10, 10, 5};
int r, c;
int sum = 0;
bool valide(int a, int b)
{
    if (a >= 1 && a <= n && b >= 1 && b <= n)
        return true;
    return false;
}
void simulation(int dir)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        int nx = r + t_dx[dir][i];
        int ny = c + t_dy[dir][i];
        if (!valide(nx, ny))
        {
            sum += (field[r][c] * percent[i]) / 100;
            total += (field[r][c] * percent[i]) / 100;
        }
        else
        {
            field[nx][ny] += (field[r][c] * percent[i]) / 100;
            total += (field[r][c] * percent[i]) / 100;
        }
    }
    int nx = r + t_dx[dir][9];
    int ny = c + t_dy[dir][9];
    if (!valide(nx, ny))
    {
        sum += (field[r][c] - total);
    }
    else
    {
        field[nx][ny] += (field[r][c] - total);
    }
    field[r][c] = 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> field[i][j];
        }
    }
    r = n / 2 + 1;
    c = r;
    int len = 1;
    bool flag = false;
    while (1)
    {
        // 좌 하
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (r == 1 && c == 1)
                {
                    flag = true;
                    break;
                }
                r += dx[i];
                c += dy[i];
                simulation(i);
            }
            if (flag)
                break;
        }
        if (flag)
            break;
        len++;
        // 우 상
        for (int i = 2; i < 4; i++)
        {
            for (int j = 0; j < len; j++)
            {
                r += dx[i];
                c += dy[i];
                simulation(i);
            }
        }
        len++;
    }
    cout << sum << '\n';
    return 0;
}